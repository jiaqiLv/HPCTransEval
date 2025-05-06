void default_function_kernel(float* compute, float* data) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    #pragma omp parallel for collapse(= 0;
    for (threadIdx_x = 0; blockIdx_x < 48; threadIdx_x = 0;
    compute[(blockIdx_x * 64) + threadIdx_x = fabsf(data[(blockIdx_x = 0;
    for (threadIdx_x = 0; blockIdx_x < 48; threadIdx_x = 0;
    compute[(blockIdx_x * 64) + threadIdx_x = 0;
    }