void default_function_kernel(float* compute, float* data) {
    int num_blocks = 495 / 32; // Assuming the number of blocks is derived from the CUDA kernel code
    int num_threads_per_block = 32;

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads_per_block; ++thread_idx) {
            int idx = block_idx * num_threads_per_block + thread_idx;
            if (idx < 495) {
                compute[idx] = 0.000000e+00f;
            }
        }
    }

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads_per_block; ++thread_idx) {
            int idx = block_idx * num_threads_per_block + thread_idx;
            if (idx < 495) {
                for (int k = 0; k < 4; ++k) {
                    int data_idx = (block_idx * 32) + (thread_idx * 4) + k;
                    if (idx < 495 && data_idx < 495) {
                        compute[idx] += expf(data[data_idx] - compute[idx]);
                    }
                }
            }
        }
    }

    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        for (int thread_idx = 0; thread_idx < num_threads_per_block; ++thread_idx) {
            int idx = block_idx * num_threads_per_block + thread_idx;
            if (idx < 495) {
                for (int k = 0; k < 4; ++k) {
                    int data_idx = (block_idx * 32) + (thread_idx * 4) + k;
                    if (idx < 495 && data_idx < 495) {
                        compute[idx] = data[data_idx] - compute[idx] - logf(compute[idx]);
                    }
                }
            }
        }
    }
}