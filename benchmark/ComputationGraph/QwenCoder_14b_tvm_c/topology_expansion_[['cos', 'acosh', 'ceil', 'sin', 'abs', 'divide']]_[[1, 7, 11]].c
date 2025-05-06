void default_function_kernel(float* T_divide, float* compute, float* compute_1, float* compute_2, float* ph_0) {
    int size = 1 * 7 * 11; // Total number of elements

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        T_divide[i] = fabsf(ph_0[i]) / ph_0[i];
        compute[i] = cosf(ph_0[i]);
        compute_1[i] = sinf(ph_0[i]);
        compute_2[i] = ceilf(acoshf(ph_0[i]));
    }
}