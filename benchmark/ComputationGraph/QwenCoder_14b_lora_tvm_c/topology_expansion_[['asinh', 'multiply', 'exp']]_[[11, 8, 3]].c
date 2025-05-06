void default_function_kernel(float* compute, float* ph_0) {
    int total_elements = 11 * 8 * 3;
    
    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        compute[i] = expf(ph_0[i] * asinhf(ph_0[i]));
    }
}