void default_function_kernel(float* compute, float* ph_0) {
    int total_elements = 11 * 2 * 8;
    #pragma omp parallel for
    for (int i = 0; i < total_elements; ++i) {
        compute[i] = atanhf((ph_0[i] / cosf(ph_0[i])));
    }
}