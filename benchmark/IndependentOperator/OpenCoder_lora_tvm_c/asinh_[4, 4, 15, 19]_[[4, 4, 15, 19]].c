void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for
    for (int i = 0; i < 80; i++) {
        compute[i] = asinh(data[i]);