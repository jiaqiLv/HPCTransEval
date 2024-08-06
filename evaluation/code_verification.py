import os
import tvm
import numpy as np
import tvm.testing as testing
from tvm.runtime import load_module
from os.path import join,exists
import json
import logging
import time
from args import args
from tqdm import tqdm
import codebleu

logging.basicConfig(
    filename=f'./metric/results/result_{args.model}_{args.op_type}.log',
    level=logging.INFO,
    format='%(asctime)s %(levelname)s: %(message)s',
    datefmt='%Y-%m-%d %H:%M:%S'
)

def cal_codebleu(prediction,reference):
    result = codebleu.calc_codebleu([reference],[prediction],lang='c',weights=(0.25,0.25,0.25,0.25),tokenizer=None)
    return result
    
def compile_by_tvm(host_module, op, c_code):
    dev_module = host_module.imported_modules[0]
    dev_module.set_source(c_code)
    dev_module.compile_source()
    np.random.seed(42)
    dev = tvm.device(target.kind.name, 0)
    input_list = []
    output_list = []
    for _input_shape in op['input_shape']:
        input_list.append(np.random.random(tuple(_input_shape)).astype("float32"))
    for _output_shape in op['output_shape']:
        output_list.append(np.zeros(tuple(_output_shape)).astype("float32"))
    input_tvm_list = []
    output_tvm_list = []
    for _input in input_list:
        input_tvm_list.append(tvm.nd.array(_input,dev))
    for _output in output_list:
        output_tvm_list.append(tvm.nd.array(_output,dev))
    param_list = []
    param_list.extend(input_tvm_list)
    param_list.extend(output_tvm_list)
    return param_list, output_tvm_list

def exec_by_tvm(host_module, param_list):
    host_module(*param_list)

if __name__ == '__main__':
    save_path = 'DATA_PATH'
    json_name = 'JSON_TO_LOAD'

    target = tvm.target.Target(target="c", host="llvm")
    if not os.path.exists(save_path):
        raise Exception(f"{save_path} not found")
    
    with open(join(save_path,json_name),'r') as file:
        op_list = json.load(file)

    # Correctness Test
    for round, op in enumerate(op_list):
        # Prevent program interruption, using single sample test
        file_name = '{}_{}_{}'.format(op['op_name'],op['op_args'],op['input_shape'])
        if args.op_name != op['op_name']:
                continue

        host_module = load_module(join(save_path,'host_module',file_name),'ll')
        device_module = load_module(join(save_path,'device_module',file_name),'c')
        host_module.import_module(device_module)

        # the c_code need to by verification
        c_code = op['c_code']
        c_code_generated = op[f'{args.model}_c']

        code_bleu = cal_codebleu(c_code_generated,c_code)
        with open(f'CODEBLEU_RESULT_SAVE_PATH','a+') as file:
            json.dump({file_name:code_bleu},file)

        # Separation of compilation and execution
        param_list, output_tvm_list = compile_by_tvm(host_module, op, c_code)
        exec_by_tvm(host_module, param_list)
        param_list_generated, output_tvm_list_generated = compile_by_tvm(host_module, op, c_code_generated)
        exec_by_tvm(host_module, param_list_generated)

        logging.info(f'{file_name} COMPILE PASS')
        try:
            assert len(output_tvm_list) == len(output_tvm_list_generated)
            for i in range(len(output_tvm_list)):
                testing.assert_allclose(output_tvm_list[i].numpy(), output_tvm_list_generated[i].numpy())
        except Exception as e:
            print(f"Exception on round {round+1}: {e}")
            continue
        logging.info(f'{file_name} EXEC PASS')
        
        N_warmup = 500
        N_execute = 500
        # Performance test

        param_list, output_tvm_list = compile_by_tvm(host_module, op, c_code)
        # warm up kernel
        for i in range(N_warmup):
            exec_by_tvm(host_module, param_list)
        c_code_start_time = time.time()
        for i in tqdm(range(N_execute)):
            exec_by_tvm(host_module, param_list)
        c_code_end_time = time.time()
        c_code_total_time = c_code_end_time - c_code_start_time

        param_list_generated, output_tvm_list_generated = compile_by_tvm(host_module, op, c_code_generated)
        # warm up kernel
        for i in range(N_warmup):
            exec_by_tvm(host_module, param_list_generated)
        gen_c_code_start_time = time.time()
        for i in tqdm(range(N_execute)):
            exec_by_tvm(host_module, param_list_generated)
        gen_c_code_end_time = time.time()
        gen_c_code_total_time = gen_c_code_end_time - gen_c_code_start_time

        with open(f'GT_PERFORMANCE_PATH','a+') as file:
            file.write(f'{file_name}: {c_code_total_time/N_execute}\n')
        with open(f'GENERATED_PERFORMANCE_PATH','a+') as file:
            file.write(f'{file_name}: {gen_c_code_total_time/N_execute}\n')