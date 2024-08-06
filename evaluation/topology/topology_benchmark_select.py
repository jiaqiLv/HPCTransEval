import os
import json
import random
import shutil

def topology_benchmark(json_file_path, source_folder, output_folder, num_files=40):
    # 读取JSON文件
    with open(json_file_path, 'r') as f:
        operators = json.load(f)
    
    # 随机选择40个算子
    selected_ops = random.sample(operators, num_files)

    # 创建输出文件夹
    os.makedirs(output_folder, exist_ok=True)

    for op in selected_ops:
        # 提取算子信息
        op_name = op['op_name']
        op_args = op['op_args']
        input_shape = op['input_shape']


        file_name = f"{op_name}_{op_args}_{input_shape}"

        # 遍历源文件夹中的子文件夹
        for subfolder in ['c', 'cuda', 'device_module', 'host_module', 'ir']:
            source_subfolder = os.path.join(source_folder, subfolder)
            if os.path.exists(source_subfolder):
                for src_file in os.listdir(source_subfolder):
                    if src_file.startswith(file_name):
                        # 构造源文件路径
                        source_file_path = os.path.join(source_subfolder, src_file)
                        
                        # 构造目标文件路径
                        target_file_path = os.path.join(f'{output_folder}/{subfolder}', src_file)
                        os.makedirs(os.path.dirname(target_file_path), exist_ok=True)
                        
                        # 复制文件
                        shutil.copy2(source_file_path, target_file_path)

    with open(f'{output_folder}/topology.json', 'w') as f:
            json.dump(selected_ops, f, indent=4)
if __name__ == '__main__':
    source_folder   = "/code/LLM4HPCTransCompile/data/topology" 
    json_file_path = "/code/LLM4HPCTransCompile/data/topology/topology.json"
    output_folder = "/code/LLM4HPCTransCompile/benchmark/topology"
    topology_benchmark(json_file_path, source_folder, output_folder)