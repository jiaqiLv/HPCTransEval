extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_3(float* __restrict__ T_reshape, float* __restrict__ conv2d_nchw) {
  for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 4; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
    if ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 1024) + (((int)blockIdx.x) * 4)) + (((int)threadIdx.x) >> 8)) < 3969) {
      conv2d_nchw[(((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] = (conv2d_nchw[(((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] - T_reshape[((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 65536) + (((int)blockIdx.x) * 256)) + (((int)threadIdx.x) >> 2)) / 3969)]);
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_12(float* __restrict__ conv2d_nchw) {
  for (int i0_i1_fused_i2_fused_i3_fused_outer = 0; i0_i1_fused_i2_fused_i3_fused_outer < 4; ++i0_i1_fused_i2_fused_i3_fused_outer) {
    if ((((i0_i1_fused_i2_fused_i3_fused_outer * 1024) + (((int)blockIdx.x) * 4)) + (((int)threadIdx.x) >> 8)) < 3969) {
      conv2d_nchw[(((i0_i1_fused_i2_fused_i3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] = max(conv2d_nchw[(((i0_i1_fused_i2_fused_i3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))], 0.000000e+00f);
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_19(float* __restrict__ T_reshape, float* __restrict__ conv2d_nchw) {
  for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 4; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
    if (((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 256) + ((int)blockIdx.x)) < 961) {
      conv2d_nchw[(((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] = (conv2d_nchw[(((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] / T_reshape[((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 16384) + (((int)blockIdx.x) * 64)) + (((int)threadIdx.x) >> 4)) / 961)]);
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_13(float* __restrict__ conv2d_nchw, float* __restrict__ conv2d_nchw_1, float* __restrict__ ph) {
  for (int nn_ff_fused_yy_fused_xx_fused_outer = 0; nn_ff_fused_yy_fused_xx_fused_outer < 4; ++nn_ff_fused_yy_fused_xx_fused_outer) {
    if (((nn_ff_fused_yy_fused_xx_fused_outer * 256) + ((int)blockIdx.x)) < 961) {
      conv2d_nchw[(((nn_ff_fused_yy_fused_xx_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] = 0.000000e+00f;
    }
    for (int rc = 0; rc < 64; ++rc) {
      for (int ry = 0; ry < 3; ++ry) {
        for (int rx = 0; rx < 3; ++rx) {
          if (((nn_ff_fused_yy_fused_xx_fused_outer * 256) + ((int)blockIdx.x)) < 961) {
            conv2d_nchw[(((nn_ff_fused_yy_fused_xx_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] = (conv2d_nchw[(((nn_ff_fused_yy_fused_xx_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] + (conv2d_nchw_1[(((((rc * 15876) + ((((((nn_ff_fused_yy_fused_xx_fused_outer * 65536) + (((int)blockIdx.x) * 256)) + (((int)threadIdx.x) >> 2)) % 3844) / 31) * 126)) + (ry * 126)) + rx) + ((((nn_ff_fused_yy_fused_xx_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x)) % 124))] * ph[(((((((((nn_ff_fused_yy_fused_xx_fused_outer * 16384) + (((int)blockIdx.x) * 64)) + (((int)threadIdx.x) >> 4)) % 61504) / 961) * 576) + (rc * 9)) + (ry * 3)) + rx)]));
          }
        }
      }
    }
  }
}

extern "C" __global__ void __launch_bounds__(64) default_function_kernel_10(float* __restrict__ T_reshape, float* __restrict__ ph) {
  T_reshape[((int)threadIdx.x)] = ph[0];
}

extern "C" __global__ void __launch_bounds__(64) default_function_kernel_18(float* __restrict__ T_reshape) {
  T_reshape[((int)threadIdx.x)] = sqrtf(T_reshape[((int)threadIdx.x)]);
}

extern "C" __global__ void __launch_bounds__(64) default_function_kernel_6(float* __restrict__ T_reshape) {
  T_reshape[((int)threadIdx.x)] = sqrtf(T_reshape[((int)threadIdx.x)]);
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_24(float* __restrict__ compute, float* __restrict__ conv2d_nchw) {
  for (int i0_i1_fused_i2_fused_i3_fused_outer = 0; i0_i1_fused_i2_fused_i3_fused_outer < 4; ++i0_i1_fused_i2_fused_i3_fused_outer) {
    if (((i0_i1_fused_i2_fused_i3_fused_outer * 256) + ((int)blockIdx.x)) < 961) {
      compute[(((i0_i1_fused_i2_fused_i3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] = max(conv2d_nchw[(((i0_i1_fused_i2_fused_i3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))], 0.000000e+00f);
    }
  }
}

extern "C" __global__ void __launch_bounds__(64) default_function_kernel_17(float* __restrict__ T_reshape) {
  T_reshape[((int)threadIdx.x)] = (T_reshape[((int)threadIdx.x)] + 1.000000e-05f);
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_9(float* __restrict__ T_reshape, float* __restrict__ conv2d_nchw) {
  for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 4; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
    if ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 1024) + (((int)blockIdx.x) * 4)) + (((int)threadIdx.x) >> 8)) < 3969) {
      conv2d_nchw[(((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] = (conv2d_nchw[(((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] * T_reshape[((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 65536) + (((int)blockIdx.x) * 256)) + (((int)threadIdx.x) >> 2)) / 3969)]);
    }
  }
}

extern "C" __global__ void __launch_bounds__(64) default_function_kernel_20(float* __restrict__ T_reshape, float* __restrict__ ph) {
  T_reshape[((int)threadIdx.x)] = ph[0];
}

extern "C" __global__ void __launch_bounds__(64) default_function_kernel_8(float* __restrict__ T_reshape, float* __restrict__ ph) {
  T_reshape[((int)threadIdx.x)] = ph[0];
}

extern "C" __global__ void __launch_bounds__(64) default_function_kernel_4(float* __restrict__ T_reshape, float* __restrict__ ph) {
  T_reshape[((int)threadIdx.x)] = ph[((int)threadIdx.x)];
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_23(float* __restrict__ T_reshape, float* __restrict__ conv2d_nchw) {
  for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 4; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
    if (((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 256) + ((int)blockIdx.x)) < 961) {
      conv2d_nchw[(((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] = (conv2d_nchw[(((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] + T_reshape[((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 16384) + (((int)blockIdx.x) * 64)) + (((int)threadIdx.x) >> 4)) / 961)]);
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_15(float* __restrict__ T_reshape, float* __restrict__ conv2d_nchw) {
  for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 4; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
    if (((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 256) + ((int)blockIdx.x)) < 961) {
      conv2d_nchw[(((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] = (conv2d_nchw[(((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] - T_reshape[((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 16384) + (((int)blockIdx.x) * 64)) + (((int)threadIdx.x) >> 4)) / 961)]);
    }
  }
}

extern "C" __global__ void __launch_bounds__(64) default_function_kernel_2(float* __restrict__ T_reshape, float* __restrict__ ph) {
  T_reshape[((int)threadIdx.x)] = ph[((int)threadIdx.x)];
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_11(float* __restrict__ T_reshape, float* __restrict__ conv2d_nchw) {
  for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 4; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
    if ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 1024) + (((int)blockIdx.x) * 4)) + (((int)threadIdx.x) >> 8)) < 3969) {
      conv2d_nchw[(((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] = (conv2d_nchw[(((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] + T_reshape[((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 65536) + (((int)blockIdx.x) * 256)) + (((int)threadIdx.x) >> 2)) / 3969)]);
    }
  }
}

extern "C" __global__ void __launch_bounds__(64) default_function_kernel_14(float* __restrict__ T_reshape, float* __restrict__ ph) {
  T_reshape[((int)threadIdx.x)] = ph[((int)threadIdx.x)];
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_1(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  for (int nn_ff_fused_yy_fused_xx_fused_outer = 0; nn_ff_fused_yy_fused_xx_fused_outer < 4; ++nn_ff_fused_yy_fused_xx_fused_outer) {
    if ((((nn_ff_fused_yy_fused_xx_fused_outer * 1024) + (((int)blockIdx.x) * 4)) + (((int)threadIdx.x) >> 8)) < 3969) {
      conv2d_nchw[(((nn_ff_fused_yy_fused_xx_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] = 0.000000e+00f;
    }
    for (int rc = 0; rc < 3; ++rc) {
      for (int ry = 0; ry < 3; ++ry) {
        for (int rx = 0; rx < 3; ++rx) {
          if ((((nn_ff_fused_yy_fused_xx_fused_outer * 1024) + (((int)blockIdx.x) * 4)) + (((int)threadIdx.x) >> 8)) < 3969) {
            conv2d_nchw[(((nn_ff_fused_yy_fused_xx_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] = (conv2d_nchw[(((nn_ff_fused_yy_fused_xx_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] + (pad_temp[(((((rc * 16384) + ((((((nn_ff_fused_yy_fused_xx_fused_outer * 131072) + (((int)blockIdx.x) * 512)) + (((int)threadIdx.x) >> 1)) % 7938) / 63) * 128)) + (ry * 128)) + rx) + ((((nn_ff_fused_yy_fused_xx_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x)) % 126))] * ph[((((((((nn_ff_fused_yy_fused_xx_fused_outer * 65536) + (((int)blockIdx.x) * 256)) + (((int)threadIdx.x) >> 2)) / 3969) * 27) + (rc * 9)) + (ry * 3)) + rx)]));
          }
        }
      }
    }
  }
}

extern "C" __global__ void __launch_bounds__(64) default_function_kernel_5(float* __restrict__ T_reshape) {
  T_reshape[((int)threadIdx.x)] = (T_reshape[((int)threadIdx.x)] + 1.000000e-05f);
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_7(float* __restrict__ T_reshape, float* __restrict__ conv2d_nchw) {
  for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 4; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
    if ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 1024) + (((int)blockIdx.x) * 4)) + (((int)threadIdx.x) >> 8)) < 3969) {
      conv2d_nchw[(((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] = (conv2d_nchw[(((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] / T_reshape[((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 65536) + (((int)blockIdx.x) * 256)) + (((int)threadIdx.x) >> 2)) / 3969)]);
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_21(float* __restrict__ T_reshape, float* __restrict__ conv2d_nchw) {
  for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 4; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
    if (((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 256) + ((int)blockIdx.x)) < 961) {
      conv2d_nchw[(((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] = (conv2d_nchw[(((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] * T_reshape[((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 16384) + (((int)blockIdx.x) * 64)) + (((int)threadIdx.x) >> 4)) / 961)]);
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel(float* __restrict__ pad_temp, float* __restrict__ ph) {
  pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ph[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
}

extern "C" __global__ void __launch_bounds__(64) default_function_kernel_22(float* __restrict__ T_reshape, float* __restrict__ ph) {
  T_reshape[((int)threadIdx.x)] = ph[0];
}

extern "C" __global__ void __launch_bounds__(64) default_function_kernel_16(float* __restrict__ T_reshape, float* __restrict__ ph) {
  T_reshape[((int)threadIdx.x)] = ph[((int)threadIdx.x)];
}

