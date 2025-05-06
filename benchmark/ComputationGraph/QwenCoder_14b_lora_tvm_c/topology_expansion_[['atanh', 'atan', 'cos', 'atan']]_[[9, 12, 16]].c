void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* ph_0) {
    int size = 9 * 12 * 16;
    
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        compute[i] = atanhf(ph_0[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        compute_1[i] = cosf(atanf(ph_0[i]));
    }

    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        compute_2[i] = atanf(ph_0[i]);
    }
}