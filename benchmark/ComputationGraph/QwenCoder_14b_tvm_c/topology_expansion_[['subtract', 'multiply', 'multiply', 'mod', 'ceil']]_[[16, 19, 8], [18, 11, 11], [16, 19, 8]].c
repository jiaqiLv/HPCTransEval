void default_function_kernel(float* T_mod, float* T_subtract, float* compute, float* ph_0, float* ph_3) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 19; ++j) {
            int idx = i * 19 + j;
            T_mod[idx] = fmodf((ph_0[idx] * (ph_0[idx] * ph_3[idx])), ph_0[idx]);
        }
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 11; ++j) {
            int idx = i * 11 + j;
            T_subtract[idx] = (ph_0[idx] - ph_3[idx]);
        }
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 19; ++j) {
            int idx = i * 19 + j;
            compute[idx] = ceilf((ph_0[idx] * (ph_0[idx] * ph_3[idx])));
        }
    }
}