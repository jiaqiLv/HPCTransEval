void default_function_kernel(float* compute, float* ph, float* ph_1) {
    int num_blocks = 625; // Assuming the number of blocks is fixed based on the CUDA kernel code
    int num_threads_per_block = 1024;

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads_per_block; ++thread_idx) {
            int index = block_idx * num_threads_per_block + thread_idx;
            if (index < 625) {
                compute[index] = ph[((((((((((block_idx * 128) + (thread_idx >> 3)) / 125) * 31944) + (((((((block_idx * 6) + (thread_idx >> 2)) % 250) / 25) * 1452)) + (((((((block_idx * 12) + (thread_idx >> 1)) % 50) / 5) * 44)) + ((((block_idx * 4) + thread_idx) % 10)) + 16973)))]);
            }
        }
    }

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads_per_block; ++thread_idx) {
            int index = block_idx * num_threads_per_block + thread_idx;
            if (index < 625) {
                int v_ = ((int)(floorf((max(min(compute[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f) << 23;
                compute[index] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(compute[index], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(compute[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(compute[index], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(compute[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(compute[index], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(compute[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(compute[index], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(compute[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(compute[index], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(compute[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(compute[index], 8.837627e+01f), -8.837626e+01f) - (floorf((max(min(compute[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), compute[index]);
            }
        }
    }

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads_per_block; ++thread_idx) {
            int index = block_idx * num_threads_per_block + thread_idx;
            if (index < 625) {
                compute[index] = ph_1[((((((((((block_idx * 128) + (thread_idx >> 3)) / 125) * 79860) + (((((((block_idx * 6) + (thread_idx >> 2)) % 250) / 25) * 2420)) + (((((((block_idx * 12) + (thread_idx >> 1)) % 50) / 5) * 55)) + ((((block_idx * 4) + thread_idx) % 10)) + 933559)))];
            }
        }
    }

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads_per_block; ++thread_idx) {
            int index = block_idx * num_threads_per_block + thread_idx;
            if (index < 625) {
                compute[index] = compute[index] * ph[((((((((((block_idx * 128) + (thread_idx >> 3)) / 125) * 31944) + (((((((block_idx * 6) + (thread_idx >> 2)) % 250) / 25) * 1452)) + (((((((block_idx * 12) + (thread_idx >> 1)) % 50) / 5) * 44)) + ((((block_idx * 4) + thread_idx) % 10)) + 16973)))];
            }
        }
    }

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads_per_block; ++thread_idx) {
            int index = block_idx * num_threads_per_block + thread_idx;
            if (index < 625) {
                compute[index] = __expf(compute[index]);
            }
        }
    }
}