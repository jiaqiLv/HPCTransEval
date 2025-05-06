void default_function_kernel(float* T_divide, float* T_subtract, float* compute, float* ph_0, float* ph_3) {
    int total_elements_T_divide = 9 * 13 * 10;
    int total_elements_T_subtract = 17 * 7 * 20;
    int total_elements_compute = 9 * 13 * 10;

    #pragma omp parallel for num_threads(64)
    for (int i = 0; i < total_elements_T_divide; ++i) {
        T_divide[i] = ph_0[i] / ph_3[i];
    }

    #pragma omp parallel for num_threads(32)
    for (int i = 0; i < total_elements_compute; ++i) {
        compute[i] = atanf(ph_0[i]);
    }

    #pragma omp parallel for num_threads(18)
    for (int i = 0; i < total_elements_T_subtract; ++i) {
        T_subtract[i] = cosf(ph_0[i]) - ph_0[i];
    }
}