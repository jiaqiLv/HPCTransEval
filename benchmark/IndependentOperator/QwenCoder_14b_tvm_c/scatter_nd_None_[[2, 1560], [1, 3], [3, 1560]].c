void default_function_kernel(float* data, int32_t* indices, float* scatter_nd_generic, float* updates) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_y = 0; blockIdx_y < 195; blockIdx_y++) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            int index = ((blockIdx_y * 128) + (threadIdx_x >> 3));
            if (index < 195) {
                scatter_nd_generic[(((indices[blockIdx_y] * 1560) + (blockIdx_y * 1024)) + threadIdx_x)] += updates[((blockIdx_y * 1024) + threadIdx_x)];
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 195; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            int index = ((blockIdx_x * 64) + (threadIdx_x >> 4));
            if (index < 195) {
                scatter_nd_generic[((blockIdx_x * 1024) + threadIdx_x)] = data[((blockIdx_x * 1024) + threadIdx_x)];
            }
        }
    }
}