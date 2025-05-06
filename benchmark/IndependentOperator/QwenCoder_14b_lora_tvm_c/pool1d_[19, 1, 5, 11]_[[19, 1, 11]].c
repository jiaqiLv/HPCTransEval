void default_function_kernel(float* data, float* pool_max) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 17; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < 7; ++threadIdx_x) {
            int index = (blockIdx_x * 7) + threadIdx_x;
            if (index < 114) {
                pool_max[index] = -3.402823e+38f;
                for (int rv0 = 0; rv0 < 3; ++rv0) {
                    int input_index = (((((blockIdx_x + threadIdx_x) % 6) * 2) + rv0) - 1);
                    if (input_index >= 0 && input_index < 11) {
                        pool_max[index] = fmaxf(pool_max[index], data[input_index]);
                    }
                }
            }
        }
    }
}