void default_function_kernel(float* T_softmax_norm, float* ph, float* ph_1) {
    #pragma omp parallel for
    for (int i = 0; i < 3105; ++i) {
        T_softmax_norm[i] = ph[i] / ph_1[i];
    }
}