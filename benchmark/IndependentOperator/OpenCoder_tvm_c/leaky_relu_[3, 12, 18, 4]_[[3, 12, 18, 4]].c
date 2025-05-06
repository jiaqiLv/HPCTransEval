void default_function_kernel(float* compute, float* data) {
    int blockIdx_x = omp_get_thread_num();
    int threadIdx_x = blockIdx_x;
    compute[blockIdx_x * 24 + threadIdx_x] = (0.0f < data[blockIdx_x * 24 + threadIdx_x]) ? data[blockIdx_x * 24 + threadIdx_x] * 0.0f>