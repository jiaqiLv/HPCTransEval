void default_function_kernel(float* compute, float* compute_1, float* data, float* data_1) {
    int total_elements = 4 * 17 * 12 * 17;
    
    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        compute[i] = cosf(data[i] + data_1[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        compute_1[i] = sqrtf(data[i] + data_1[i]);
    }
}