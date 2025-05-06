void default_function_kernel(float* T_fast_exp, float* ph, float* ph_1) {
    int num_blocks = 625; // Assuming the number of blocks is fixed based on the CUDA kernel code
    int threads_per_block = 1024;

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < threads_per_block; ++thread_idx) {
            if (((block_idx * threads_per_block) + thread_idx) < 625) {
                int index = (block_idx * threads_per_block) + thread_idx;
                T_fast_exp[index] = ph[((((((((block_idx * 128) + (thread_idx >> 3)) / 125) * 79860) + (((((((block_idx * 6) + (thread_idx >> 2)) % 250) / 25) * 2420)) + (((((((block_idx * 12) + (thread_idx >> 1)) % 50) / 5) * 55)) + ((((block_idx * 4) + thread_idx) % 10)) + 933559))];
            }
        }
    }

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < threads_per_block; ++thread_idx) {
            if (((block_idx * threads_per_block) + thread_idx) < 625) {
                int index = (block_idx * threads_per_block) + thread_idx;
                int v_ = (int)(floorf(max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f + 5.000000e-01f)) << 23;
                T_fast_exp[index] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-02f) * (max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f + 5.000000e-01f)) * 6.931472e-01f))) * (max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), T_fast_exp[index]);
            }
        }
    }

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < threads_per_block; ++thread_idx) {
            if (((block_idx * threads_per_block) + thread_idx) < 625) {
                int index = (block_idx * threads_per_block) + thread_idx;
                T_fast_exp[index] = ph[((((((((block_idx * 128) + (thread_idx >> 3)) / 125) * 31944) + (((((((block_idx * 6) + (thread_idx >> 2)) % 250) / 25) * 1452)) + (((((((block_idx * 12) + (thread_idx >> 1)) % 50) / 5) * 44)) + ((((block_idx * 4) + thread_idx) % 10)) + 16973))];
            }
        }
    }

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < threads_per_block; ++thread_idx) {
            if (((block_idx * threads_per_block) + thread_idx) < 625) {
                int index = (block_idx * threads_per_block) + thread_idx;
                T_fast_exp[index] = T_fast_exp[index] * T_strided_slice_1[index];
            }
        }
    }
}