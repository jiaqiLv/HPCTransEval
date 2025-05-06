void default_function_kernel(float* T_reverse_sequence, float* data) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            int idx = (i * 13) + j;
            int src_idx = (((i & 7) * 13) + j + 312) - ((i >> 3) * 104);
            T_reverse_sequence[idx] = data[src_idx];
        }
    }
}