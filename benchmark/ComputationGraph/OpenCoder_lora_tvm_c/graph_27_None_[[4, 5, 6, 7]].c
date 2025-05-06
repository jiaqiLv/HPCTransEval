void default_function_kernel(float* T_reshape, float* ph) {
    int i;
    #pragma omp parallel for
    for (i = 0; i < 840; i++) {
        T_reshape[i] = ph[i];
    }
}