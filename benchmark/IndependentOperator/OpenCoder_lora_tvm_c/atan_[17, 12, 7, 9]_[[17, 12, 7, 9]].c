void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for
    for (int i = 0; i < 17 * 12 * 7 * 9; i++) {
        compute[i] = atanf(data[i]);
    }
}