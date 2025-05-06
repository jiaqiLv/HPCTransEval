void default_function_kernel(float* compute, float* data) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    #pragma omp parallel for private(threadIdx_x = 0; threadIdx_x < 17; threadIdx_x++) {
        for (threadIdx_x = 0; threadIdx_x < 7; threadIdx_x++) {
            compute[(blockIdx_x * 7) + threadIdx_x] = cosf(data[(blockIdx_x * 7) + threadIdx_x]);