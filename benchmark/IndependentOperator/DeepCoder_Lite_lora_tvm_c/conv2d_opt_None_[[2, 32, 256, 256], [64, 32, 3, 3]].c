#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

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
      int pad_temp_shared_access_address = ((((((int)omp_get_thread_num()) * 16) + (((int)omp_get_thread_num()) * 2)) + ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner) % 1024);
      pad_temp_shared[pad_temp_shared_access_address] = data[(((((((((((int)omp_get_thread_num()) / 16) * 2097152) + (rc_outer * 131072)) + ((((int)omp_get_thread_num()) % 16) * 8192)) + (((int)omp_get_thread_num()) / 16) * 512) + ((((int)omp_get_thread_num()) % 16) * 256)) + (((int)omp_get_thread_num()) / 16) * 2) + ((int)omp_get_thread_num()) % 16)];
    }
    for (int ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner_1 = 0; ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner_1 < 36; ++ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner_1) {
      int kernel_shared_access_address = (((((((int)omp_get_thread_num()) * 18) + (((int)omp_get_thread_num()) * 36)) + ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner_1) % 1024);
      kernel_shared[kernel_shared_access_address] = kernel[(((((((((int)omp_get_thread_num()) / 16) & 1) * 9216) + (((int)omp_get_thread_num()) / 16) * 1152) + (((int)omp_get_thread_num()) % 16) * 576) + ((ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner_1 / 18) * 288) + (rc_outer * 18)) + (ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner_1 % 18))];
    }
    for (int rc_inner = 0; rc_inner < 2; ++rc_inner) {
      for (int ry_inner = 0; ry_inner < 3; ++ry_inner) {
        for (int rx_inner = 0; rx_inner < 3; ++rx_inner) {
          for (int yy_c = 0; yy_c < 2; ++yy_c) {
            int conv2d_nchw_local_access_address = ((((rc_inner * 16) + (yy_c * 4)) + (ry_inner * 4)) + ((int)omp_get_thread_num()) % 16);
            conv2d_nchw_local[yy_c] += (pad_temp_shared[conv2d_nchw_local_access_address] * kernel_shared[((((((int)omp_get_thread_num()) * 18) + (rc_inner * 9)) + (ry_inner * 3)) + rx_inner)]);
            conv2d_nchw_local[(yy_c + 2)] += (pad_temp_shared[conv2d_nchw_local_access_address] * kernel_shared[(((((((int)omp_get_thread_num()) * 18) + (rc_inner * 9)) + (ry_inner * 3)) + rx_inner) + 144)]);
            conv2d_nchw_local[(yy_c + 4)] += (pad_temp_shared[conv2d_nchw_local_access_address] * kernel_shared[(((((((int)omp_get_thread_num()) * 18) + (rc_inner * 9)) + (ry_inner * 3)) + rx_inner) + 288)]);
            conv2d_nchw_local[(yy_c + 6)] += (pad_temp_shared[conv2d_nchw_local_access_address] * kernel_shared[(((((((int)omp_get_thread_num()) * 18) + (rc_inner * 9)) + (ry_inner * 3)) + rx_inner) + 432)]);
          }
        }
      }
    }
  }
  for (int yy_inner_inner_inner = 0; yy_inner_inner_inner < 2; ++yy_inner_inner_inner) {
    int conv2d_nchw_access_address = (((((((int)omp_get_thread_num()) * 2064512) + (((int)omp_get_thread_num()) * 64516)) + (((int)omp_get_thread_num()) * 508)) + (yy_inner_inner_inner * 254)) + (((int)omp_get_thread_num()) * 2) % 1024;
    conv2d_nchw[conv2d_nchw_access_address] = conv2d_nchw_local[yy_inner_inner_inner];
    conv2d_nchw[conv2d_nchw_access_address + 516128] = conv2d_nchw_local[(yy_inner_inner_inner + 2)];
    conv2d_nchw[conv2d_nchw_access_address + 1032256] = conv2d_nchw_local[(yy_inner_inner_inner + 4)];
    conv2d_nchw[conv2d_nchw_access_address + 1548384] = conv2d_nchw_local[(yy_inner_inner_inner + 6)];
  }
}