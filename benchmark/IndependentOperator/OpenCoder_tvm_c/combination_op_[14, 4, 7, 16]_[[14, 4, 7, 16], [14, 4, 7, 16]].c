void default_function_kernel(float* T_add, float* data, float* data_1) {
    int blockIdx_x = omp_get_thread_num();
    int threadIdx_x = blockIdx_x;
    T_add[((blockIdx_x * 32) + (threadIdx_x))] = (sqrtf(data[((blockIdx_x * 32) + (threadIdx_x))]) + cosf(data_1[((blockIdx_x * 32) + (threadIdx_x))]));
}