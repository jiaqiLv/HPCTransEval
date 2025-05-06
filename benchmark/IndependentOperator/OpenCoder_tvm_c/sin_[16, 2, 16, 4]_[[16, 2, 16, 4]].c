void default_function_kernel(float* compute, float* data) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    #pragma omp parallel for collapse(2)
    for (blockIdx_x = 0; blockIdx_x < 16; blockIdx_x++) {
        for (threadIdx_x = 0; threadIdx_x < 4; threadIdx_x++) {
            compute[(blockIdx_x * 4) + threadIdx_x] = sinf(data[(blockIdx_x * 4) + threadIdx_x]);
        }
    }
}