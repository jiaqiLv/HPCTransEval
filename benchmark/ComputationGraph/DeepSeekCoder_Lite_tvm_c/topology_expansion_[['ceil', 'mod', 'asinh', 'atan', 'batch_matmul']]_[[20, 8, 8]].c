void default_function_kernel(float* compute, float* ph_0) {
    int blockIdx_x = omp_get_thread_num();
    int threadIdx_x = omp_get_thread_num() % 32;

    compute[blockIdx_x * 32 + threadIdx_x] = asinhf(fmodf(ph_0[blockIdx_x * 32 + threadIdx_x], ceilf(ph_0[blockIdx_x * 32 + threadIdx_x])));
}