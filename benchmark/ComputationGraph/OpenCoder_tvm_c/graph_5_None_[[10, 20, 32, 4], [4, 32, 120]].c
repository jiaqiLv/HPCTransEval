void default_function_kernel(float* T_power, float* ph, float* ph_1) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    #pragma omp parallel for collapse(2) private(threadIdx_x)
    for (blockIdx_x = 0; blockIdx_x < 10; blockIdx_x++) {
        for (threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            T_power[(blockIdx_x * 1024) + threadIdx_x] = powf((1.1 - ph[(blockIdx_x * 1024) + threadIdx_x]), 2.0);
            ph_1[(blockIdx_x * 1024) + threadIdx_x] = ph[(blockIdx_x * 1024) + threadIdx_x] * 4;
        }
    }
}