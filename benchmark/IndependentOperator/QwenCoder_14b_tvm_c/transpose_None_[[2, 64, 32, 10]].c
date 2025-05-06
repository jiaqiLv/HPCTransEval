void default_function_kernel(float* A, float* T_transpose) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 20; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            int index = ((blockIdx_x * 1024) + threadIdx_x);
            int src_index = (((blockIdx_x / 20) * 20480) + ((threadIdx_x & 63) * 320) + ((blockIdx_x % 20) * 16) + (threadIdx_x >> 6));
            T_transpose[index] = A[src_index];
        }
    }
}