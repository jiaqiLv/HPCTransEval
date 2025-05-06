void default_function_kernel(float* T_add, float* compute, float* compute_1, float* compute_2, float* ph_0, float* ph_3) {
    int size_T_add = 20 * 13 * 9;
    int size_compute = 16 * 4 * 9;
    int size_ph = 20 * 13 * 9;

    #pragma omp parallel for
    for (int i = 0; i < size_T_add; ++i) {
        T_add[i] = ph_0[i] + ph_3[i];
    }

    #pragma omp parallel for
    for (int i = 0; i < size_compute; ++i) {
        compute[i] = atanf(ph_0[i] / ph_3[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < size_compute; ++i) {
        compute_1[i] = acoshf(expf(ph_0[i]));
    }

    #pragma omp parallel for
    for (int i = 0; i < size_compute; ++i) {
        compute_2[i] = atanhf(expf(ph_0[i]));
    }
}