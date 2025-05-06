void default_function_kernel(float* T_add, float* compute, float* compute_1, float* compute_2, float* ph_0) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 9; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 32; threadIdx_x++) {
            int idx = (blockIdx_x * 32) + threadIdx_x;
            if (blockIdx_x * 4 + (threadIdx_x >> 3) < 9) {
                compute[idx] = fabsf(ph_0[idx]);
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 9; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 12; threadIdx_x++) {
            int idx = (blockIdx_x * 12) + threadIdx_x;
            compute_1[idx] = acosf(sinf(ph_0[idx]));
        }
    }

    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 9; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 16; threadIdx_x++) {
            int idx = (blockIdx_x * 16) + threadIdx_x;
            if (blockIdx_x * 2 + (threadIdx_x >> 3) < 9) {
                compute_2[idx] = expf(ph_0[idx]);
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 9; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 32; threadIdx_x++) {
            int idx = (blockIdx_x * 32) + threadIdx_x;
            if (blockIdx_x * 4 + (threadIdx_x >> 3) < 9) {
                T_add[idx] = acoshf(ph_0[idx]) + ph_0[idx];
            }
        }
    }
}