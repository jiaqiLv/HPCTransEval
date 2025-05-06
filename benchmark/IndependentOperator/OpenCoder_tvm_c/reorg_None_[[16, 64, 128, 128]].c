void default_function_kernel(float* A, float* T_reshape) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    int T_reshape_idx = 0;
    int A_idx = 0;

    #pragma omp parallel for private(blockIdx_x, threadIdx_x, T_reshape_idx, A_idx)
    for (blockIdx_x = 0; blockIdx_x < 1024; blockIdx_x++) {
        for (threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            T_reshape_idx = ((blockIdx_x * 1024) + threadIdx_x);
            A_idx = (((((((blockIdx_x >> 10) * 4194304) + ((blockIdx_x & 255) * 4096)) + ((threadIdx_x >> 7) * 512)) + ((blockIdx_x & 1023) >> 9) * 256)) + ((threadIdx_x & 127) * 2)) + ((blockIdx_x & 511) >> 8));
            T_reshape[T_reshape_idx] = A[A_idx];
        }
    }
}