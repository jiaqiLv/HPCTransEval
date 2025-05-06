void default_function_kernel(float* Scale, float* ScaleShift, float* Shift, float* data) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    #pragma omp parallel for collapse(2)
    for(blockIdx_x = 0; blockIdx_x < 7; blockIdx_x++){
        for(threadIdx_x = 0; threadIdx_x < 64; threadIdx_x++){
            ScaleShift[((blockIdx_x * 64) + threadIdx_x)] = ((data[((blockIdx_x * 64) + threadIdx_x)] * Scale[((((((blockIdx_x % 49) * 2) + (threadIdx_x >> 5)) / 49) * 7) + (blockIdx_x + threadIdx_x) % 7)]) + Shift[((((((blockIdx_x % 49) * 2) + (threadIdx_x >> 5)) / 49) * 7) + (blockIdx_x + threadIdx_x) % 7)]);
        }
    }
}