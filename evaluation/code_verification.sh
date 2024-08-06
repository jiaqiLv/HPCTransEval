PYTHON_PROGRAM="code_verification.py"

Generated_Graph=(
'topology_expansion_[['abs', 'asinh', 'exp', 'ceil', 'ceil']]_[[1, 9, 2]]'
'topology_expansion_[['exp', 'atanh']]_[[13, 17, 7]]'
'topology_expansion_[['multiply', 'abs', 'atanh']]_[[19, 20, 18], [9, 19, 17], [19, 20, 18]]'
'topology_expansion_[['atan', 'atan', 'abs', 'atan']]_[[6, 3, 7]]'
'topology_expansion_[['divide', 'add', 'exp', 'acosh', 'atanh', 'atan']]_[[20, 13, 9], [16, 4, 9], [20, 13, 9]]'
'topology_expansion_[['sin', 'atanh', 'mod', 'acosh', 'sin', 'asinh']]_[[16, 10, 8]]'
'topology_expansion_[['atanh', 'ceil', 'acosh', 'ceil', 'ceil']]_[[15, 10, 18]]'
'topology_expansion_[['asinh', 'asin', 'atanh', 'sin']]_[[2, 11, 7]]'
'topology_expansion_[['ceil', 'asin', 'atanh', 'acos', 'sin', 'exp', 'asin']]_[[9, 11, 6]]'
'topology_expansion_[['atanh', 'asin', 'atanh', 'abs', 'asin']]_[[2, 5, 15]]'
'topology_expansion_[['atan', 'cos', 'add', 'exp']]_[[16, 17, 4]]'
'topology_expansion_[['ceil', 'mod', 'asinh', 'atan', 'batch_matmul']]_[[20, 8, 8]]'
'topology_expansion_[['divide', 'atan', 'cos', 'subtract']]_[[9, 13, 10], [17, 7, 20], [9, 13, 10]]'
'topology_expansion_[['mod', 'acosh', 'acosh', 'ceil', 'batch_matmul', 'subtract', 'acos']]_[[10, 15, 5], [10, 20, 3], [10, 15, 5], [10, 5, 1]]'
'topology_expansion_[['asinh', 'multiply', 'exp']]_[[11, 8, 3]]'
'topology_expansion_[['acosh', 'ceil', 'add', 'cos']]_[[3, 9, 3]]'
'topology_expansion_[['acos', 'cos', 'asinh', 'sin', 'atan']]_[[19, 17, 15]]'
'topology_expansion_[['asinh', 'acos', 'ceil', 'sin']]_[[14, 17, 9]]'
'topology_expansion_[['divide', 'subtract', 'multiply', 'asinh', 'atanh']]_[[19, 15, 9], [19, 12, 17], [19, 15, 9]]'
'topology_expansion_[['asinh', 'atan', 'cos', 'asinh', 'acosh']]_[[16, 18, 10]]'
'topology_expansion_[['cos', 'divide', 'atanh']]_[[11, 2, 8]]'
'topology_expansion_[['sin', 'asinh', 'atan', 'asinh']]_[[4, 1, 19]]'
'topology_expansion_[['subtract', 'acos', 'ceil', 'mod', 'ceil']]_[[20, 14, 4], [12, 10, 16], [20, 14, 4]]'
'topology_expansion_[['subtract', 'multiply', 'multiply', 'mod', 'ceil']]_[[16, 19, 8], [18, 11, 11], [16, 19, 8]]'
'topology_expansion_[['cos', 'acosh', 'ceil', 'sin', 'abs', 'divide']]_[[1, 7, 11]]'
'topology_expansion_[['multiply', 'atanh', 'ceil']]_[[10, 2, 1], [4, 2, 7], [10, 2, 1]]'
'topology_expansion_[['cos', 'add', 'atanh']]_[[8, 1, 18]]'
'topology_expansion_[['ceil']]_[[10, 17, 20]]'
'topology_expansion_[['acosh', 'asinh', 'mod', 'cos', 'mod']]_[[2, 12, 20]]'
'topology_expansion_[['ceil', 'asin', 'abs', 'asin', 'multiply', 'asinh']]_[[9, 10, 5]]'
'topology_expansion_[['abs', 'acosh', 'add', 'exp', 'sin', 'acos']]_[[16, 8, 2]]'
'topology_expansion_[['abs', 'cos', 'asinh', 'subtract', 'atanh', 'asin']]_[[1, 15, 2]]'
'topology_expansion_[['atanh', 'atan', 'cos', 'atan']]_[[9, 12, 16]]'
'topology_expansion_[['add', 'atan']]_[[1, 14, 4], [14, 17, 6], [1, 14, 4]]'
'topology_expansion_[['divide', 'asinh', 'subtract', 'abs', 'exp']]_[[18, 1, 10], [16, 1, 3], [18, 1, 10]]'
'topology_expansion_[['divide', 'divide', 'cos', 'asinh', 'acos', 'asinh']]_[[15, 18, 5], [8, 9, 2], [15, 18, 5]]'
'topology_expansion_[['acos', 'atan', 'multiply', 'ceil', 'mod']]_[[10, 5, 12]]'
'topology_expansion_[['add', 'acos', 'sin', 'cos', 'abs', 'multiply']]_[[8, 12, 16], [2, 9, 7], [8, 12, 16]]'
'topology_expansion_[['mod', 'sin', 'ceil', 'asinh']]_[[14, 2, 1], [20, 9, 19], [14, 2, 1]]'
'topology_expansion_[['asinh', 'sin', 'mod']]_[[4, 3, 17]]'
'graph_1_None_[[11, 22, 33, 44], [11, 22, 44, 33]]'
'graph_2_None_[[4, 5, 6], [20, 6]]'
'graph_3_None_[[4, 16, 32, 32]]'
'graph_4_None_[[10, 20, 3, 4]]'
'graph_5_None_[[10, 20, 32, 4], [4, 32, 120]]'
'graph_6_None_[[11, 22, 33, 44]]'
'graph_7_None_[[11, 22, 33, 44], [22, 33, 44, 55]]'
'graph_8_None_[[11, 22, 33, 44], [22, 33, 44, 55]]'
'graph_9_None_[[11, 22, 33, 44], [22, 33, 44, 55]]'
'graph_10_None_[[23, 45, 12]]'
'graph_11_None_[[23, 45, 12], [12, 45, 23]]'
'graph_12_None_[[23, 5, 12]]'
'graph_13_None_[[1, 45, 12], [32]]'
'graph_14_None_[[1, 33, 1, 44]]'
'graph_15_None_[[11, 22, 33, 44], [22, 33, 44, 55]]'
'graph_16_None_[[4, 16, 32, 32]]'
'graph_17_None_[[11, 22, 6, 7]]'
'graph_18_None_[[11, 22, 33, 44], [10, 10]]'
'graph_19_None_[[23, 5, 12]]'
'graph_20_None_[[23, 5, 12]]'
'graph_21_None_[[23, 5, 12]]'
'graph_22_None_[[1, 45, 12]]'
'graph_23_None_[[23, 5, 12]]'
'graph_24_None_[[11, 22, 33, 44], [22, 33, 44, 55]]'
'graph_25_None_[[3, 45, 12]]'
'graph_26_None_[[4, 16, 32, 32]]'
'graph_27_None_[[4, 5, 6, 7]]'
'graph_28_None_[[43, 54, 16, 17]]'
'graph_29_None_[[11, 22, 33, 44]]'
'graph_30_None_[[11, 22, 33, 44]]'
)

