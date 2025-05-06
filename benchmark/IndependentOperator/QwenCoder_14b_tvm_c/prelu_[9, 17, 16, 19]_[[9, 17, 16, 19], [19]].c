void default_function_kernel(float* Scale, float* compute, float* data) {
    int total_elements = 9 * 17 * 16 * 19;
    #pragma omp parallel for
    for (int i = 0; i < total_elements; ++i) {
        compute[i] = (0.0f < data[i]) ? data[i] : (data[i] * Scale[i % 19]);
    }
}