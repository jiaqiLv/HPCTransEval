void default_function_kernel(float* compute, float* ph_0) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 15; j++) {
            for (int k = 0; k < 2; k++) {
                compute[((i * 15 + j) * 2 + k)] = fabsf(ph_0[((i * 15 + j) * 2 + k)]);
            }
        }
    }
}