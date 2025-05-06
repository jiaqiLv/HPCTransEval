void default_function_kernel(float* T_reshape, float* ph) {
    int num_blocks = (2541 + 1023) / 1024;
    int num_threads = 1024;

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = block_idx * num_threads + omp_get_thread_num(); thread_idx < (block_idx + 1) * num_threads && thread_idx < 2541; thread_idx += num_threads) {
            int idx = block_idx * 1024 + thread_idx;
            if (thread_idx < 2541) {
                T_reshape[idx] = ph[(((((((((block_idx * 256) + (thread_idx >> 2)) / 231) * 924) + (((((((block_idx * 50) + (thread_idx >> 1)) % 462) / 21) * 42)) + (((((((block_idx * 16) + (thread_idx)) % 42) / 7) * 7)) + (((((block_idx * 2) + (thread_idx)) % 7))))];
            }
        }
    }

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = block_idx * num_threads + omp_get_thread_num(); thread_idx < (block_idx + 1) * num_threads && thread_idx < 2541; thread_idx += num_threads) {
            int idx = block_idx * 1024 + thread_idx;
            if (thread_idx < 2541) {
                T_reshape[idx] = T_reshape[idx] - T_softmax_maxelem[(((((block_idx * 512) + ((thread_idx >> 1) % 512)) / 21))];
            }
        }
    }

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = block_idx * num_threads + omp_get_thread_num(); thread_idx < (block_idx + 1) * num_threads && thread_idx < 2541; thread_idx += num_threads) {
            int idx = block_idx * 1024 + thread_idx;
            if (thread_idx < 2541) {
                T_reshape[idx] = exp(T_reshape[idx]);
            }
        }
    }

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = block_idx * num_threads + omp_get_thread_num(); thread_idx < (block_idx + 1) * num_threads && thread_idx < 2541; thread_idx += num_threads) {
            int idx = block_idx * 1024 + thread_idx;
            if (thread_idx < 2541) {
                float sum = 0.0f;
                for (int k = 0; k < 42; ++k) {
                    sum += T_reshape[((((block_idx * 1024) + (thread_idx)) * 42) + k)];
                }
                T_reshape[idx] /= sum;
            }
        }
    }
}