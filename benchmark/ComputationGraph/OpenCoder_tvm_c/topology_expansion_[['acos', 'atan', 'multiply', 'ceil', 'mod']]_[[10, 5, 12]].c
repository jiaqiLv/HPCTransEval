void default_function_kernel(float* T_mod, float* T_multiply, float* compute, float* ph_0) {
    int num_threads = omp_get_max_threads();
    omp_set_num_threads(num_threads);
    #pragma omp parallel for
    for (int i = 0; i < 10; i++) {
        T_mod[i] = fmodf(ph_0[i], ceilf(ph_0[i]));
        T_multiply[i] = atanf(ph_0[i]) * ph_0[i];
        compute[i] = acosf(ph_0[i]);
    }
}