Elementwise=(erf leaky_relu sqrt asin tanh floor log sin prelu fast_exp 
log2 sign sigmoid isnan relu cos fast_tanh log10 round atan 
negative add tan atanh acos ceil asinh abs exp rsqrt 
sinh cosh combination_op fast_erf)

Reduction=(min global_pool_max global_pool_avg sum max rms_norm log_softmax softmax fast_softmax softmax_common 
prod pool3d pool1d pool2d  adaptive_pool_max adaptive_pool_avg)

Layout_Transform=(unpack_NCHWc_to_nchw flatten scale_shift_nchw flip depth_to_space batch_to_space_nd 
strided_slice space_to_depth scale_shift_nchwc mirror_pad dilate 
reshape transpose gather_nd scatter_nd reorg)

Logic_Intensive=(fifo_buffer multi_out_op shape upsampling resize2d resize3d grid_sample argsort)

Compute_Intensive=(lrn matmul conv2d_opt dft group_conv2d_opt batch_matmul_opt)

success=0
for model in "${Model[@]}"; do
    for op in "${Elementwise[@]}"; do
        python $PYTHON_PROGRAM \
            --op_name "$op" \
            --model "$model" \
            --op_type "OP_TYPE" \

        if [ $? -eq 0 ]; then
            success=$((success+1))
        else
            continue
        fi
    done
done