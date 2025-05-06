# ComputationGraph IndependentOperator ModelBuildingBlock

python /code/HPCTransEval/evaluation/evaluate.py --model QwenCoder_14b_tvm \
                                            --op_type ComputationGraph

python /code/HPCTransEval/evaluation/evaluate.py --model QwenCoder_14b_tvm \
                                            --op_type IndependentOperator
                
python /code/HPCTransEval/evaluation/evaluate.py --model QwenCoder_14b_tvm \
                                            --op_type ModelBuildingBlock