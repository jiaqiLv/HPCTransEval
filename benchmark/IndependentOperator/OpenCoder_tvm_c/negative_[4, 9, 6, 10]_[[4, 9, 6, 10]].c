void default_function_kernel(float* compute, float* data) {
    int blockIdx_x = omp_get_num_threads();
    int threadIdx_x = omp_get_num_threads();
    compute[((((int)blockIdx_x) * 8) + ((int)threadIdx_x))] * -1.000000e+00f);