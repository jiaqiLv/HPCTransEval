void default_function_kernel(float* A, float* T_reshape) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 16; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            int index = ((blockIdx_x * 1024) + threadIdx_x);
            T_reshape[index] = A[(((((((((blockIdx_x >> 10) * 4194304) + ((blockIdx_x & 255) * 4096)) + ((threadIdx_x >> 7) * 512)) + (((blockIdx_x & 1023) >> 9) * 256)) + ((threadIdx_x & 127) * 2)) + ((blockIdx_x & 511) >> 8))];
        }
    }
}