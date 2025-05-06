void default_function_kernel(float* compute, float* ph) {
    #pragma omp parallel for
    for (int i = 0; i < 168; i++) {
        compute[i] = expf(ph[i]);
    }
}