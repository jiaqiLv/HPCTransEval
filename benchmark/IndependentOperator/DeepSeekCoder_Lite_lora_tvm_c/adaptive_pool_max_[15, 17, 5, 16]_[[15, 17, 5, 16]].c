void default_function_kernel(float* adaptive_pool_max, float* data) {
    #pragma omp parallel for
    for (int idx = 0; idx < 60; ++idx) {
        adaptive_pool_max[idx] = -3.402823e+38f;
    }

    #pragma omp parallel for
    for (int idx = 0; idx < 60; ++idx) {
        for (int rv0 = 0; rv0 < 2; ++rv0) {
            for (int rv1 = 0; rv1 < 16; ++rv1) {
                int data_idx = (((((idx / 4) * 80) + ((((idx & 3) >> 1) * 5) >> 3) * 16)) + (rv0 * 16) + ((((idx & 3) * 2) + rv1) & 15));
                adaptive_pool_max[idx] = fmaxf(adaptive_pool_max[idx], data[data_idx]);
            }
        }
    }
}