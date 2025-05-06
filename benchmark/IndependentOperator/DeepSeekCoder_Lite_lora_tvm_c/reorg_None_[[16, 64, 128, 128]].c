void default_function_kernel(float* A, float* T_reshape) {
    int blockIdx_x = omp_get_thread_num();
    int threadIdx_x = omp_get_thread_num();

    T_reshape[((((blockIdx_x) * 1024) + (threadIdx_x)))] = A[(((((((((blockIdx_x) >> 10) * 4194304) + ((((blockIdx_x) & 255) * 4096)) + ((((threadIdx_x) >> 7) * 512)) + (((((blockIdx_x) & 1023) >> 9) * 256)) + ((((threadIdx_x) & 127) * 2)) + ((((blockIdx_x) & 511) >> 8))))))];
}