void default_function_kernel(float* compute, float* data) {
    int blockIdx_x = omp_get_thread_num();
    int threadIdx_x = blockIdx_x;
    compute[((((int)blockIdx_x) * 18) + ((int)threadIdx_x))] = atanf(data[((((int)blockIdx_x) * 18) + ((int)threadIdx_x))];
}