void default_function_kernel(float* Scale, float* ScaleShift, float* Shift, float* data) {
    #pragma omp parallel for
    for (int i = 0; i < 7 * 2 * 16 * 14 * 7; ++i) {
        int blockIdx_x = i / 64;
        int threadIdx_x = i % 64;

        int scale_index = (((blockIdx_x % 49) * 2 + (threadIdx_x >> 5)) / 49) * 7 + ((blockIdx_x + threadIdx_x) % 7);
        ScaleShift[i] = (data[i] * Scale[scale_index]) + Shift[scale_index];
    }
}