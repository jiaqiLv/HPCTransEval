void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for
    for (int i = 0; i < 374; ++i) {
        compute[i] = roundf(data[i]);
    }
}