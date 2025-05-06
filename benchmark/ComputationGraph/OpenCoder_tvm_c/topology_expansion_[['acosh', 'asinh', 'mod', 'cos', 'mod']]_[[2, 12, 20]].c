void default_function_kernel(float* T_mod, float* T_mod_1, float* compute, float* ph_0) {
    int blockIdx_x = omp_get_thread_num();
    int threadIdx_x = omp_get_num_threads();
    compute[((blockIdx_x * 16) + (threadIdx_x))] = acoshf(ph_0[((blockIdx_x * 16) + (threadIdx_x))]);
    T_mod_1[((blockIdx_x * 16) + (threadIdx_x))] = fmodf(asinhf(ph_0[((blockIdx_x * 16) + (threadIdx_x))]), ph_0[((blockIdx_x * 16) + (threadIdx_x))]);
    T_mod[((blockIdx_x * 32) + (threadIdx_x))] = fmodf(ph_0[((blockIdx_x * 32) + (threadIdx_x))], __cosf(ph_0[((blockIdx_x * 32) + (threadIdx_x))]));
}