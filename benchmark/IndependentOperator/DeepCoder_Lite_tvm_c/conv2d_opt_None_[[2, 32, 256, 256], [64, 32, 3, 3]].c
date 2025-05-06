#include <omp.h>
#include <stdio.h>

extern "C" void default_function_kernel(float* __restrict__ conv2d_nchw, float* __restrict__ data, float* __restrict__ kernel) {
    float conv2d_nchw_local[8];
    #pragma omp parallel for
    for (int yy_c_init = 0; yy_c_init < 2; ++yy_c_init) {
        conv2d_nchw_local[yy_c_init] = 0.000000e+00f;
        conv2d_nchw_local[(yy_c_init + 2)] = 0.000000e+00f;
        conv2d_nchw_local[(yy_c_init + 4)] = 0.000000e+00f;
        conv2d_nchw_local[(yy_c_init + 6)] = 0.000000e+00f;
    }
    for (int rc_outer = 0; rc_outer < 16; ++rc_outer) {
        for (int ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner = 0; ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner < 2; ++ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner) {
            int idx = (((((((((((int)blockIdx.z) >> 1) * 2097152) + (rc_outer * 131072)) + ((((int)threadIdx.z) >> 2) * 65536)) + (((int)blockIdx.y) * 512)) + ((((int)threadIdx.z) & 3) * 256)) + (((int)blockIdx.x) * 2)) + (((int)threadIdx.x) * 2)) + ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner);
            int idx_pad_temp_shared = ((((((int)threadIdx.z) * 4) + (((int)threadIdx.x) * 2)) + ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner);
            pad_temp_shared[idx_pad_temp_shared] = data[idx];
        }
        for (int ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner_1 = 0; ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner_1 < 36; ++ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner_1) {
            int idx_kernel_shared = ((((((((int)blockIdx.z) & 1) * 9216) + (((int)threadIdx.z) * 1152)) + (((int)threadIdx.x) * 576)) + ((ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner_1 / 18) * 288)) + (rc_outer * 18)) + (ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner_1 % 18);
            kernel_shared[(((((int)threadIdx.z) * 72) + (((int)threadIdx.x) * 36)) + ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner_1)] = kernel[idx_kernel_shared];
        }
        for (int rc_inner = 0; rc_inner < 2; ++rc_inner) {
            for (int ry_inner = 0; ry_inner < 3; ++ry_inner) {
                for (int rx_inner = 0; rx_inner < 3; ++rx_inner) {
                    for (int yy_c = 0; yy_c < 2; ++yy_c) {
                        int idx_pad_temp_shared_1 = ((((rc_inner * 16) + (yy_c * 4)) + (ry_inner * 4)) + ((int)threadIdx.x)) + rx_inner;
                        int idx_kernel_shared_1 = (((((int)threadIdx.z) * 18) + (rc_inner * 9)) + (ry_inner * 3)) + rx_inner;
                        conv2d_nchw_local[yy_c] += (pad_temp_shared[idx_pad_temp_shared_1] * kernel_shared[idx_kernel_shared_1]);
                        conv2d_nchw_local[(yy_c + 2)] += (pad_temp_shared[idx_pad_temp_shared_1] * kernel_shared[(idx_kernel_shared_1 + 144)]);
                        conv2d_nchw_local[(yy_c + 4)] += (pad_temp_shared[idx_pad_temp_shared_1] * kernel_shared[(idx_kernel_shared_1 + 288)]);
                        conv2d_nchw_local[(yy_c + 6)] += (pad_temp_shared[idx_pad_temp_shared_1] * kernel_shared[(idx_kernel_shared_1 + 432)]);
                    }
                }
            }
        }
    }
    for (int yy_inner_inner_inner = 0; yy_inner_inner_inner < 2; ++yy_inner_inner_inner) {
        int idx_conv2d_nchw = (((((((((int)blockIdx.z) * 2097152) + (((int)threadIdx.z) * 64516)) + (((int)blockIdx.y) * 508)) + (yy_inner_inner_inner * 254)) + (((int)blockIdx.x) * 2)) + ((int)threadIdx.x));
        conv2d_nchw[idx_conv2d_nchw] = conv2d_nchw_local[yy_inner_inner_inner];
        conv2d_nchw[(idx_conv2d_nchw + 516128)] = conv2d_nchw_local[(yy_inner_inner_inner + 2)];
        conv2d_nchw[(idx_conv2d_nchw + 1032256)] = conv2d_nchw_local[(yy_inner_inner_inner + 4)];
        conv2d_nchw[(idx_conv2d_nchw + 1548384)] = conv2d_nchw_local[(yy_inner_inner_inner + 6)];
    }
}