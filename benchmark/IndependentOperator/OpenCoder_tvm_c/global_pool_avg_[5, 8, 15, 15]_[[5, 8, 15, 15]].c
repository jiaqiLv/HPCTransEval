void default_function_kernel(float* adaptive_pool_avg, float* data) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    int rv0 = 0;
    int rv1 = 0;
    float sum = 0.0f;

    #pragma omp parallel for collapse(2) private(rv0, rv1, sum)
    for (blockIdx_x = 0; blockIdx_x < 5; ++blockIdx_x) {
        sum = 0.0f;
        for (rv0 = 0; rv0 < 15; ++rv0) {
            for (rv1 = 0; rv1 < 15; ++rv1) {
                sum += data[((((blockIdx_x * 4500) + (threadIdx_x * 225)) + (rv0 * 15)) + rv1)];
            }
        }
        adaptive_pool_avg[(blockIdx_x * 20) + threadIdx_x] = sum * 0.444444f;
    }
}