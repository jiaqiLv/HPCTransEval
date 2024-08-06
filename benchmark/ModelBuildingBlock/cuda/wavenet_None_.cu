extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_18(float* __restrict__ conv1d_ncw) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (1.000000e+00f / (1.000000e+00f + __expf((0.000000e+00f - conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]))));
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_42(float* __restrict__ conv1d_ncw, float* __restrict__ conv1d_ncw_1) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = conv1d_ncw_1[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_39(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 128; ++rc) {
    for (int ry = 0; ry < 3; ++ry) {
      if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
        conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (pad_temp[(((rc * 116) + (ry * 8)) + (((((int)blockIdx.x) * 24) + ((int)threadIdx.x)) % 100))] * ph[((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 25) * 384) + (rc * 3)) + ry)]));
      }
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_3(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 128; ++rc) {
    for (int ry = 0; ry < 3; ++ry) {
      if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
        conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (pad_temp[(((rc * 102) + ry) + (((((int)blockIdx.x) * 24) + ((int)threadIdx.x)) % 100))] * ph[((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 25) * 384) + (rc * 3)) + ry)]));
      }
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_5(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 4) + (((int)threadIdx.x) >> 8)) < 51) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ((1 <= (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 1)) % 51)) ? conv1d_ncw[((((((((int)blockIdx.x) * 512) + (((int)threadIdx.x) >> 1)) / 51) * 100) + (((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 102)) - 2)] : 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_41(float* __restrict__ conv1d_ncw, float* __restrict__ conv1d_ncw_1) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + conv1d_ncw_1[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_25(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 128; ++rc) {
    for (int ry = 0; ry < 3; ++ry) {
      if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
        conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (pad_temp[(((rc * 108) + (ry * 4)) + (((((int)blockIdx.x) * 24) + ((int)threadIdx.x)) % 100))] * ph[((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 25) * 384) + (rc * 3)) + ry)]));
      }
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_27(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 27) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ((8 <= (((((int)blockIdx.x) * 52) + ((int)threadIdx.x)) % 108)) ? conv1d_ncw[((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 27) * 100) + (((((int)blockIdx.x) * 52) + ((int)threadIdx.x)) % 108)) - 8)] : 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_30(float* __restrict__ conv1d_ncw, float* __restrict__ conv1d_ncw_1) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + conv1d_ncw_1[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_35(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 29) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ((16 <= (((((int)blockIdx.x) * 96) + ((int)threadIdx.x)) % 116)) ? conv1d_ncw[((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 29) * 100) + (((((int)blockIdx.x) * 96) + ((int)threadIdx.x)) % 116)) - 16)] : 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_17(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 128; ++rc) {
    for (int ry = 0; ry < 3; ++ry) {
      if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
        conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (pad_temp[(((rc * 104) + (ry * 2)) + (((((int)blockIdx.x) * 24) + ((int)threadIdx.x)) % 100))] * ph[((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 25) * 384) + (rc * 3)) + ry)]));
      }
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_19(float* __restrict__ conv1d_ncw, float* __restrict__ conv1d_ncw_1) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + conv1d_ncw_1[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_15(float* __restrict__ conv1d_ncw) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = tanhf(conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_24(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 27) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ((8 <= (((((int)blockIdx.x) * 52) + ((int)threadIdx.x)) % 108)) ? conv1d_ncw[((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 27) * 100) + (((((int)blockIdx.x) * 52) + ((int)threadIdx.x)) % 108)) - 8)] : 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_28(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 128; ++rc) {
    for (int ry = 0; ry < 3; ++ry) {
      if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
        conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (pad_temp[(((rc * 108) + (ry * 4)) + (((((int)blockIdx.x) * 24) + ((int)threadIdx.x)) % 100))] * ph[((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 25) * 384) + (rc * 3)) + ry)]));
      }
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_6(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 128; ++rc) {
    for (int ry = 0; ry < 3; ++ry) {
      if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
        conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (pad_temp[(((rc * 102) + ry) + (((((int)blockIdx.x) * 24) + ((int)threadIdx.x)) % 100))] * ph[((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 25) * 384) + (rc * 3)) + ry)]));
      }
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_12(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_23(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_40(float* __restrict__ conv1d_ncw) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (1.000000e+00f / (1.000000e+00f + __expf((0.000000e+00f - conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]))));
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_2(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 4) + (((int)threadIdx.x) >> 8)) < 51) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ((1 <= (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 1)) % 51)) ? conv1d_ncw[((((((((int)blockIdx.x) * 512) + (((int)threadIdx.x) >> 1)) / 51) * 100) + (((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 102)) - 2)] : 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_26(float* __restrict__ conv1d_ncw) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = tanhf(conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_11(float* __restrict__ conv1d_ncw, float* __restrict__ conv1d_ncw_1, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 128; ++rc) {
    if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
      conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv1d_ncw_1[((rc * 100) + (((((int)blockIdx.x) * 24) + ((int)threadIdx.x)) % 100))] * ph[(((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 25) * 64) + rc)]));
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_7(float* __restrict__ conv1d_ncw) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (1.000000e+00f / (1.000000e+00f + __expf((0.000000e+00f - conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]))));
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_21(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 128; ++rc) {
    if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
      pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv1d_ncw[((rc * 100) + (((((int)blockIdx.x) * 24) + ((int)threadIdx.x)) % 100))] * ph[(((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 25) * 128) + rc)]));
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_34(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_46(float* __restrict__ T_concat, float* __restrict__ conv1d_ncw, float* __restrict__ conv1d_ncw_1, float* __restrict__ conv1d_ncw_2, float* __restrict__ conv1d_ncw_3) {
  T_concat[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ((75 <= ((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9))) ? conv1d_ncw[(((((int)blockIdx.x) * 1024) + ((int)threadIdx.x)) - 38400)] : ((25 <= ((int)blockIdx.x)) ? conv1d_ncw_1[(((((int)blockIdx.x) * 1024) + ((int)threadIdx.x)) - 25600)] : ((25 <= ((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9))) ? conv1d_ncw_2[(((((int)blockIdx.x) * 1024) + ((int)threadIdx.x)) - 12800)] : conv1d_ncw_3[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))])));
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_4(float* __restrict__ conv1d_ncw) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = tanhf(conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_33(float* __restrict__ conv1d_ncw, float* __restrict__ conv1d_ncw_1, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 128; ++rc) {
    if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
      conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv1d_ncw_1[((rc * 100) + (((((int)blockIdx.x) * 24) + ((int)threadIdx.x)) % 100))] * ph[(((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 25) * 64) + rc)]));
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_14(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 128; ++rc) {
    for (int ry = 0; ry < 3; ++ry) {
      if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
        conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (pad_temp[(((rc * 104) + (ry * 2)) + (((((int)blockIdx.x) * 24) + ((int)threadIdx.x)) % 100))] * ph[((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 25) * 384) + (rc * 3)) + ry)]));
      }
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_45(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_16(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp) {
  pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ((1 <= (((((int)blockIdx.x) * 22) + (((int)threadIdx.x) >> 2)) % 26)) ? conv1d_ncw[((((((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) / 13) * 100) + (((((int)blockIdx.x) * 88) + ((int)threadIdx.x)) % 104)) - 4)] : 0.000000e+00f);
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_8(float* __restrict__ conv1d_ncw, float* __restrict__ conv1d_ncw_1) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + conv1d_ncw_1[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_32(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 128; ++rc) {
    if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
      pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv1d_ncw[((rc * 100) + (((((int)blockIdx.x) * 24) + ((int)threadIdx.x)) % 100))] * ph[(((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 25) * 128) + rc)]));
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_43(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 128; ++rc) {
    if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
      pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv1d_ncw[((rc * 100) + (((((int)blockIdx.x) * 24) + ((int)threadIdx.x)) % 100))] * ph[(((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 25) * 128) + rc)]));
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_20(float* __restrict__ conv1d_ncw, float* __restrict__ conv1d_ncw_1) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = conv1d_ncw_1[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel(float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 8) + (((int)threadIdx.x) >> 7)) < 51) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ((1 <= (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 1)) % 51)) ? ph[((((((((int)blockIdx.x) * 512) + (((int)threadIdx.x) >> 1)) / 51) * 100) + (((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 102)) - 2)] : 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_38(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 29) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ((16 <= (((((int)blockIdx.x) * 96) + ((int)threadIdx.x)) % 116)) ? conv1d_ncw[((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 29) * 100) + (((((int)blockIdx.x) * 96) + ((int)threadIdx.x)) % 116)) - 16)] : 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_44(float* __restrict__ conv1d_ncw, float* __restrict__ conv1d_ncw_1, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 128; ++rc) {
    if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
      conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv1d_ncw_1[((rc * 100) + (((((int)blockIdx.x) * 24) + ((int)threadIdx.x)) % 100))] * ph[(((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 25) * 64) + rc)]));
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_29(float* __restrict__ conv1d_ncw) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (1.000000e+00f / (1.000000e+00f + __expf((0.000000e+00f - conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]))));
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_31(float* __restrict__ conv1d_ncw, float* __restrict__ conv1d_ncw_1) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = conv1d_ncw_1[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_37(float* __restrict__ conv1d_ncw) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = tanhf(conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_36(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 128; ++rc) {
    for (int ry = 0; ry < 3; ++ry) {
      if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
        conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (pad_temp[(((rc * 116) + (ry * 8)) + (((((int)blockIdx.x) * 24) + ((int)threadIdx.x)) % 100))] * ph[((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 25) * 384) + (rc * 3)) + ry)]));
      }
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_9(float* __restrict__ conv1d_ncw, float* __restrict__ conv1d_ncw_1) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = conv1d_ncw_1[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_10(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 128; ++rc) {
    if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
      pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv1d_ncw[((rc * 100) + (((((int)blockIdx.x) * 24) + ((int)threadIdx.x)) % 100))] * ph[(((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 25) * 128) + rc)]));
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_1(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 64; ++rc) {
    for (int ry = 0; ry < 3; ++ry) {
      if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
        conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (pad_temp[(((rc * 102) + ry) + (((((int)blockIdx.x) * 24) + ((int)threadIdx.x)) % 100))] * ph[((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 25) * 192) + (rc * 3)) + ry)]));
      }
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_13(float* __restrict__ conv1d_ncw, float* __restrict__ pad_temp) {
  pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ((1 <= (((((int)blockIdx.x) * 22) + (((int)threadIdx.x) >> 2)) % 26)) ? conv1d_ncw[((((((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) / 13) * 100) + (((((int)blockIdx.x) * 88) + ((int)threadIdx.x)) % 104)) - 4)] : 0.000000e+00f);
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_22(float* __restrict__ conv1d_ncw, float* __restrict__ conv1d_ncw_1, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
    conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 128; ++rc) {
    if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 9)) < 25) {
      conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv1d_ncw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv1d_ncw_1[((rc * 100) + (((((int)blockIdx.x) * 24) + ((int)threadIdx.x)) % 100))] * ph[(((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 25) * 64) + rc)]));
    }
  }
}

