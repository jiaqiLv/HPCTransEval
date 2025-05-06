import argparse


parser = argparse.ArgumentParser()
parser.add_argument('--model',type=str,default='qwencoder',
                    help='the model to evaluate')
parser.add_argument('--file_name',type=str,default='prod_[15, 20, 3, 7]_[[15, 20, 3, 7]]',
                    help='the op type to generate')
parser.add_argument('--op_type',type=str,default='IndependentOperator',
                    help='the op type to generate')
# parser.add_argument('--json_name',type=str,default='Elementwise',
#                     help='the op type to generate')
args = parser.parse_args()