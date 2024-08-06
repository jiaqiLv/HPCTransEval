extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_40(float* __restrict__ conv2d_nchw, float* __restrict__ conv2d_nchw_1, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int ry = 0; ry < 3; ++ry) {
    for (int rx = 0; rx < 3; ++rx) {
      if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
        conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv2d_nchw_1[(((((((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) / 15) * 122) + (ry * 122)) + rx) + (((((int)blockIdx.x) * 64) + ((int)threadIdx.x)) % 120))] * ph[((ry * 3) + rx)]));
      }
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_10(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int ry = 0; ry < 3; ++ry) {
    for (int rx = 0; rx < 3; ++rx) {
      if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
        conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (pad_temp[(((((((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) / 15) * 122) + (ry * 122)) + rx) + (((((int)blockIdx.x) * 64) + ((int)threadIdx.x)) % 120))] * ph[((ry * 3) + rx)]));
      }
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_39(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_69(float* __restrict__ conv2d_nchw, float* __restrict__ conv2d_nchw_1, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ((3721 <= ((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2))) ? conv2d_nchw_1[(((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3721) * 14400) + (((((((int)blockIdx.x) * 512) + (((int)threadIdx.x) >> 1)) % 7442) / 61) * 120)) + (((((int)blockIdx.x) * 48) + ((int)threadIdx.x)) % 122)) - 14400)] : pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_66(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_32(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 32) + (((int)threadIdx.x) >> 5)) < 961) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (((((31 <= (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) % 3844)) && ((((((int)blockIdx.x) * 1024) + ((int)threadIdx.x)) % 15376) < 15252)) && (1 <= (((((int)blockIdx.x) * 32) + ((int)threadIdx.x)) % 124))) && ((((((int)blockIdx.x) * 32) + ((int)threadIdx.x)) % 124) < 123)) ? conv2d_nchw[(((((((((int)blockIdx.x) * 64) + (((int)threadIdx.x) >> 4)) / 961) * 14884) + (((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) % 3844) / 31) * 122)) + (((((int)blockIdx.x) * 32) + ((int)threadIdx.x)) % 124)) - 123)] : -3.402823e+38f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_26(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] * ph[0]));
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_2(float* __restrict__ conv2d_nchw) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_13(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_45(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_11(float* __restrict__ conv2d_nchw) {
  if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_25(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_23(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 2; ++rc) {
    if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
      pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv2d_nchw[(((rc * 14884) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] * ph[rc]));
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_34(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 2; ++rc) {
    if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
      pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv2d_nchw[(((rc * 14884) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] * ph[rc]));
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_63(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_18(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_1(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 3; ++rc) {
    for (int ry = 0; ry < 7; ++ry) {
      for (int rx = 0; rx < 7; ++rx) {
        if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
          conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (pad_temp[(((((rc * 16384) + ((((((int)blockIdx.x) * 512) + (((int)threadIdx.x) >> 1)) / 61) * 128)) + (ry * 128)) + rx) + (((((int)blockIdx.x) * 48) + ((int)threadIdx.x)) % 122))] * ph[(((rc * 49) + (ry * 7)) + rx)]));
        }
      }
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel(float* __restrict__ pad_temp, float* __restrict__ ph) {
  pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ph[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_75(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] * ph[0]));
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_31(float* __restrict__ conv2d_nchw, float* __restrict__ conv2d_nchw_1, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ((3721 <= ((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2))) ? conv2d_nchw_1[(((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3721) * 14400) + (((((((int)blockIdx.x) * 512) + (((int)threadIdx.x) >> 1)) % 7442) / 61) * 120)) + (((((int)blockIdx.x) * 48) + ((int)threadIdx.x)) % 122)) - 14400)] : pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_36(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_21(float* __restrict__ conv2d_nchw) {
  if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_41(float* __restrict__ conv2d_nchw) {
  if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_78(float* __restrict__ conv2d_nchw, float* __restrict__ conv2d_nchw_1, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int ry = 0; ry < 3; ++ry) {
    for (int rx = 0; rx < 3; ++rx) {
      if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
        conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv2d_nchw_1[(((((((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) / 15) * 122) + (ry * 122)) + rx) + (((((int)blockIdx.x) * 64) + ((int)threadIdx.x)) % 120))] * ph[((ry * 3) + rx)]));
      }
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_55(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] * ph[0]));
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_43(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 2; ++rc) {
    if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
      pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv2d_nchw[(((rc * 14884) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] * ph[rc]));
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_70(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 32) + (((int)threadIdx.x) >> 5)) < 961) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (((((31 <= (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) % 3844)) && ((((((int)blockIdx.x) * 1024) + ((int)threadIdx.x)) % 15376) < 15252)) && (1 <= (((((int)blockIdx.x) * 32) + ((int)threadIdx.x)) % 124))) && ((((((int)blockIdx.x) * 32) + ((int)threadIdx.x)) % 124) < 123)) ? conv2d_nchw[(((((((((int)blockIdx.x) * 64) + (((int)threadIdx.x) >> 4)) / 961) * 14884) + (((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) % 3844) / 31) * 122)) + (((((int)blockIdx.x) * 32) + ((int)threadIdx.x)) % 124)) - 123)] : -3.402823e+38f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_9(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_24(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_20(float* __restrict__ conv2d_nchw, float* __restrict__ conv2d_nchw_1, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int ry = 0; ry < 3; ++ry) {
    for (int rx = 0; rx < 3; ++rx) {
      if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
        conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv2d_nchw_1[(((((((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) / 15) * 122) + (ry * 122)) + rx) + (((((int)blockIdx.x) * 64) + ((int)threadIdx.x)) % 120))] * ph[((ry * 3) + rx)]));
      }
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_8(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_52(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 2; ++rc) {
    if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
      pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv2d_nchw[(((rc * 14884) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] * ph[rc]));
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_64(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] * ph[0]));
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_15(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_48(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_59(float* __restrict__ conv2d_nchw) {
  if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_53(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_61(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 2; ++rc) {
    if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
      pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv2d_nchw[(((rc * 14884) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] * ph[rc]));
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_72(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 2; ++rc) {
    if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
      pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv2d_nchw[(((rc * 14884) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] * ph[rc]));
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_62(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_49(float* __restrict__ conv2d_nchw, float* __restrict__ conv2d_nchw_1, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int ry = 0; ry < 3; ++ry) {
    for (int rx = 0; rx < 3; ++rx) {
      if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
        conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv2d_nchw_1[(((((((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) / 15) * 122) + (ry * 122)) + rx) + (((((int)blockIdx.x) * 64) + ((int)threadIdx.x)) % 120))] * ph[((ry * 3) + rx)]));
      }
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_27(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_28(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_30(float* __restrict__ conv2d_nchw) {
  if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_22(float* __restrict__ conv2d_nchw, float* __restrict__ conv2d_nchw_1, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ((3721 <= ((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2))) ? conv2d_nchw_1[(((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3721) * 14400) + (((((((int)blockIdx.x) * 512) + (((int)threadIdx.x) >> 1)) % 7442) / 61) * 120)) + (((((int)blockIdx.x) * 48) + ((int)threadIdx.x)) % 122)) - 14400)] : pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_37(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] * ph[0]));
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_5(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] * ph[0]));
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_68(float* __restrict__ conv2d_nchw) {
  if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_14(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int rc = 0; rc < 2; ++rc) {
    if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
      pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv2d_nchw[(((rc * 14884) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x))] * ph[rc]));
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_50(float* __restrict__ conv2d_nchw) {
  if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_77(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_79(float* __restrict__ conv2d_nchw) {
  if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_17(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] * ph[0]));
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_54(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_42(float* __restrict__ conv2d_nchw, float* __restrict__ conv2d_nchw_1, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ((3721 <= ((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2))) ? conv2d_nchw_1[(((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3721) * 14400) + (((((((int)blockIdx.x) * 512) + (((int)threadIdx.x) >> 1)) % 7442) / 61) * 120)) + (((((int)blockIdx.x) * 48) + ((int)threadIdx.x)) % 122)) - 14400)] : pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_3(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 64) + (((int)threadIdx.x) >> 4)) < 961) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (((((31 <= ((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2))) && (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3813)) && (1 <= (((((int)blockIdx.x) * 32) + ((int)threadIdx.x)) % 124))) && ((((((int)blockIdx.x) * 32) + ((int)threadIdx.x)) % 124) < 123)) ? conv2d_nchw[((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 31) * 122) + (((((int)blockIdx.x) * 32) + ((int)threadIdx.x)) % 124)) - 123)] : -3.402823e+38f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_16(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_56(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_60(float* __restrict__ conv2d_nchw, float* __restrict__ conv2d_nchw_1, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ((3721 <= ((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2))) ? conv2d_nchw_1[(((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3721) * 14400) + (((((((int)blockIdx.x) * 512) + (((int)threadIdx.x) >> 1)) % 7442) / 61) * 120)) + (((((int)blockIdx.x) * 48) + ((int)threadIdx.x)) % 122)) - 14400)] : pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_29(float* __restrict__ conv2d_nchw, float* __restrict__ conv2d_nchw_1, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int ry = 0; ry < 3; ++ry) {
    for (int rx = 0; rx < 3; ++rx) {
      if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
        conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv2d_nchw_1[(((((((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) / 15) * 122) + (ry * 122)) + rx) + (((((int)blockIdx.x) * 64) + ((int)threadIdx.x)) % 120))] * ph[((ry * 3) + rx)]));
      }
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_76(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_65(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_80(float* __restrict__ T_concat, float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) < 3721) {
    T_concat[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ((3721 <= ((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2))) ? conv2d_nchw[(((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3721) * 14400) + (((((((int)blockIdx.x) * 512) + (((int)threadIdx.x) >> 1)) % 7442) / 61) * 120)) + (((((int)blockIdx.x) * 48) + ((int)threadIdx.x)) % 122)) - 14400)] : pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_46(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] * ph[0]));
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_47(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_6(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_71(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = -3.402823e+38f;
  }
  for (int rv0 = 0; rv0 < 3; ++rv0) {
    for (int rv1 = 0; rv1 < 3; ++rv1) {
      if (((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) < 3721) {
        conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], pad_temp[((((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3721) * 15376) + (((((((int)blockIdx.x) * 512) + (((int)threadIdx.x) >> 1)) % 7442) / 61) * 124)) + (rv0 * 124)) + rv1) + (((((int)blockIdx.x) * 48) + ((int)threadIdx.x)) % 122))]);
      }
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_19(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_51(float* __restrict__ conv2d_nchw, float* __restrict__ conv2d_nchw_1, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ((3721 <= ((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2))) ? conv2d_nchw_1[(((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3721) * 14400) + (((((((int)blockIdx.x) * 512) + (((int)threadIdx.x) >> 1)) % 7442) / 61) * 120)) + (((((int)blockIdx.x) * 48) + ((int)threadIdx.x)) % 122)) - 14400)] : pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_74(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_7(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] * ph[0]));
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_33(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = -3.402823e+38f;
  }
  for (int rv0 = 0; rv0 < 3; ++rv0) {
    for (int rv1 = 0; rv1 < 3; ++rv1) {
      if (((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) < 3721) {
        conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], pad_temp[((((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3721) * 15376) + (((((((int)blockIdx.x) * 512) + (((int)threadIdx.x) >> 1)) % 7442) / 61) * 124)) + (rv0 * 124)) + rv1) + (((((int)blockIdx.x) * 48) + ((int)threadIdx.x)) % 122))]);
      }
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_44(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_12(float* __restrict__ conv2d_nchw, float* __restrict__ conv2d_nchw_1, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ((3721 <= ((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2))) ? conv2d_nchw[(((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3721) * 14400) + (((((((int)blockIdx.x) * 512) + (((int)threadIdx.x) >> 1)) % 7442) / 61) * 120)) + (((((int)blockIdx.x) * 48) + ((int)threadIdx.x)) % 122)) - 14400)] : conv2d_nchw_1[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))]);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_58(float* __restrict__ conv2d_nchw, float* __restrict__ conv2d_nchw_1, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int ry = 0; ry < 3; ++ry) {
    for (int rx = 0; rx < 3; ++rx) {
      if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
        conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv2d_nchw_1[(((((((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) / 15) * 122) + (ry * 122)) + rx) + (((((int)blockIdx.x) * 64) + ((int)threadIdx.x)) % 120))] * ph[((ry * 3) + rx)]));
      }
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_38(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_73(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_57(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_4(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = -3.402823e+38f;
  }
  for (int rv0 = 0; rv0 < 3; ++rv0) {
    for (int rv1 = 0; rv1 < 3; ++rv1) {
      if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
        conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], pad_temp[(((((((((int)blockIdx.x) * 512) + (((int)threadIdx.x) >> 1)) / 61) * 124) + (rv0 * 124)) + rv1) + (((((int)blockIdx.x) * 48) + ((int)threadIdx.x)) % 122))]);
      }
    }
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_35(float* __restrict__ conv2d_nchw, float* __restrict__ pad_temp) {
  if (((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) < 3721) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
  }
}

extern "C" __global__ void __launch_bounds__(1024) default_function_kernel_67(float* __restrict__ conv2d_nchw, float* __restrict__ conv2d_nchw_1, float* __restrict__ ph) {
  if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
    conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = 0.000000e+00f;
  }
  for (int ry = 0; ry < 3; ++ry) {
    for (int rx = 0; rx < 3; ++rx) {
      if (((((int)blockIdx.x) * 16) + (((int)threadIdx.x) >> 6)) < 225) {
        conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (conv2d_nchw_1[(((((((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) / 15) * 122) + (ry * 122)) + rx) + (((((int)blockIdx.x) * 64) + ((int)threadIdx.x)) % 120))] * ph[((ry * 3) + rx)]));
      }
    }
  }
}

