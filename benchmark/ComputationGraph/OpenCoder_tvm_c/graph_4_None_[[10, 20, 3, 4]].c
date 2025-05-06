void default_function_kernel(float* T_reshape, float* ph) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 45; i++) {
        for (int j = 0; j < 1024; j++) {
            T_reshape[i * 1024 + j] = ph[(((((((((i * 64) + (j >> 4)) / 15) * 240) + (((((((i * 16) + (j >> 2)) % 60) / 3) * 12)) + (((((i * 2) + (j >> 1)) % 30) * 2)) + (j & 1))) * 4)) + (j & 3))];
        }
    }
}