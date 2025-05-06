void default_function_kernel(float* T_transpose, float* ph) {
    int num_threads = omp_get_max_threads();
    #pragma omp parallel for
    for (int i = 0; i < 30 * 4 * 7; ++i) {
        T_transpose[i] = ph[i];
    }
}