void default_function_kernel(float* T_softmax_norm, float* ph) {
    int num_blocks = 1; // Assuming the number of blocks is 1 as per the input shape
    int threads_per_block = 1024;

    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * 1024 + t;
            if (index < 11979) {
                T_softmax_norm[index] = sqrtf(T_softmax_norm[index]);
            }
        }
    }

    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * 1024 + t;
            if (index < 3993) {
                T_softmax_norm[index] = ph[(b * 1024 + t) % 1452];
            }
        }
    }

    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * 1024 + t;
            if (index < 11979) {
                T_softmax_norm[index] = T_softmax_norm[index] - T_softmax_norm[((b * 1024 + t) % 1452)];
            }
        }
    }

    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * 1024 + t;
            if (index < 1089) {
                T_softmax_norm[index] = 0.000000e+00f;
            }
            for (int k = 0; k < 11; ++k) {
                int inner_index = ((k * 17424) + (b * 1024 + t)) % 11979;
                if (inner_index < 11979) {
                    T_softmax_norm[index] += T_softmax_norm[inner_index];
                }
            }
        }
    }

    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * 1024 + t;
            if (index < 11979) {
                T_softmax_norm[index] = T_softmax_norm[index] / T_softmax_norm[((b * 1024 + t) % 1452)];
            }
        }
    }

    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * 1024 + t;
            if (index < 11979) {
                int v_ = ((int)(floorf(((max(min(T_softmax_norm[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
                T_softmax_norm[index] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(T_softmax_norm[index], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_softmax_norm[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(T_softmax_norm[index], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_softmax_norm[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(T_softmax_norm[index], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_softmax_norm[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(T_softmax_norm[index], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_softmax_norm[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(T_softmax_norm[index], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_softmax_norm[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(T_softmax_norm[index], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_softmax_norm[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), T_softmax_norm[index]);
            }
        }
    }
}