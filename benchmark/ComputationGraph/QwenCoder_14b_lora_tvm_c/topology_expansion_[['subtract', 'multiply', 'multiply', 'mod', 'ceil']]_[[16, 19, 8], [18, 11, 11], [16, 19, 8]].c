void default_function_kernel(float* T_mod, float* T_subtract, float* compute, float* ph_0, float* ph_3) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 19; ++j) {
            int idx = i * 19 + j;
            T_mod[idx] = fmodf((ph_0[idx] * (ph_0[idx] * ph_3[idx])), ph_0[idx]);
            T_subtract[idx] = (ph_0[idx] - ph_3[idx]);
            compute[idx] = ceilf((ph_0[idx] * (ph_0[idx] * ph_3[idx])));
        }
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 18; ++i) {
        for (int j = 0; j < 11; ++j) {
            int idx = i * 11 + j;
            T_mod[16 * 19 + idx] = fmodf((ph_0[16 * 19 + idx] * (ph_0[16 * 19 + idx] * ph_3[16 * 19 + idx])), ph_0[16 * 19 + idx]);
            T_subtract[16 * 19 + idx] = (ph_0[16 * 19 + idx] - ph_3[16 * 19 + idx]);
            compute[16 * 19 + idx] = ceilf((ph_0[16 * 19 + idx] * (ph_0[16 * 19 + idx] * ph_3[16 * 19 + idx])));
        }
    }
}