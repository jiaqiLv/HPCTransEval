void default_function_kernel(float* compute, float* ph, float* ph_1) {
    int num_blocks = 10; // Assuming the number of blocks is derived from the input shape
    int num_threads_per_block = 1024;

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads_per_block; ++thread_idx) {
            int idx = block_idx * 1024 + thread_idx;
            if (idx < 625) {
                compute[idx] = ph[((((((((((block_idx * 128) + (thread_idx >> 3)) / 125) * 31944) + (((((((block_idx * 6) + (thread_idx >> 2)) % 250) / 25) * 1452)) + (((((((block_idx * 12) + (thread_idx >> 1)) % 50) / 5) * 44)) + ((block_idx * 4) + thread_idx)) + 16973))];
            }
        }
    }

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads_per_block; ++thread_idx) {
            int idx = block_idx * 1024 + thread_idx;
            if (idx < 625) {
                int v_ = ((int)(floorf((max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f) << 23;
                compute[idx] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), compute[idx]);
            }
        }
    }

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads_per_block; ++thread_idx) {
            int idx = block_idx * 1024 + thread_idx;
            if (idx < 625) {
                compute[idx] = ph_1[((((((((((block_idx * 128) + (thread_idx >> 3)) / 125) * 79860) + (((((((block_idx * 6) + (thread_idx >> 2)) % 250) / 25) * 2420)) + (((((((block_idx * 12) + (thread_idx >> 1)) % 50) / 5) * 55)) + ((block_idx * 4) + thread_idx)) + 933559))];
            }
        }
    }

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads_per_block; ++thread_idx) {
            int idx = block_idx * 1024 + thread_idx;
            if (idx < 625) {
                compute[idx] = compute[idx] * ph[((((((((((block_idx * 128) + (thread_idx >> 3)) / 125) * 79860) + (((((((block_idx * 6) + (thread_idx >> 2)) % 250) / 25) * 2420)) + (((((((block_idx * 12) + (thread_idx >> 1)) % 50) / 5) * 55)) + ((block_idx * 4) + thread_idx)) + 933559))];
            }
        }
    }

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads_per_block; ++thread_idx) {
            int idx = block_idx * 1024 + thread_idx;
            if (idx < 625) {
                compute[idx] = __expf(compute[idx]);
            }
        }
    }
}