void default_function_kernel(float* Scale, float* compute, float* data) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    #pragma omp parallel for private(threadIdx_x)
    for(blockIdx_x = 0; blockIdx_x < 9; blockIdx_x++){
        for(threadIdx_x = 0; threadIdx_x < 38; threadIdx_x++){
            compute[(blockIdx_x * 38) + threadIdx_x] = (0.0 < data[(blockIdx_x * 38) + threadIdx_x]) ? data[(blockIdx_x * 38) + threadIdx_x] : (data[(blockIdx_x * 38) + threadIdx_x] * Scale[threadIdx_x % 19]);
        }
    }
}