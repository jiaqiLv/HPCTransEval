void default_function_kernel(float* T_softmax_norm, float* ph) {
    const int num_blocks = 625;
    const int threads_per_block = 1024;

    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < num_blocks; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < threads_per_block; ++threadIdx_x) {
            int idx = (blockIdx_x * threads_per_block) + threadIdx_x;

            if (idx < 625 * 1024) {
                // default_function_kernel_1
                ph[idx] += 3.000000e+00f;

                // default_function_kernel_2
                ph[idx] *= 7.692308e-02f;

                // default_function_kernel_3
                ph[idx] = (0.000000e+00f < ph[idx]) ? ph[idx] : (ph[idx] * 5.000000e-01f);

                // default_function_kernel_4
                int max_idx = (blockIdx_x * 1024) + threadIdx_x;
                float max_val = -3.402823e+38f;
                for (int k = 0; k < 16; ++k) {
                    int temp_idx = (((blockIdx_x * 256) + (threadIdx_x >> 2)) / 625) * 40000 + (k * 2500) + (max_idx % 2500);
                    max_val = fmax(max_val, ph[temp_idx]);
                }
                ph[max_idx] = max_val;

                // default_function_kernel_5
                int maxelem_idx = (((blockIdx_x * 16) + (threadIdx_x >> 6)) / 625) * 2500 + (idx % 2500);
                ph[idx] -= T_softmax_norm[maxelem_idx];

                // default_function_kernel_6
                int v_ = ((int)(floorf(((fmax(fmin(ph[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
                ph[idx] = fmax(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (fmax(fmin(ph[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmax(fmin(ph[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (fmax(fmin(ph[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmax(fmin(ph[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (fmax(fmin(ph[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmax(fmin(ph[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (fmax(fmin(ph[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmax(fmin(ph[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (fmax(fmin(ph[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmax(fmin(ph[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (fmax(fmin(ph[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmax(fmin(ph[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (fmax(fmin(ph[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmax(fmin(ph[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (fmax(fmin(ph[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmax(fmin(ph[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), ph[idx]);

                // default_function_kernel_7
                float sum_val = 0.0f;
                for (int k = 0; k < 16; ++k) {
                    int temp_idx = (((blockIdx_x * 256) + (threadIdx_x >> 2)) / 625) * 40000 + (k * 2500) + (idx % 2500);
                    sum_val += ph[temp_idx];
                }
                ph[idx] = sum_val;

                // default_function_kernel_8
                T_softmax_norm[idx] = ph[idx] / T_softmax_norm[maxelem_idx];
            }
        }
    }
}