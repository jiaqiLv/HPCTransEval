void default_function_kernel(float* DilatedInput, float* data) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    int size = 11 * 16 * 7;
    #pragma omp parallel for private(threadIdx_x)
    for (blockIdx_x = 0; blockIdx_x < 2; blockIdx_x++) {
        for (threadIdx_x = 0; threadIdx_x < size; threadIdx_x++) {
            DilatedInput[(blockIdx_x * size) + threadIdx_x] = data[(blockIdx_x * size) + threadIdx_x];
        }
    }
}