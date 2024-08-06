import argparse


parser = argparse.ArgumentParser()
parser.add_argument('--model',type=str,default='deepseek',
                    help='the model to evaluate')
parser.add_argument('--op_name',type=str,default='abs',
                    help='the op type to generate')
parser.add_argument('--op_type',type=str,default='Elementwise',
                    help='the op type to generate')
parser.add_argument('--json_name',type=str,default='Elementwise',
                    help='the op type to generate')
args = parser.parse_args()