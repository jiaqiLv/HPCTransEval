void default_function_kernel(float* compute, float* data) {
    int total_elements = 7623;
    
    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        compute[i] = asinf(data[i]);
    }
}