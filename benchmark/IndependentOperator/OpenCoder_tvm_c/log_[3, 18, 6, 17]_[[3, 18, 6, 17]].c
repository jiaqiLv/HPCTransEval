void default_function_kernel(float* compute, float* data) {
    int blockIdx_x = omp_get_thread_num();
    int threadIdx_x = 0;
    #pragma omp parallel for private(threadIdx_x)
    for (blockIdx_x = 0; blockIdx_x < 51; blockIdx_x++) {
        threadIdx_x = omp_get_thread_num();