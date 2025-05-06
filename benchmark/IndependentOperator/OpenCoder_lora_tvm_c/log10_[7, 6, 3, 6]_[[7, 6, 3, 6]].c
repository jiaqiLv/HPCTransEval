void default_function_kernel(float* compute, float* data) {
    int i;
    #pragma omp parallel for
    for (i = 0; i < 7 * 6 * 3 * 6; i++) {
        compute[i] = log10f(data[i]);
    }
}