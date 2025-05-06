void default_function_kernel(float* data, float* depth_to_space) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 54; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 54; threadIdx_x++) {
            int index = ((blockIdx_x * 54) + threadIdx_x);
            depth_to_space[index] = data[((((((((blockIdx_x >> 2) * 270) + (((((blockIdx_x & 3) * 9) + (threadIdx_x / 6)) % 2) * 108)) + (((threadIdx_x % 6) % 2) * 54)) + (((((blockIdx_x & 3) * 9) + (threadIdx_x / 6)) / 2) * 3)) + ((threadIdx_x % 6) / 2))];
        }
    }
}