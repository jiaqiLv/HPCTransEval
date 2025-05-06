void default_function_kernel(float* A, float* T_reshape) {
    int total_threads = 1024;
    int num_blocks = 1;

    #pragma omp parallel for num_threads(total_threads)
    for (int i = 0; i < num_blocks * total_threads; ++i) {
        int blockIdx_x = i / total_threads;
        int threadIdx_x = i % total_threads;

        int index = ((blockIdx_x * 1024) + threadIdx_x);
        int value = A[((((((((blockIdx_x * 16) + (threadIdx_x >> 6)) / 5) * 320) + (((((((blockIdx_x * 32) + (threadIdx_x >> 1)) % 160) / 5) * 10)) + (((blockIdx_x * 4) + threadIdx_x) % 10))];

        T_reshape[index] = value;
    }
}