void default_function_kernel(float* compute, float* data) {
    int blockIdx_x = omp_get_thread_num();
    int threadIdx_x = blockIdx_x;
    compute[(blockIdx_x * 33) + threadIdx_x] = tanhf(data[(blockIdx_x * 33) + threadIdx_x]);
}