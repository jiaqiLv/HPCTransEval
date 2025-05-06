void default_function_kernel(float* Scale, float* ScaleShift, float* Shift, float* data) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    int i = 0;
    #pragma omp parallel for private(i, threadIdx_x, blockIdx_x)
    for (i = 0; i < 64; i++) {
        blockIdx_x = i;
        threadIdx_x = i;
        ScaleShift[i] = data[i] * Scale[((((((blockIdx_x / 49) * 2) + (threadIdx_x >> 5)) / 49) * 7) + (blockIdx_x % 7))] + Shift[((((((blockIdx_x / 49) * 2) + (threadIdx_x >> 5)) / 49) * 7) + (blockIdx_x % 7))];
    }
}