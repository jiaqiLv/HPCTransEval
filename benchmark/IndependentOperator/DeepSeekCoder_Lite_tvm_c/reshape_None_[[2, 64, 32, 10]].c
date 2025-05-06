void default_function_kernel(float* A, float* T_reshape) {
    int num_blocks = 128; // Derived from blockIdx.x range in CUDA kernel
    int num_threads = 1024; // Number of threads per block, derived from threadIdx.x range in CUDA kernel

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads; i++) {
        int block_idx = i / num_threads;
        int thread_idx = i % num_threads;
        int index = (((((block_idx * 16) + (thread_idx >> 6)) / 5) * 320) + ((((((block_idx * 32) + (thread_idx >> 1)) % 160) / 5) * 10)) + ((block_idx * 4) + (thread_idx) % 10));
        T_reshape[i] = A[index];
    }
}