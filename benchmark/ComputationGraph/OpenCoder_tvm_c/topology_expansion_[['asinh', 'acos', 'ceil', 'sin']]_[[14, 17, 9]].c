void default_function_kernel(float* compute, float* ph_0) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    int i = 0;
    #pragma omp parallel for collapse(2) private(i, threadIdx_x)
    for (blockIdx_x = 0; blockIdx_x < 14; blockIdx_x++) {
        for (threadIdx_x = 0; threadIdx_x < 17; threadIdx_x++) {
            i = blockIdx_x * 17 + threadIdx_x;
            compute[i] = asinhf(ph_0[i]);
        }
    }
}