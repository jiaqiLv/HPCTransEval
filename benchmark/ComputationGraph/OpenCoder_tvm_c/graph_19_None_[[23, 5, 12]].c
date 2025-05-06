void default_function_kernel(float* compute, float* ph) {
    int i;
    #pragma omp parallel for private(i)
    for (i = 0; i < 168; i++) {
        compute[i] = expf(ph[i]);
    }
}