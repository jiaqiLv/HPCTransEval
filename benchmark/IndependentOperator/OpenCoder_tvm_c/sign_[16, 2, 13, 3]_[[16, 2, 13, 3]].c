void default_function_kernel(float* T_sign, float* data) {
    int blockIdx_x = omp_get_thread_num();
    int threadIdx_x = blockIdx_x;
    T_sign[((((int)blockIdx_x) * 16) + ((int)threadIdx_x))] < 0.000000e+00f)) : 0.000000e+00f)) : 0.000000e+00f));
}