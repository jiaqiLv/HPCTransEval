void default_function_kernel(float* compute, float* data) {
    int total_elements = 143 * 32; // 11 * 8 * 1 * 13

    #pragma omp parallel for
    for (int i = 0; i < total_elements; ++i) {
        compute[i] = log2f(data[i]);
    }
}