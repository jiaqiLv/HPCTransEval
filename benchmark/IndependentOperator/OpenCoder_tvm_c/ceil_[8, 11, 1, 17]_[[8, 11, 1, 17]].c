void default_function_kernel(float* compute, float* data) {
    int blockIdx_x = omp_get_thread_num();
    int threadIdx_x = blockIdx_x;
    if (((((int)blockIdx_x) * 4) + (((int)threadIdx_x) >> 3)) < 187) {
        compute[((((int)blockIdx_x) * 32) + ((int)threadIdx_x))] = ceil(data[((((int)blockIdx_x) * 32) + ((int)threadIdx_x))]);
    }
}