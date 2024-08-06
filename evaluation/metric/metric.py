import os
from os.path import join,exists

if __name__ == "__main__":
    TYPE_LIST = ['Elementwise', 'Reduction', 'Layout-Transform', 'Logic-Intensive', 'Compute-Intensive']
    file_path = '/code/OpGen-Verify/code_verification/metric/performance'
    file_list = os.listdir(file_path)
    op_name_dict = {}
    for _file in file_list:
        if _file.split('_')[-1] == 'c.txt':
            op_type = _file.split('_')[-2]
            if op_type not in op_name_dict:
                op_name_dict[op_type] = []
            with open(join(file_path,_file),'r') as file:
                for line in file:
                    if line.split(':')[0] not in op_name_dict[op_type]:
                        op_name_dict[op_type].append(line.split(':')[0])
                        with open(join(file_path,f'result_gt_{op_type}.txt'),'a+') as file:
                            file.write(line)