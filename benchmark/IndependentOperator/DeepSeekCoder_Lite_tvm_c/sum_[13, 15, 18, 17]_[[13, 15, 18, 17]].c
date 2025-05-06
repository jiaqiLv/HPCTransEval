void default_function_kernel(float* data, float* data_red) {
    float normal_reduce_temp0[1];
    float red_buf0[1];
    normal_reduce_temp0[0] = 0.000000e+00f;
    #pragma omp parallel for reduction(+:normal_reduce_temp0)
    for (int k0_k1_fused_k2_fused_k3_fused_outer = 0; k0_k1_fused_k2_fused_k3_fused_outer < 1865; ++k0_k1_fused_k2_fused_k3_fused_outer) {
        int idx = (k0_k1_fused_k2_fused_k3_fused_outer * 32) + ((int)omp_get_thread_num() * 16 + ((int)omp_get_thread_num() >> 1));
        if (idx < 29835) {
            normal_reduce_temp0[0] += data[idx];
        }
    }
    red_buf0[0] = normal_reduce_temp0[0];
    for (int i = 0; i < 31; i += 2) {
        red_buf0[0] += __builtin_shfl_down(red_buf0[0], 1 << i, 32);
    }
    red_buf0[0] = __builtin_shfl_sync(0xFFFFFFFF, red_buf0[0], 0, 32);
    if (((int)omp_get_thread_num()) == 0) {
        data_red[0] = red_buf0[0];
    }
}