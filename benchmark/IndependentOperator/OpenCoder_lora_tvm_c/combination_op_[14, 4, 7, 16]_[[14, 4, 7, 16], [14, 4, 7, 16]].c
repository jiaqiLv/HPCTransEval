void default_function_kernel(float* T_add, float* data, float* data_1) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 7; k++) {
                for (int l = 0; l < 16; l++) {
                    T_add[((i * 4 + j) * 7 + k) * 16 + l] = sqrtf(data[((i * 4 + j) * 7 + k) * 16 + l]) + cosf(data_1[((i * 4 + j) * 7 + k) * 16 + l]);
                }
            }
        }
    }
}