void default_function_kernel(float* T_reverse_sequence, float* data) {
    #pragma omp parallel for
    for (int i = 0; i < 104; i++) {
        int blockIdx_x = i / 13;
        int threadIdx_x = i % 13;
        T_reverse_sequence[i] = data[((blockIdx_x & 7) * 13 + threadIdx_x + 312 - ((blockIdx_x >> 3) * 104))];
    }
}