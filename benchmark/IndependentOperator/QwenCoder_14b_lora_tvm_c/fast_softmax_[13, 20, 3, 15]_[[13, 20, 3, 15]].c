void default_function_kernel(float* T_softmax_norm, float* data) {
    const int num_blocks = 195;
    const int threads_per_block = 64;

    #pragma omp parallel for collapse(2)
    for (int blockIdx = 0; blockIdx < num_blocks; blockIdx++) {
        for (int threadIdx = 0; threadIdx < threads_per_block; threadIdx++) {
            int idx = (blockIdx * threads_per_block) + threadIdx;
            if (idx < 195) {
                T_softmax_norm[idx] = -3.402823e+38f;
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int blockIdx = 0; blockIdx < num_blocks; blockIdx++) {
        for (int threadIdx = 0; threadIdx < threads_per_block; threadIdx++) {
            int idx = (blockIdx * threads_per_block) + threadIdx;
            if (idx < 195) {
                for (int k = 0; k < 15; ++k) {
                    T_softmax_norm[idx] = fmaxf(T_softmax_norm[idx], data[(blockIdx * 960) + (threadIdx * 15) + k]);
                }
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int blockIdx = 0; blockIdx < num_blocks; blockIdx++) {
        for (int threadIdx = 0; threadIdx < threads_per_block; threadIdx++) {
            int idx = (blockIdx * threads_per_block) + threadIdx;
            if (idx < 195) {
                T_softmax_norm[idx] = 0.000000e+00f;
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int blockIdx = 0; blockIdx < num_blocks; blockIdx++) {
        for (int threadIdx = 0; threadIdx < threads_per_block; threadIdx++) {
            int idx = (blockIdx * threads_per_block) + threadIdx;
            if (idx < 195) {
                for (int k = 0; k < 15; ++k) {
                    float diff = data[(blockIdx * 960) + (threadIdx * 15) + k] - T_softmax_norm[idx];
                    float exp_diff = fmaxf(fminf(diff, 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f + 5.000000e-01f;
                    int v_ = ((int)(floorf(exp_diff) + 1.270000e+02f)) << 23;
                    float exp_value = (*(float *)&v_);
                    float poly = exp_value * (
                        1.987569e-04f * (exp_diff - floorf(exp_diff)) +
                        1.398200e-03f * (exp_diff - floorf(exp_diff)) +
                        8.333452e-03f * (exp_diff - floorf(exp_diff)) +
                        4.166580e-02f * (exp_diff - floorf(exp_diff)) +
                        1.666667e-01f * (exp_diff - floorf(exp_diff)) +
                        5.000000e-01f * (exp_diff - floorf(exp_diff))
                    ) + exp_value;
                    T_softmax_norm[idx] += poly * diff;
                }
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int blockIdx = 0; blockIdx < num_blocks; blockIdx++) {
        for (int threadIdx = 0; threadIdx < threads_per_block; threadIdx++) {
            int idx = (blockIdx * threads_per_block) + threadIdx;
            if (idx < 195) {
                float diff = data[idx] - T_softmax_norm[idx];
                float exp_diff = fmaxf(fminf(diff, 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f + 5.000000e-01f;
                int v_ = ((int)(floorf(exp_diff) + 1.270000e+02f)) << 23;
                float exp_value = (*(float *)&v_);
                float poly = exp_value * (
                    1.987569e-04f * (exp_diff - floorf(exp_diff)) +
                    1.398200e-03f * (exp_diff - floorf(exp_diff)) +
                    8.333452e-03f * (exp_diff - floorf(exp_diff)) +
                    4.166580e-02f * (exp_diff - floorf(exp_diff)) +
                    1.666667e-01f * (exp_diff - floorf(exp_diff)) +
                    5.000000e-01f * (exp_diff - floorf(exp_diff))
                ) + exp_value;
                T_softmax_norm[idx] = (poly * diff) / T_softmax_norm[idx];
            }
        }
    }
}