void default_function_kernel(float* T_softmax_norm, float* ph, float* ph_1) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 23; i++) {
        for (int j = 0; j < 45; j++) {
            T_softmax_norm[i * 45 + j] = ph[(i * 540 + j) / 23 * 12 + (i * 540 + j) % 23] / ph_1[i * 540 + j];
        }
    }
}