void default_function_kernel(float* T_add, float* data, float* data_1) {
    #pragma omp parallel for
    for (int i = 0; i < 20 * 10 * 9 * 18; ++i) {
        T_add[i] = data[i] + data_1[i];
    }
}