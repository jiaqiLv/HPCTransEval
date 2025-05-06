#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* __restrict__ T_transpose, float* __restrict__ ph) {
    #pragma omp parallel for
    for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 2; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
        for (int i = ((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 32768) + (((int)blockIdx.x) * 128)) + (((int)threadIdx.x) >> 3); i < (((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 32768) + (((int)blockIdx.x) * 128)) + (((int)threadIdx.x) >> 3) + 1); i++) {
            if (i < 43923) {
                T_transpose[(((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] = ph[((((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 32768) + (((int)blockIdx.x) * 128)) + (((int)threadIdx.x) >> 3)) / 3993) * 31944) + ((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 65536) + (((int)blockIdx.x) * 256)) + (((int)threadIdx.x) >> 2)) % 242) / 11) * 1452)) + ((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 32768) + (((int)blockIdx.x) * 128)) + (((int)threadIdx.x) >> 3)) % 3993) / 121) * 44)) + ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x)) % 44))];
            }
        }
    }
}