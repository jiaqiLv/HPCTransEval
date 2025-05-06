#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* __restrict__ T_transpose, float* __restrict__ ph, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_ax3_fused_outer < 2; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
        int idx = ((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 32768) + (((int)blockIdx.x) * 128)) + (((int)threadIdx.x) >> 3);
        if (idx < 43923) {
            int base_idx = ((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x);
            if (ax0_ax1_fused_ax2_fused_ax3_fused_outer == 0) {
                T_transpose[base_idx] = ph[((((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 32768) + (((int)blockIdx.x) * 128)) + (((int)threadIdx.x) >> 3)) / 3993) * 31944) + ((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 65536) + (((int)blockIdx.x) * 256)) + (((int)threadIdx.x) >> 2)) % 242) / 11) * 1452)) + ((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 32768) + (((int)blockIdx.x) * 128)) + (((int)threadIdx.x) >> 3)) % 3993) / 121) * 44)) + ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x)) % 44))];
            } else {
                T_transpose[base_idx] = T_transpose_1[(((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))];
            }
        }
    }
}