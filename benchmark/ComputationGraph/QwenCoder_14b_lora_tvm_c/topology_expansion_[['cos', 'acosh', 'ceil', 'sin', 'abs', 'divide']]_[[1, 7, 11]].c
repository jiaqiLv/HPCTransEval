void default_function_kernel(float* T_divide, float* compute, float* compute_1, float* compute_2, float* ph_0) {
    int total_elements = 1 * 7 * 11;

    #pragma omp parallel for
    for (int i = 0; i < total_elements; ++i) {
        compute[i] = cosf(ph_0[i]);
        compute_1[i] = sinf(ph_0[i]);
        compute_2[i] = ceilf(acoshf(ph_0[i]));
        T_divide[i] = fabsf(ph_0[i]) / ph_0[i];
    }
}