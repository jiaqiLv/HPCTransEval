void default_function_kernel(float* T_add, float* compute, float* ph_0, float* ph_3) {
    // First kernel: compute = atanf(ph_0)
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 14; ++j) {
            for (int k = 0; k < 4; ++k) {
                int idx = i * 14 * 4 + j * 4 + k;
                compute[idx] = atanf(ph_0[idx]);
            }
        }
    }

    // Second kernel: T_add = ph_0 + ph_3
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 17; ++j) {
            for (int k = 0; k < 6; ++k) {
                int idx = i * 17 * 6 + j * 6 + k;
                T_add[idx] = ph_0[idx] + ph_3[idx];
            }
        }
    }
}