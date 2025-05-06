void default_function_kernel(float* compute, float* data) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    #pragma omp parallel for collapse(2)
    for (blockIdx_x = 0; blockIdx_x < 4; blockIdx_x++) {
        for ( threadIdx_x = 0; threadIdx_x < 8; threadIdx_x++) {
            compute[((blockIdx_x * 8) + threadIdx_x)] = (data[((blockIdx_x * 8) + threadIdx_x)] = (data[((blockIdx_x * 8) + threadIdx_x)] * -1.000000e+00f);
        }
    }
}