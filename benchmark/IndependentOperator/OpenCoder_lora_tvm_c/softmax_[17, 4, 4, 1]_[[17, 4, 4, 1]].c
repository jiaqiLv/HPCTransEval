void default_function_kernel_1(float* T_softmax_expsum, float* T_softmax_maxelem, float* data) {
    int i;
    #pragma omp parallel for private(i)
    for (i = 0; i < 17; i++) {
        T_softmax_expsum[i] = 0.000000e+00f;
    }
    #pragma omp parallel for private(i)
    for (i = 0; i < 17; i++) {
        T_softmax_expsum[i] = T_softmax_expsum[i] + exp(data[i] - T_softmax_maxelem[i]);
    }
}