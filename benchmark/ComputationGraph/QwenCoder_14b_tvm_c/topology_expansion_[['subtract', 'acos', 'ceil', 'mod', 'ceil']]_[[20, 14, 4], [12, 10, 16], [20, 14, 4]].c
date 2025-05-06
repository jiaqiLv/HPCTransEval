void default_function_kernel(float* T_mod, float* T_subtract, float* compute, float* compute_1, float* ph_0, float* ph_3) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 9; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < 32; ++threadIdx_x) {
            int idx = (blockIdx_x * 32) + threadIdx_x;
            if (idx < 9 * 32) {
                T_mod[idx] = fmodf(ceilf(ph_0[idx]), ph_0[idx]);
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 9; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < 64; ++threadIdx_x) {
            int idx = (blockIdx_x * 64) + threadIdx_x;
            if (idx < 9 * 64) {
                compute[idx] = ceilf(ceilf(ph_0[idx]));
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 9; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < 8; ++threadIdx_x) {
            int idx = (blockIdx_x * 8) + threadIdx_x;
            if (idx < 9 * 8) {
                T_subtract[idx] = (ph_0[idx] - ph_3[idx]);
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 9; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < 32; ++threadIdx_x) {
            int idx = (blockIdx_x * 32) + threadIdx_x;
            if (idx < 9 * 32) {
                compute_1[idx] = acosf(ph_0[idx]);
            }
        }
    }
}