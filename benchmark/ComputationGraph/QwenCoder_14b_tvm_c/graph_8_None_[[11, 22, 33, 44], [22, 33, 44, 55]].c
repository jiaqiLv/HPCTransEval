void default_function_kernel(float* compute, float* ph, float* ph_1) {
    const int num_threads = 1024;
    const int num_blocks = 625;

    // Initialize compute array with zeros
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_blocks * num_threads; ++i) {
        compute[i] = 0.0f;
    }

    // Initialize T_strided_slice with -FLT_MAX
    float* T_strided_slice = (float*)malloc(num_blocks * num_threads * sizeof(float));
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_blocks * num_threads; ++i) {
        T_strided_slice[i] = -FLT_MAX;
    }

    // Compute T_strided_slice values
    #pragma omp parallel for collapse(2) num_threads(num_threads)
    for (int blockIdx = 0; blockIdx < num_blocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < num_threads; ++threadIdx) {
            if (((blockIdx * 64) + (threadIdx >> 4)) < 625) {
                int index = (blockIdx * 1024) + threadIdx;
                int ph_index = (((((blockIdx * 128) + (threadIdx >> 3)) / 125) * 31944) +
                                ((((((blockIdx * 6) + (threadIdx >> 2)) % 250) / 25) * 1452)) +
                                (((((((blockIdx * 12) + (threadIdx >> 1)) % 50) / 5) * 44)) +
                                (((blockIdx * 4) + threadIdx) % 10)) + 16973;
                T_strided_slice[index] = ph[ph_index];
            }
        }
    }

    // Compute T_strided_slice_1 values
    float* T_strided_slice_1 = (float*)malloc(num_blocks * num_threads * sizeof(float));
    #pragma omp parallel for collapse(2) num_threads(num_threads)
    for (int blockIdx = 0; blockIdx < num_blocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < num_threads; ++threadIdx) {
            if (((blockIdx * 64) + (threadIdx >> 4)) < 625) {
                int index = (blockIdx * 1024) + threadIdx;
                int ph_index = (((((blockIdx * 128) + (threadIdx >> 3)) / 125) * 79860) +
                                ((((((blockIdx * 6) + (threadIdx >> 2)) % 250) / 25) * 2420)) +
                                (((((((blockIdx * 12) + (threadIdx >> 1)) % 50) / 5) * 55)) +
                                (((blockIdx * 4) + threadIdx) % 10)) + 933559;
                T_strided_slice_1[index] = ph[ph_index];
            }
        }
    }

    // Compute T_strided_slice values again
    #pragma omp parallel for collapse(2) num_threads(num_threads)
    for (int blockIdx = 0; blockIdx < num_blocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < num_threads; ++threadIdx) {
            if (((blockIdx * 64) + (threadIdx >> 4)) < 625) {
                int index = (blockIdx * 1024) + threadIdx;
                int ph_index = (((((blockIdx * 128) + (threadIdx >> 3)) / 125) * 31944) +
                                ((((((blockIdx * 6) + (threadIdx >> 2)) % 250) / 25) * 1452)) +
                                (((((((blockIdx * 12) + (threadIdx >> 1)) % 50) / 5) * 44)) +
                                (((blockIdx * 4) + threadIdx) % 10)) + 16973;
                T_strided_slice[index] = ph[ph_index];
            }
        }
    }

    // Compute T_strided_slice_2 values
    float* T_strided_slice_2 = (float*)malloc(num_blocks * num_threads * sizeof(float));
    #pragma omp parallel for num_threads(num_threads)
    for (int threadIdx = 0; threadIdx < num_threads; ++threadIdx) {
        T_strided_slice_2[threadIdx] = -FLT_MAX;
        for (int k = 0; k < 10; ++k) {
            int index = (((threadIdx / 10) * 100) + (k * 10)) + (threadIdx % 10);
            T_strided_slice_2[threadIdx] = fmaxf(T_strided_slice_2[threadIdx], T_strided_slice_1[index]);
        }
    }

    // Compute compute values
    #pragma omp parallel for num_threads(num_threads)
    for (int threadIdx = 0; threadIdx < num_threads; ++threadIdx) {
        for (int k = 0; k < 10; ++k) {
            int index = (((threadIdx / 10) * 100) + (k * 10)) + (threadIdx % 10);
            compute[threadIdx] += expf(T_strided_slice[index] - T_strided_slice_2[threadIdx]);
        }
    }

    // Compute compute_1 values
    float* compute_1 = (float*)malloc(num_blocks * num_threads * sizeof(float));
    #pragma omp parallel for collapse(2) num_threads(num_threads)
    for (int blockIdx = 0; blockIdx < num_blocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < num_threads; ++threadIdx) {
            if (((blockIdx * 64) + (threadIdx >> 4)) < 625) {
                int index = (blockIdx * 1024) + threadIdx;
                int T_strided_slice_index = (((((blockIdx * 256) + (threadIdx >> 2)) / 25) * 10) + ((blockIdx * 4) + threadIdx) % 10);
                compute_1[index] = logf(compute[T_strided_slice_index]);
            }
        }
    }

    // Compute final compute values
    #pragma omp parallel for collapse(2) num_threads(num_threads)
    for (int blockIdx = 0; blockIdx < num_blocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < num_threads; ++threadIdx) {
            if (((blockIdx * 64) + (threadIdx >> 4)) < 625) {
                int index = (blockIdx * 1024) + threadIdx;
                int T_strided_slice_index = (((((blockIdx * 256) + (threadIdx >> 2)) / 25) * 10) + ((blockIdx * 4) + threadIdx) % 10);
                compute[index] = (T_strided_slice[index] - T_strided_slice_1[T_strided_slice_index]) - compute_1[index];
            }
        }
    }

    // Compute T_strided_slice_3 values
    float* T_strided_slice_3 = (float*)malloc(num_blocks * num_threads * sizeof(float));
    #pragma omp parallel for collapse(2) num_threads(num_threads)
    for (int blockIdx = 0; blockIdx < num_blocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < num_threads; ++threadIdx) {
            if (((blockIdx * 64) + (threadIdx >> 4)) < 625) {
                int index = (blockIdx * 1024) + threadIdx;
                T_strided_slice_3[index] = T_strided_slice[index] + T_strided_slice_1[index];
            }
        }
    }

    // Copy final results to compute array
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_blocks * num_threads; ++i) {
        compute[i] = T_strided_slice_3[i];
    }

    free(T_strided_slice);
    free(T_strided_slice_1);
    free(T_strided_slice_2);
    free(compute_1);
    free(T_strided_slice_3);
}