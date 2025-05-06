void default_function_kernel(float* compute, float* ph) {
    int i;
    #pragma omp parallel for
    for (i = 0; i < 405; i++) {
        compute[i] = max(min(ph[i], 1.111000e+01f), 1.100000e+00f);
    }
}