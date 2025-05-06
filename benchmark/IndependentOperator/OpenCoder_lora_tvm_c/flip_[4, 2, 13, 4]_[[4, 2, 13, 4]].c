void default_function_kernel(float* T_reverse_sequence, float* data) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 13; k++) {
                for (int l = 0; l < 4; l++) {
                    T_reverse_sequence[((i * 2 + j) * 13 + k) * 4 + l] = data[((((i & 7) * 13 + k) + 312) - ((i >> 3) * 104)) * 4 + l];
                }
            }
        }
    }
}