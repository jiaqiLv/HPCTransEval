void default_function_kernel(float* T_softmax_norm, float* ph, float* resize, int num_blocks, int threads_per_block) {
    // Assuming num_blocks and threads_per_block are known and appropriate for the given input shape
    omp_set_num_threads(omp_get_max_threads());

    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int idx = b * threads_per_block + t;
            if (((b * 4) + (t >> 8)) < 625) {
                resize[idx] = (resize[idx] - T_softmax_maxelem[((b * 16) + (t >> 6)) / 625 * 2500 + (idx % 1024)]);
            }
        }
    }

    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int idx = b * threads_per_block + t;
            if (((b * 4) + (t >> 8)) < 625) {
                int v_ = ((int)(floorf(((max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
                resize[idx] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), resize[idx]);
            }
        }
    }

    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int idx = b * threads_per_block + t;
            if (((b * 4) + (t >> 8)) < 625) {
                T_softmax_norm[idx] = (resize[idx] / T_softmax_maxelem[((b * 16) + (t >> 6)) / 625 * 2500 + (idx % 1024)]));
            }
        }
    }
}