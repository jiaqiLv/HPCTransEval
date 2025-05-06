void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for
    for (int i < 18 * 9 * 3 * 11; i++) {
        compute[i] = atanhf(data[i]) {