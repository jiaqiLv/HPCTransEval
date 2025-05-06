void default_function_kernel(float* data, float* pool_max) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 9; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < 6; ++threadIdx_x) {
            int index = (blockIdx_x * 6) + threadIdx_x;
            pool_max[index] = -3.402823e+38f;

            for (int rv0 = 0; rv0 < 3; ++rv0) {
                for (int rv1 = 0; rv1 < 3; ++rv1) {
                    int data_index = (((blockIdx_x % 9) * 2) + rv0) * 12 + (((threadIdx_x) * 2) + rv1) - 13;
                    if (data_index >= 0 && data_index < 18 * 12) {
                        pool_max[index] = fmaxf(pool_max[index], data[data_index]);
                    }
                }
            }
        }
    }
}