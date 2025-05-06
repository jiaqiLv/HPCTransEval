void default_function_kernel(float* compute, float* ph_0) {
    int size = 11 * 8 * 3;
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        compute[i] = expf(ph_0[i] * asinhf(ph_0[i]));
    }
}