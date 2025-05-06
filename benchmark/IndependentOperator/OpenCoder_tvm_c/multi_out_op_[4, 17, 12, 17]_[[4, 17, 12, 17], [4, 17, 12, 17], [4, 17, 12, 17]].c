void default_function_kernel(float* compute, float* compute_1, float* data, float* data_1) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    #pragma omp parallel for collapse(2) private(blockIdx_x, threadIdx_x)
    for (blockIdx_x = 0; blockIdx_x < 4; blockIdx_x++) {
        for (threadIdx_x = 0; threadIdx_x < 24; threadIdx_x++) {
            compute[((blockIdx_x * 24) + threadIdx_x)] = cosf((data[((blockIdx_x * 24) + threadIdx_x)] + data_1[((blockIdx_x * 24) + threadIdx_x)]));
        }
    }
    #pragma omp parallel for collapse(2) private(blockIdx_x, threadIdx_x)
    for (blockIdx_x = 0; blockIdx_x < 4; blockIdx_x++) {
        for (threadIdx_x = 0; threadIdx_x < 6; threadIdx_x++) {
            compute_1[((blockIdx_x * 6) + threadIdx_x)] = sqrtf((data[((blockIdx_x * 6) + threadIdx_x)] + data_1[((blockIdx_x * 6) + threadIdx_x)]));
        }
    }
}