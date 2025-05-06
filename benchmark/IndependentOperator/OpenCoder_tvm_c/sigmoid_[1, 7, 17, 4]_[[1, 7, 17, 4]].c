void default_function_kernel(float* compute, float* data) {
    int blockIdx_x = omp_get_thread_num();
    int threadIdx_x = blockIdx_x;
    compute[((((int)blockIdx_x) * 7) + ((int)threadIdx_x)) = (1.000000e+00f / (1.000000e+00f + exp((0.000000e+00f - data[((((int)blockIdx_x) * 7) + ((int)threadIdx_x))]))));
}