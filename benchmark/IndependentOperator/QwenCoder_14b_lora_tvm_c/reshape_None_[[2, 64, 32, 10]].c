void default_function_kernel(float* A, float* T_reshape) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 128; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            int index = ((blockIdx_x * 1024) + threadIdx_x);
            int value = (((((blockIdx_x * 16) + (threadIdx_x >> 6)) / 5) * 320) + (((((blockIdx_x * 32) + (threadIdx_x >> 1)) % 160) / 5) * 10)) + ((blockIdx_x * 4) + (threadIdx_x % 10));
            T_reshape[index] = A[value];
        }
    }
}