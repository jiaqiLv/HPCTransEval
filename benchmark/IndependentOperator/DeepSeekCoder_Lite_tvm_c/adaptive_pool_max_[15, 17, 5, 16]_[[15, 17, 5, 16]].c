void default_function_kernel(float* adaptive_pool_max, float* data) {
    int blockIdx_x = omp_get_thread_num();
    int threadIdx_x = omp_get_thread_num();

    adaptive_pool_max[(blockIdx_x * 60) + threadIdx_x] = -3.402823e+38f;

    for (int rv0 = 0; rv0 < 8; ++rv0) {
        for (int rv1 = 0; rv1 < 2; ++rv1) {
            int index = (((blockIdx_x * 15) + (threadIdx_x >> 2)) >> 4) * 80 + 
                        ((((blockIdx_x * 15) + (threadIdx_x >> 2)) & 15) >> 1) * 5 >> 3 * 16 + 
                        (rv0 * 16) + 
                        ((((blockIdx_x * 4) + threadIdx_x) & 7) * 2) + 
                        rv1;
            adaptive_pool_max[(blockIdx_x * 60) + threadIdx_x] = fmaxf(adaptive_pool_max[(blockIdx_x * 60) + threadIdx_x], data[index]);
        }
    }
}