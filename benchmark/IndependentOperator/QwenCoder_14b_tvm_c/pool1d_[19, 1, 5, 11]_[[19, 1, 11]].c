void default_function_kernel(float* data, float* pool_max) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 17; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < 7; ++threadIdx_x) {
            int idx = (blockIdx_x * 7) + threadIdx_x;
            if (idx < 114) {
                pool_max[idx] = -3.402823e+38f;
                for (int rv0 = 0; rv0 < 3; ++rv0) {
                    int input_idx = (((((blockIdx_x + threadIdx_x) % 6) * 2) + rv0) - 1);
                    if (input_idx >= 0 && input_idx < 11) {
                        pool_max[idx] = fmaxf(pool_max[idx], data[input_idx]);
                    }
                }
            }
        }
    }
}