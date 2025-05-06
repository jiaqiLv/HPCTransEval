
set -e

# # DSC

python /code/HPCTransEval/evaluation/evaluate.py --model DeepSeekCoder_Lite_tvm \
                                            --op_type ComputationGraph

python /code/HPCTransEval/evaluation/evaluate.py --model DeepSeekCoder_Lite_lora_tvm \
                                            --op_type ComputationGraph

python /code/HPCTransEval/evaluation/evaluate.py --model DeepSeekCoder_Lite_tvm \
                                            --op_type IndependentOperator
                
python /code/HPCTransEval/evaluation/evaluate.py --model DeepSeekCoder_Lite_lora_tvm \
                                            --op_type IndependentOperator

# python /code/HPCTransEval/evaluation/evaluate.py --model DeepSeekCoder_Lite_tvm \
#                                             --op_type ModelBuildingBlock

# python /code/HPCTransEval/evaluation/evaluate.py --model DeepSeekCoder_Lite_lora_tvm \
#                                             --op_type ModelBuildingBlock

# # OC

python /code/HPCTransEval/evaluation/evaluate.py --model OpenCoder_tvm \
                                            --op_type ComputationGraph

python /code/HPCTransEval/evaluation/evaluate.py --model OpenCoder_lora_tvm \
                                            --op_type ComputationGraph

python /code/HPCTransEval/evaluation/evaluate.py --model OpenCoder_tvm \
                                            --op_type IndependentOperator

python /code/HPCTransEval/evaluation/evaluate.py --model OpenCoder_lora_tvm \
                                            --op_type IndependentOperator
                
# python /code/HPCTransEval/evaluation/evaluate.py --model OpenCoder_tvm \
#                                             --op_type ModelBuildingBlock

# python /code/HPCTransEval/evaluation/evaluate.py --model OpenCoder_lora_tvm \
#                                             --op_type ModelBuildingBlock
                

# # QWC

python /code/HPCTransEval/evaluation/evaluate.py --model QwenCoder_14b_tvm \
                                            --op_type ComputationGraph

python /code/HPCTransEval/evaluation/evaluate.py --model QwenCoder_14b_lora_tvm \
                                            --op_type ComputationGraph

python /code/HPCTransEval/evaluation/evaluate.py --model QwenCoder_14b_tvm \
                                            --op_type IndependentOperator

python /code/HPCTransEval/evaluation/evaluate.py --model QwenCoder_14b_lora_tvm \
                                            --op_type IndependentOperator
                
# python /code/HPCTransEval/evaluation/evaluate.py --model QwenCoder_14b_tvm \
#                                             --op_type ModelBuildingBlock

# python /code/HPCTransEval/evaluation/evaluate.py --model QwenCoder_14b_lora_tvm \
#                                             --op_type ModelBuildingBlock