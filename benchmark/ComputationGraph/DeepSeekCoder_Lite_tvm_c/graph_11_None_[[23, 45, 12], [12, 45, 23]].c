void default_function_kernel_6(float* T_softmax_maxelem, float* T_softmax_norm, float* T_transpose) {
    int num_blocks = 3105 / 1024;
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        int idx = b * 1024 + omp_get_thread_num() * 32;
        if (idx < 3105) {
            T_softmax_norm[idx] = T_transpose[idx] / T_softmax_maxelem[(b * 1024 + omp_get_thread_num()) / 23];
        }
    }
}