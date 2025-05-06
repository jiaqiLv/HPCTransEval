#include <math.h>
#include <omp.h>

void default_function_kernel_2(float* __restrict__ T_batch_matmul_NN, float* __restrict__ ph_0, float* __restrict__ ph_6, int num_blocks) {
    #pragma omp parallel for
    for (int blockIdx_x = 0; blockIdx_x < num_blocks; ++blockIdx_x) {
        float T_batch_matmul_NN_local[2];
        for (int b_c_inner_init = 0; b_c_inner_init < 2; ++b_c_inner_init) {
            T_batch_matmul_NN_local[b_c_inner_init] = 0.000000e+00f;
        }
        for (int ax0_ax1_fused_ax2_fused_outer_outer = 0; ax0_ax1_fused_ax2_fused_outer_outer < 2; ++ax0_ax1_fused_ax2_fused_outer_outer) {
            if (((ax0_ax1_fused_ax2_fused_outer_outer * 4) + ((int)threadIdx.x / 10)) < 5) {
                int index = (((ax0_ax1_fused_ax2_fused_outer_outer * 40) + ((int)threadIdx.x)) + (blockIdx_x * 50));
                if (index < (num_blocks * 50)) {
                    ph_6[index] = ph_6_shared[index];
                }
            }
        }
        for (int k_inner = 0; k_inner < 5; ++k_inner) {
            for (int b_c_inner = 0; b_c_inner < 2; ++b_c_inner) {
                int index = (((b_c_inner * 25) + (k_inner * 5)) + (((int)threadIdx.x) % 5) + (blockIdx_x * 50));
                if (index < (num_blocks * 50)) {
                    T_batch_matmul_NN_local[b_c_inner] += (ph_0[((((blockIdx_x * 80) + (b_c_inner * 40)) + (((int)threadIdx.x) / 5) * 5) + k_inner)] * ph_6_shared[index]);
                }
            }
        }
        for (int b_inner = 0; b_inner < 2; ++b_inner) {
            int index = ((b_inner * 40) + ((int)threadIdx.x) + (blockIdx_x * 80));
            if (index < (num_blocks * 80)) {
                T_batch_matmul_NN[index] = T_batch_matmul_NN_local[b_inner];
            }
        }
    }
}

void default_function_kernel(float* __restrict__ compute, float* __restrict__ ph_0, int num_blocks) {
    #pragma omp parallel for
    for (int blockIdx_x = 0; blockIdx_x < num_blocks; ++blockIdx_x) {
        int index = (blockIdx_x * 32) + ((int)threadIdx.x);
        if (index < (num_blocks * 32)) {
            compute[index] = asinhf(fmodf(ph_0[index], ceilf(ph_0[index])));
        }
    }
}

void default_function_kernel_1(float* __restrict__ compute, float* __restrict__ ph_0, int num_blocks) {
    #pragma omp parallel for
    for (int blockIdx_x = 0; blockIdx_x < num_blocks; ++blockIdx_x) {
        int index = (blockIdx_x * 32) + ((int)threadIdx.x);
        if (index < (num_blocks * 32)) {
            compute[index] = atanf(ph_0[index]);
        }
    }
}