import os
import json

def generate_prompt_files(json_folder, prompt_template):

    categories = ['Elementwise', 'Reduction', 'Layout Transform', 'Logic Intensive', 'Compute Intensive']

    for category in categories:
        json_file_path = f'{json_folder}/{category}/{category}.json'
        output_folder = f'{json_folder}/{category}/prompt'
        os.makedirs(output_folder, exist_ok=True)
        
        # 读取每个类别的JSON文件
        if os.path.exists(json_file_path):
            with open(json_file_path, 'r') as f:
                operators = json.load(f)

            # 遍历算子列表，生成prompt文件
            for op in operators:
                # 提取算子信息
                op_name = op['op_name']
                op_args = op['op_args']
                input_shape = op['input_shape']
                output_shape = op['output_shape']
                cuda_code = op['cuda_code']

                # 填充模板
                prompt_content = prompt_template.format(
                    op_name=op_name,
                    op_args=op_args,
                    input_shape=input_shape,
                    output_shape=output_shape,
                    cuda_code=cuda_code
                )

                file_name = f"{op_name}_{op_args}_{input_shape}.text"

                # 保存文件
                with open(os.path.join(output_folder, file_name), 'w') as f:
                    f.write(prompt_content)


if __name__ == '__main__':

    # prompt.text的内容
    prompt_template_1 = """Task: Translate the given CUDA code to its equivalent C code.
    Context: You are provided with a CUDA code snippet that needs to be translated into C code. The translation should preserve the same functionality and structure as much as possible. Focus on translating the CUDA-specific parallel constructs into C constructs, such as using OpenMP for parallelism. The resulting C code should be complete and ready to compile.
    Following are some details of the cuda code:
    - Operation Name: {op_name}
    - Operation Arguments: {op_args}
    - Input Shape: {input_shape}
    - Output Shape: {output_shape}
    Input CUDA Code: \n{cuda_code}
    Print only single C function implementation, end with comment '|End-of-Code|'.
    """
    prompt_template_2 = """
    You are a senior CUDA and C programming expert, please translate the following CUDA Code to C Code: \n{cuda_code} 
    You must ensure that the generated C code matches the CUDA code parameter list, print only single C function implementation, end with comment '|End-of-Code|'.

    """

    # 调用函数生成prompt文件
    json_file_path = '/code/LLM4HPCTransCompile/benchmark/single_op'  # 请替换为实际的JSON文件路径
    generate_prompt_files(json_file_path, prompt_template_2)
