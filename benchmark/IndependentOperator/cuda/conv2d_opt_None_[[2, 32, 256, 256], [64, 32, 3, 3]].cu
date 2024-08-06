extern "C" __global__ void __launch_bounds__(16) default_function_kernel(float* __restrict__ conv2d_nchw, float* __restrict__ data, float* __restrict__ kernel) {
  float conv2d_nchw_local[8];
  __shared__ float pad_temp_shared[32];
  __shared__ float kernel_shared[576];
  for (int yy_c_init = 0; yy_c_init < 2; ++yy_c_init) {
    conv2d_nchw_local[yy_c_init] = 0.000000e+00f;
    conv2d_nchw_local[(yy_c_init + 2)] = 0.000000e+00f;
    conv2d_nchw_local[(yy_c_init + 4)] = 0.000000e+00f;
    conv2d_nchw_local[(yy_c_init + 6)] = 0.000000e+00f;
  }
  for (int rc_outer = 0; rc_outer < 16; ++rc_outer) {
    __syncthreads();
    for (int ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner = 0; ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner < 2; ++ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner) {
      pad_temp_shared[(((((int)threadIdx.z) * 4) + (((int)threadIdx.x) * 2)) + ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner)] = data[(((((((((((int)blockIdx.z) >> 1) * 2097152) + (rc_outer * 131072)) + ((((int)threadIdx.z) >> 2) * 65536)) + (((int)blockIdx.y) * 512)) + ((((int)threadIdx.z) & 3) * 256)) + (((int)blockIdx.x) * 2)) + (((int)threadIdx.x) * 2)) + ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner)];
    }
    for (int ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner_1 = 0; ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner_1 < 36; ++ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner_1) {
      kernel_shared[(((((int)threadIdx.z) * 72) + (((int)threadIdx.x) * 36)) + ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner_1)] = kernel[(((((((((int)blockIdx.z) & 1) * 9216) + (((int)threadIdx.z) * 1152)) + (((int)threadIdx.x) * 576)) + ((ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner_1 / 18) * 288)) + (rc_outer * 18)) + (ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner_1 % 18))];
    }
    __syncthreads();
    for (int rc_inner = 0; rc_inner < 2; ++rc_inner) {
      for (int ry_inner = 0; ry_inner < 3; ++ry_inner) {
        for (int rx_inner = 0; rx_inner < 3; ++rx_inner) {
          for (int yy_c = 0; yy_c < 2; ++yy_c) {
            conv2d_nchw_local[yy_c] = (conv2d_nchw_local[yy_c] + (pad_temp_shared[(((((rc_inner * 16) + (yy_c * 4)) + (ry_inner * 4)) + ((int)threadIdx.x)) + rx_inner)] * kernel_shared[((((((int)threadIdx.z) * 18) + (rc_inner * 9)) + (ry_inner * 3)) + rx_inner)]));
            conv2d_nchw_local[(yy_c + 2)] = (conv2d_nchw_local[(yy_c + 2)] + (pad_temp_shared[(((((rc_inner * 16) + (yy_c * 4)) + (ry_inner * 4)) + ((int)threadIdx.x)) + rx_inner)] * kernel_shared[(((((((int)threadIdx.z) * 18) + (rc_inner * 9)) + (ry_inner * 3)) + rx_inner) + 144)]));
            conv2d_nchw_local[(yy_c + 4)] = (conv2d_nchw_local[(yy_c + 4)] + (pad_temp_shared[(((((rc_inner * 16) + (yy_c * 4)) + (ry_inner * 4)) + ((int)threadIdx.x)) + rx_inner)] * kernel_shared[(((((((int)threadIdx.z) * 18) + (rc_inner * 9)) + (ry_inner * 3)) + rx_inner) + 288)]));
            conv2d_nchw_local[(yy_c + 6)] = (conv2d_nchw_local[(yy_c + 6)] + (pad_temp_shared[(((((rc_inner * 16) + (yy_c * 4)) + (ry_inner * 4)) + ((int)threadIdx.x)) + rx_inner)] * kernel_shared[(((((((int)threadIdx.z) * 18) + (rc_inner * 9)) + (ry_inner * 3)) + rx_inner) + 432)]));
          }
        }
      }
    }
  }
  for (int yy_inner_inner_inner = 0; yy_inner_inner_inner < 2; ++yy_inner_inner_inner) {
    conv2d_nchw[((((((((int)blockIdx.z) * 2064512) + (((int)threadIdx.z) * 64516)) + (((int)blockIdx.y) * 508)) + (yy_inner_inner_inner * 254)) + (((int)blockIdx.x) * 2)) + ((int)threadIdx.x))] = conv2d_nchw_local[yy_inner_inner_inner];
    conv2d_nchw[(((((((((int)blockIdx.z) * 2064512) + (((int)threadIdx.z) * 64516)) + (((int)blockIdx.y) * 508)) + (yy_inner_inner_inner * 254)) + (((int)blockIdx.x) * 2)) + ((int)threadIdx.x)) + 516128)] = conv2d_nchw_local[(yy_inner_inner_inner + 2)];
    conv2d_nchw[(((((((((int)blockIdx.z) * 2064512) + (((int)threadIdx.z) * 64516)) + (((int)blockIdx.y) * 508)) + (yy_inner_inner_inner * 254)) + (((int)blockIdx.x) * 2)) + ((int)threadIdx.x)) + 1032256)] = conv2d_nchw_local[(yy_inner_inner_inner + 4)];
    conv2d_nchw[(((((((((int)blockIdx.z) * 2064512) + (((int)threadIdx.z) * 64516)) + (((int)blockIdx.y) * 508)) + (yy_inner_inner_inner * 254)) + (((int)blockIdx.x) * 2)) + ((int)threadIdx.x)) + 1548384)] = conv2d_nchw_local[(yy_inner_inner_inner + 6)];
  }
}

