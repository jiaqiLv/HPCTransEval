void default_function_kernel(float* T_reverse_sequence, float* compute, float* ph, float* ph_1) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int idx = i * 10 + j;
            T_reverse_sequence[idx] = ph[idx];
            compute[idx] = atan(T_reverse_sequence[idx]);
        }
    }
}