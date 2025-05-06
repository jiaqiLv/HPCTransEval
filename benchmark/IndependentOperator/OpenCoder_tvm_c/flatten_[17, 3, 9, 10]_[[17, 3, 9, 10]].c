void default_function_kernel(float* compute, float* data) {
    int blockIdx_x = omp_get_thread_num();
    int threadIdx = omp_get_num_threads();
    compute[((((int) * 30) + ((int)threadidx_x))];