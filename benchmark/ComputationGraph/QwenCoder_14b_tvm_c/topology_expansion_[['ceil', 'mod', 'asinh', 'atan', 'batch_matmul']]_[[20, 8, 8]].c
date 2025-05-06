void default_function_kernel(float* T_batch_matmul_NN, float* compute, float* ph_0) {
    const int num_blocks = 20;
    const int threads_per_block = 32;

    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < num_blocks; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < threads_per_block; ++threadIdx_x) {
            // Compute for default_function_kernel
            compute[(blockIdx_x * threads_per_block) + threadIdx_x] = asinhf(fmodf(ph_0[(blockIdx_x * threads_per_block) + threadIdx_x], ceilf(ph_0[(blockIdx_x * threads_per_block) + threadIdx_x])));
        }
    }

    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < num_blocks; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < threads_per_block; ++threadIdx_x) {
            // Compute for default_function_kernel_1
            compute[(blockIdx_x * threads_per_block) + threadIdx_x] = atanf(ph_0[(blockIdx_x * threads_per_block) + threadIdx_x]);
        }
    }

    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < num_blocks; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < threads_per_block; ++threadIdx_x) {
            // Compute for default_function_kernel_2
            float T_batch_matmul_NN_local[2] = {0.0f, 0.0f};
            float ph_6_shared[50];

            for (int ax0_ax1_fused_ax2_fused_outer_outer = 0; ax0_ax1_fused_ax2_fused_outer_outer < 2; ++ax0_ax1_fused_ax2_fused_outer_outer) {
                if (((ax0_ax1_fused_ax2_fused_outer_outer * 4) + (threadIdx_x / 10)) < 5) {
                    ph_6_shared[(ax0_ax1_fused_ax2_fused_outer_outer * 40) + threadIdx_x] = ph_0[((blockIdx_x * 80) + (ax0_ax1_fused_ax2_fused_outer_outer * 40) + threadIdx_x)];
                }
            }

            for (int k_inner = 0; k_inner < 5; ++k_inner) {
                for (int b_c_inner = 0; b_c_inner < 2; ++b_c_inner) {
                    T_batch_matmul_NN_local[b_c_inner] += ph_0[((blockIdx_x * 80) + (b_c_inner * 40) + ((threadIdx_x / 5) * 5) + k_inner)] * ph_6_shared[(b_c_inner * 25) + (k_inner * 5) + (threadIdx_x % 5)];
                }
            }

            for (int b_inner = 0; b_inner < 2; ++b_inner) {
                T_batch_matmul_NN[((blockIdx_x * 80) + (b_inner * 40) + threadIdx_x)] = T_batch_matmul_NN_local[b_inner];
            }
        }
    }
}