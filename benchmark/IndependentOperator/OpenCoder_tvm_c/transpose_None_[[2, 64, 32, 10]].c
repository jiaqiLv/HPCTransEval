void default_function_kernel(float* A, float* T_transpose) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    int temp = 0;
    #pragma omp parallel for private(threadIdx_x)
    for (blockIdx_x = 0; blockIdx_x < 40; blockIdx_x++) {
        for (threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            temp = ((blockIdx_x / 20) * 20480) + ((threadIdx_x & 63) * 320) + ((blockIdx_x % 20) * 16) + (threadIdx_x >> 6);
            T_transpose[((blockIdx_x * 1024) + threadIdx_x)] = A[temp];
        }
    }
}