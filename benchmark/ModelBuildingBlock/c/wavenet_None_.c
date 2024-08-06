void default_function_kernel(float* T_concat, float* ph, float* ph_1, float* ph_2, float* ph_3, float* ph_4, float* ph_5, float* ph_6, float* ph_7, float* ph_8, float* ph_9, float* ph_10, float* ph_11, float* ph_12, float* ph_13, float* ph_14, float* ph_15, float* ph_16, float* ph_17) {
  float pad_temp[14848];
  float conv1d_ncw[12800];
  float conv1d_ncw_1[12800];
  float conv1d_ncw_2[12800];
  float conv1d_ncw_3[12800];
  float conv1d_ncw_4[12800];
  #pragma omp parallel for
  for (int32_t i0_i1_fused = 0; i0_i1_fused < 64; ++i0_i1_fused) {
    for (int32_t i2_outer = 0; i2_outer < 7; ++i2_outer) {
      for (int32_t i2_inner = 0; i2_inner < 16; ++i2_inner) {
        if (((i2_outer * 8) + (i2_inner >> 1)) < 51) {
          pad_temp[(((i0_i1_fused * 102) + (i2_outer * 16)) + i2_inner)] = ((1 <= ((i2_outer * 8) + (i2_inner >> 1))) ? ph_9[((((i0_i1_fused * 100) + (i2_outer * 16)) + i2_inner) - 2)] : 0.000000e+00f);
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t nn_ff_fused = 0; nn_ff_fused < 128; ++nn_ff_fused) {
    for (int32_t yy_outer = 0; yy_outer < 7; ++yy_outer) {
      for (int32_t yy_inner = 0; yy_inner < 16; ++yy_inner) {
        if (((yy_outer * 4) + (yy_inner >> 2)) < 25) {
          conv1d_ncw[(((nn_ff_fused * 100) + (yy_outer * 16)) + yy_inner)] = 0.000000e+00f;
        }
        if (((yy_outer * 4) + (yy_inner >> 2)) < 25) {
          for (int32_t rc = 0; rc < 64; ++rc) {
            for (int32_t ry = 0; ry < 3; ++ry) {
              conv1d_ncw[(((nn_ff_fused * 100) + (yy_outer * 16)) + yy_inner)] = (conv1d_ncw[(((nn_ff_fused * 100) + (yy_outer * 16)) + yy_inner)] + (pad_temp[((((rc * 102) + (yy_outer * 16)) + yy_inner) + ry)] * ph_17[(((nn_ff_fused * 192) + (rc * 3)) + ry)]));
            }
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_1 = 0; i0_i1_fused_1 < 128; ++i0_i1_fused_1) {
    for (int32_t i2_outer_1 = 0; i2_outer_1 < 7; ++i2_outer_1) {
      for (int32_t i2_inner_1 = 0; i2_inner_1 < 16; ++i2_inner_1) {
        if (((i2_outer_1 * 8) + (i2_inner_1 >> 1)) < 51) {
          pad_temp[(((i0_i1_fused_1 * 102) + (i2_outer_1 * 16)) + i2_inner_1)] = ((1 <= ((i2_outer_1 * 8) + (i2_inner_1 >> 1))) ? conv1d_ncw[((((i0_i1_fused_1 * 100) + (i2_outer_1 * 16)) + i2_inner_1) - 2)] : 0.000000e+00f);
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t nn_ff_fused_1 = 0; nn_ff_fused_1 < 128; ++nn_ff_fused_1) {
    for (int32_t yy_outer_1 = 0; yy_outer_1 < 7; ++yy_outer_1) {
      for (int32_t yy_inner_1 = 0; yy_inner_1 < 16; ++yy_inner_1) {
        if (((yy_outer_1 * 4) + (yy_inner_1 >> 2)) < 25) {
          conv1d_ncw_1[(((nn_ff_fused_1 * 100) + (yy_outer_1 * 16)) + yy_inner_1)] = 0.000000e+00f;
        }
        if (((yy_outer_1 * 4) + (yy_inner_1 >> 2)) < 25) {
          for (int32_t rc_1 = 0; rc_1 < 128; ++rc_1) {
            for (int32_t ry_1 = 0; ry_1 < 3; ++ry_1) {
              conv1d_ncw_1[(((nn_ff_fused_1 * 100) + (yy_outer_1 * 16)) + yy_inner_1)] = (conv1d_ncw_1[(((nn_ff_fused_1 * 100) + (yy_outer_1 * 16)) + yy_inner_1)] + (pad_temp[((((rc_1 * 102) + (yy_outer_1 * 16)) + yy_inner_1) + ry_1)] * ph_16[(((nn_ff_fused_1 * 384) + (rc_1 * 3)) + ry_1)]));
            }
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_2 = 0; i0_i1_fused_2 < 128; ++i0_i1_fused_2) {
    for (int32_t i2_outer_2 = 0; i2_outer_2 < 7; ++i2_outer_2) {
      for (int32_t i2_inner_2 = 0; i2_inner_2 < 16; ++i2_inner_2) {
        if (((i2_outer_2 * 4) + (i2_inner_2 >> 2)) < 25) {
          conv1d_ncw_1[(((i0_i1_fused_2 * 100) + (i2_outer_2 * 16)) + i2_inner_2)] = tanhf(conv1d_ncw_1[(((i0_i1_fused_2 * 100) + (i2_outer_2 * 16)) + i2_inner_2)]);
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_3 = 0; i0_i1_fused_3 < 128; ++i0_i1_fused_3) {
    for (int32_t i2_outer_3 = 0; i2_outer_3 < 7; ++i2_outer_3) {
      for (int32_t i2_inner_3 = 0; i2_inner_3 < 16; ++i2_inner_3) {
        if (((i2_outer_3 * 8) + (i2_inner_3 >> 1)) < 51) {
          pad_temp[(((i0_i1_fused_3 * 102) + (i2_outer_3 * 16)) + i2_inner_3)] = ((1 <= ((i2_outer_3 * 8) + (i2_inner_3 >> 1))) ? conv1d_ncw[((((i0_i1_fused_3 * 100) + (i2_outer_3 * 16)) + i2_inner_3) - 2)] : 0.000000e+00f);
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t nn_ff_fused_2 = 0; nn_ff_fused_2 < 128; ++nn_ff_fused_2) {
    for (int32_t yy_outer_2 = 0; yy_outer_2 < 7; ++yy_outer_2) {
      for (int32_t yy_inner_2 = 0; yy_inner_2 < 16; ++yy_inner_2) {
        if (((yy_outer_2 * 4) + (yy_inner_2 >> 2)) < 25) {
          conv1d_ncw[(((nn_ff_fused_2 * 100) + (yy_outer_2 * 16)) + yy_inner_2)] = 0.000000e+00f;
        }
        if (((yy_outer_2 * 4) + (yy_inner_2 >> 2)) < 25) {
          for (int32_t rc_2 = 0; rc_2 < 128; ++rc_2) {
            for (int32_t ry_2 = 0; ry_2 < 3; ++ry_2) {
              conv1d_ncw[(((nn_ff_fused_2 * 100) + (yy_outer_2 * 16)) + yy_inner_2)] = (conv1d_ncw[(((nn_ff_fused_2 * 100) + (yy_outer_2 * 16)) + yy_inner_2)] + (pad_temp[((((rc_2 * 102) + (yy_outer_2 * 16)) + yy_inner_2) + ry_2)] * ph_15[(((nn_ff_fused_2 * 384) + (rc_2 * 3)) + ry_2)]));
            }
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_4 = 0; i0_i1_fused_4 < 128; ++i0_i1_fused_4) {
    for (int32_t i2_outer_4 = 0; i2_outer_4 < 7; ++i2_outer_4) {
      for (int32_t i2_inner_4 = 0; i2_inner_4 < 16; ++i2_inner_4) {
        if (((i2_outer_4 * 4) + (i2_inner_4 >> 2)) < 25) {
          conv1d_ncw[(((i0_i1_fused_4 * 100) + (i2_outer_4 * 16)) + i2_inner_4)] = (1.000000e+00f / (1.000000e+00f + expf((0.000000e+00f - conv1d_ncw[(((i0_i1_fused_4 * 100) + (i2_outer_4 * 16)) + i2_inner_4)]))));
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused = 0; ax0_ax1_fused < 128; ++ax0_ax1_fused) {
    for (int32_t ax2_outer = 0; ax2_outer < 7; ++ax2_outer) {
      for (int32_t ax2_inner = 0; ax2_inner < 16; ++ax2_inner) {
        if (((ax2_outer * 4) + (ax2_inner >> 2)) < 25) {
          conv1d_ncw_1[(((ax0_ax1_fused * 100) + (ax2_outer * 16)) + ax2_inner)] = (conv1d_ncw_1[(((ax0_ax1_fused * 100) + (ax2_outer * 16)) + ax2_inner)] + conv1d_ncw[(((ax0_ax1_fused * 100) + (ax2_outer * 16)) + ax2_inner)]);
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_5 = 0; i0_i1_fused_5 < 128; ++i0_i1_fused_5) {
    for (int32_t i2_outer_5 = 0; i2_outer_5 < 7; ++i2_outer_5) {
      for (int32_t i2_inner_5 = 0; i2_inner_5 < 16; ++i2_inner_5) {
        if (((i2_outer_5 * 4) + (i2_inner_5 >> 2)) < 25) {
          conv1d_ncw[(((i0_i1_fused_5 * 100) + (i2_outer_5 * 16)) + i2_inner_5)] = conv1d_ncw_1[(((i0_i1_fused_5 * 100) + (i2_outer_5 * 16)) + i2_inner_5)];
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t nn_ff_fused_3 = 0; nn_ff_fused_3 < 128; ++nn_ff_fused_3) {
    for (int32_t yy_outer_3 = 0; yy_outer_3 < 7; ++yy_outer_3) {
      for (int32_t yy_inner_3 = 0; yy_inner_3 < 16; ++yy_inner_3) {
        if (((yy_outer_3 * 4) + (yy_inner_3 >> 2)) < 25) {
          pad_temp[(((nn_ff_fused_3 * 100) + (yy_outer_3 * 16)) + yy_inner_3)] = 0.000000e+00f;
        }
        if (((yy_outer_3 * 4) + (yy_inner_3 >> 2)) < 25) {
          for (int32_t rc_3 = 0; rc_3 < 128; ++rc_3) {
            pad_temp[(((nn_ff_fused_3 * 100) + (yy_outer_3 * 16)) + yy_inner_3)] = (pad_temp[(((nn_ff_fused_3 * 100) + (yy_outer_3 * 16)) + yy_inner_3)] + (conv1d_ncw[(((rc_3 * 100) + (yy_outer_3 * 16)) + yy_inner_3)] * ph_14[((nn_ff_fused_3 * 128) + rc_3)]));
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t nn_ff_fused_4 = 0; nn_ff_fused_4 < 128; ++nn_ff_fused_4) {
    for (int32_t yy_outer_4 = 0; yy_outer_4 < 7; ++yy_outer_4) {
      for (int32_t yy_inner_4 = 0; yy_inner_4 < 16; ++yy_inner_4) {
        if (((yy_outer_4 * 4) + (yy_inner_4 >> 2)) < 25) {
          conv1d_ncw[(((nn_ff_fused_4 * 100) + (yy_outer_4 * 16)) + yy_inner_4)] = 0.000000e+00f;
        }
        if (((yy_outer_4 * 4) + (yy_inner_4 >> 2)) < 25) {
          for (int32_t rc_4 = 0; rc_4 < 128; ++rc_4) {
            conv1d_ncw[(((nn_ff_fused_4 * 100) + (yy_outer_4 * 16)) + yy_inner_4)] = (conv1d_ncw[(((nn_ff_fused_4 * 100) + (yy_outer_4 * 16)) + yy_inner_4)] + (conv1d_ncw_1[(((rc_4 * 100) + (yy_outer_4 * 16)) + yy_inner_4)] * ph_13[((nn_ff_fused_4 * 64) + rc_4)]));
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_1 = 0; ax0_ax1_fused_1 < 128; ++ax0_ax1_fused_1) {
    for (int32_t ax2_outer_1 = 0; ax2_outer_1 < 7; ++ax2_outer_1) {
      for (int32_t ax2_inner_1 = 0; ax2_inner_1 < 16; ++ax2_inner_1) {
        if (((ax2_outer_1 * 4) + (ax2_inner_1 >> 2)) < 25) {
          conv1d_ncw[(((ax0_ax1_fused_1 * 100) + (ax2_outer_1 * 16)) + ax2_inner_1)] = (pad_temp[(((ax0_ax1_fused_1 * 100) + (ax2_outer_1 * 16)) + ax2_inner_1)] + conv1d_ncw[(((ax0_ax1_fused_1 * 100) + (ax2_outer_1 * 16)) + ax2_inner_1)]);
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_6 = 0; i0_i1_fused_6 < 128; ++i0_i1_fused_6) {
    for (int32_t i2_outer_6 = 0; i2_outer_6 < 7; ++i2_outer_6) {
      for (int32_t i2_inner_6 = 0; i2_inner_6 < 16; ++i2_inner_6) {
        if (((i2_outer_6 * 2) + (i2_inner_6 >> 3)) < 13) {
          pad_temp[(((i0_i1_fused_6 * 104) + (i2_outer_6 * 16)) + i2_inner_6)] = ((1 <= ((i2_outer_6 * 4) + (i2_inner_6 >> 2))) ? conv1d_ncw[((((i0_i1_fused_6 * 100) + (i2_outer_6 * 16)) + i2_inner_6) - 4)] : 0.000000e+00f);
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t nn_ff_fused_5 = 0; nn_ff_fused_5 < 128; ++nn_ff_fused_5) {
    for (int32_t yy_outer_5 = 0; yy_outer_5 < 7; ++yy_outer_5) {
      for (int32_t yy_inner_5 = 0; yy_inner_5 < 16; ++yy_inner_5) {
        if (((yy_outer_5 * 4) + (yy_inner_5 >> 2)) < 25) {
          conv1d_ncw_1[(((nn_ff_fused_5 * 100) + (yy_outer_5 * 16)) + yy_inner_5)] = 0.000000e+00f;
        }
        if (((yy_outer_5 * 4) + (yy_inner_5 >> 2)) < 25) {
          for (int32_t rc_5 = 0; rc_5 < 128; ++rc_5) {
            for (int32_t ry_3 = 0; ry_3 < 3; ++ry_3) {
              conv1d_ncw_1[(((nn_ff_fused_5 * 100) + (yy_outer_5 * 16)) + yy_inner_5)] = (conv1d_ncw_1[(((nn_ff_fused_5 * 100) + (yy_outer_5 * 16)) + yy_inner_5)] + (pad_temp[((((rc_5 * 104) + (yy_outer_5 * 16)) + (ry_3 * 2)) + yy_inner_5)] * ph_12[(((nn_ff_fused_5 * 384) + (rc_5 * 3)) + ry_3)]));
            }
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_7 = 0; i0_i1_fused_7 < 128; ++i0_i1_fused_7) {
    for (int32_t i2_outer_7 = 0; i2_outer_7 < 7; ++i2_outer_7) {
      for (int32_t i2_inner_7 = 0; i2_inner_7 < 16; ++i2_inner_7) {
        if (((i2_outer_7 * 4) + (i2_inner_7 >> 2)) < 25) {
          conv1d_ncw_1[(((i0_i1_fused_7 * 100) + (i2_outer_7 * 16)) + i2_inner_7)] = tanhf(conv1d_ncw_1[(((i0_i1_fused_7 * 100) + (i2_outer_7 * 16)) + i2_inner_7)]);
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_8 = 0; i0_i1_fused_8 < 128; ++i0_i1_fused_8) {
    for (int32_t i2_outer_8 = 0; i2_outer_8 < 7; ++i2_outer_8) {
      for (int32_t i2_inner_8 = 0; i2_inner_8 < 16; ++i2_inner_8) {
        if (((i2_outer_8 * 2) + (i2_inner_8 >> 3)) < 13) {
          pad_temp[(((i0_i1_fused_8 * 104) + (i2_outer_8 * 16)) + i2_inner_8)] = ((1 <= ((i2_outer_8 * 4) + (i2_inner_8 >> 2))) ? conv1d_ncw[((((i0_i1_fused_8 * 100) + (i2_outer_8 * 16)) + i2_inner_8) - 4)] : 0.000000e+00f);
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t nn_ff_fused_6 = 0; nn_ff_fused_6 < 128; ++nn_ff_fused_6) {
    for (int32_t yy_outer_6 = 0; yy_outer_6 < 7; ++yy_outer_6) {
      for (int32_t yy_inner_6 = 0; yy_inner_6 < 16; ++yy_inner_6) {
        if (((yy_outer_6 * 4) + (yy_inner_6 >> 2)) < 25) {
          conv1d_ncw_2[(((nn_ff_fused_6 * 100) + (yy_outer_6 * 16)) + yy_inner_6)] = 0.000000e+00f;
        }
        if (((yy_outer_6 * 4) + (yy_inner_6 >> 2)) < 25) {
          for (int32_t rc_6 = 0; rc_6 < 128; ++rc_6) {
            for (int32_t ry_4 = 0; ry_4 < 3; ++ry_4) {
              conv1d_ncw_2[(((nn_ff_fused_6 * 100) + (yy_outer_6 * 16)) + yy_inner_6)] = (conv1d_ncw_2[(((nn_ff_fused_6 * 100) + (yy_outer_6 * 16)) + yy_inner_6)] + (pad_temp[((((rc_6 * 104) + (yy_outer_6 * 16)) + (ry_4 * 2)) + yy_inner_6)] * ph_11[(((nn_ff_fused_6 * 384) + (rc_6 * 3)) + ry_4)]));
            }
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_9 = 0; i0_i1_fused_9 < 128; ++i0_i1_fused_9) {
    for (int32_t i2_outer_9 = 0; i2_outer_9 < 7; ++i2_outer_9) {
      for (int32_t i2_inner_9 = 0; i2_inner_9 < 16; ++i2_inner_9) {
        if (((i2_outer_9 * 4) + (i2_inner_9 >> 2)) < 25) {
          conv1d_ncw_2[(((i0_i1_fused_9 * 100) + (i2_outer_9 * 16)) + i2_inner_9)] = (1.000000e+00f / (1.000000e+00f + expf((0.000000e+00f - conv1d_ncw_2[(((i0_i1_fused_9 * 100) + (i2_outer_9 * 16)) + i2_inner_9)]))));
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_2 = 0; ax0_ax1_fused_2 < 128; ++ax0_ax1_fused_2) {
    for (int32_t ax2_outer_2 = 0; ax2_outer_2 < 7; ++ax2_outer_2) {
      for (int32_t ax2_inner_2 = 0; ax2_inner_2 < 16; ++ax2_inner_2) {
        if (((ax2_outer_2 * 4) + (ax2_inner_2 >> 2)) < 25) {
          conv1d_ncw_1[(((ax0_ax1_fused_2 * 100) + (ax2_outer_2 * 16)) + ax2_inner_2)] = (conv1d_ncw_1[(((ax0_ax1_fused_2 * 100) + (ax2_outer_2 * 16)) + ax2_inner_2)] + conv1d_ncw_2[(((ax0_ax1_fused_2 * 100) + (ax2_outer_2 * 16)) + ax2_inner_2)]);
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_10 = 0; i0_i1_fused_10 < 128; ++i0_i1_fused_10) {
    for (int32_t i2_outer_10 = 0; i2_outer_10 < 7; ++i2_outer_10) {
      for (int32_t i2_inner_10 = 0; i2_inner_10 < 16; ++i2_inner_10) {
        if (((i2_outer_10 * 4) + (i2_inner_10 >> 2)) < 25) {
          conv1d_ncw_2[(((i0_i1_fused_10 * 100) + (i2_outer_10 * 16)) + i2_inner_10)] = conv1d_ncw_1[(((i0_i1_fused_10 * 100) + (i2_outer_10 * 16)) + i2_inner_10)];
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t nn_ff_fused_7 = 0; nn_ff_fused_7 < 128; ++nn_ff_fused_7) {
    for (int32_t yy_outer_7 = 0; yy_outer_7 < 7; ++yy_outer_7) {
      for (int32_t yy_inner_7 = 0; yy_inner_7 < 16; ++yy_inner_7) {
        if (((yy_outer_7 * 4) + (yy_inner_7 >> 2)) < 25) {
          pad_temp[(((nn_ff_fused_7 * 100) + (yy_outer_7 * 16)) + yy_inner_7)] = 0.000000e+00f;
        }
        if (((yy_outer_7 * 4) + (yy_inner_7 >> 2)) < 25) {
          for (int32_t rc_7 = 0; rc_7 < 128; ++rc_7) {
            pad_temp[(((nn_ff_fused_7 * 100) + (yy_outer_7 * 16)) + yy_inner_7)] = (pad_temp[(((nn_ff_fused_7 * 100) + (yy_outer_7 * 16)) + yy_inner_7)] + (conv1d_ncw_2[(((rc_7 * 100) + (yy_outer_7 * 16)) + yy_inner_7)] * ph_10[((nn_ff_fused_7 * 128) + rc_7)]));
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t nn_ff_fused_8 = 0; nn_ff_fused_8 < 128; ++nn_ff_fused_8) {
    for (int32_t yy_outer_8 = 0; yy_outer_8 < 7; ++yy_outer_8) {
      for (int32_t yy_inner_8 = 0; yy_inner_8 < 16; ++yy_inner_8) {
        if (((yy_outer_8 * 4) + (yy_inner_8 >> 2)) < 25) {
          conv1d_ncw_2[(((nn_ff_fused_8 * 100) + (yy_outer_8 * 16)) + yy_inner_8)] = 0.000000e+00f;
        }
        if (((yy_outer_8 * 4) + (yy_inner_8 >> 2)) < 25) {
          for (int32_t rc_8 = 0; rc_8 < 128; ++rc_8) {
            conv1d_ncw_2[(((nn_ff_fused_8 * 100) + (yy_outer_8 * 16)) + yy_inner_8)] = (conv1d_ncw_2[(((nn_ff_fused_8 * 100) + (yy_outer_8 * 16)) + yy_inner_8)] + (conv1d_ncw_1[(((rc_8 * 100) + (yy_outer_8 * 16)) + yy_inner_8)] * ph[((nn_ff_fused_8 * 64) + rc_8)]));
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_3 = 0; ax0_ax1_fused_3 < 128; ++ax0_ax1_fused_3) {
    for (int32_t ax2_outer_3 = 0; ax2_outer_3 < 7; ++ax2_outer_3) {
      for (int32_t ax2_inner_3 = 0; ax2_inner_3 < 16; ++ax2_inner_3) {
        if (((ax2_outer_3 * 4) + (ax2_inner_3 >> 2)) < 25) {
          conv1d_ncw_2[(((ax0_ax1_fused_3 * 100) + (ax2_outer_3 * 16)) + ax2_inner_3)] = (pad_temp[(((ax0_ax1_fused_3 * 100) + (ax2_outer_3 * 16)) + ax2_inner_3)] + conv1d_ncw_2[(((ax0_ax1_fused_3 * 100) + (ax2_outer_3 * 16)) + ax2_inner_3)]);
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_11 = 0; i0_i1_fused_11 < 128; ++i0_i1_fused_11) {
    for (int32_t i2_outer_11 = 0; i2_outer_11 < 7; ++i2_outer_11) {
      for (int32_t i2_inner_11 = 0; i2_inner_11 < 16; ++i2_inner_11) {
        if (((i2_outer_11 * 4) + (i2_inner_11 >> 2)) < 27) {
          pad_temp[(((i0_i1_fused_11 * 108) + (i2_outer_11 * 16)) + i2_inner_11)] = ((1 <= ((i2_outer_11 * 2) + (i2_inner_11 >> 3))) ? conv1d_ncw_2[((((i0_i1_fused_11 * 100) + (i2_outer_11 * 16)) + i2_inner_11) - 8)] : 0.000000e+00f);
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t nn_ff_fused_9 = 0; nn_ff_fused_9 < 128; ++nn_ff_fused_9) {
    for (int32_t yy_outer_9 = 0; yy_outer_9 < 7; ++yy_outer_9) {
      for (int32_t yy_inner_9 = 0; yy_inner_9 < 16; ++yy_inner_9) {
        if (((yy_outer_9 * 4) + (yy_inner_9 >> 2)) < 25) {
          conv1d_ncw_1[(((nn_ff_fused_9 * 100) + (yy_outer_9 * 16)) + yy_inner_9)] = 0.000000e+00f;
        }
        if (((yy_outer_9 * 4) + (yy_inner_9 >> 2)) < 25) {
          for (int32_t rc_9 = 0; rc_9 < 128; ++rc_9) {
            for (int32_t ry_5 = 0; ry_5 < 3; ++ry_5) {
              conv1d_ncw_1[(((nn_ff_fused_9 * 100) + (yy_outer_9 * 16)) + yy_inner_9)] = (conv1d_ncw_1[(((nn_ff_fused_9 * 100) + (yy_outer_9 * 16)) + yy_inner_9)] + (pad_temp[((((rc_9 * 108) + (yy_outer_9 * 16)) + (ry_5 * 4)) + yy_inner_9)] * ph_8[(((nn_ff_fused_9 * 384) + (rc_9 * 3)) + ry_5)]));
            }
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_12 = 0; i0_i1_fused_12 < 128; ++i0_i1_fused_12) {
    for (int32_t i2_outer_12 = 0; i2_outer_12 < 7; ++i2_outer_12) {
      for (int32_t i2_inner_12 = 0; i2_inner_12 < 16; ++i2_inner_12) {
        if (((i2_outer_12 * 4) + (i2_inner_12 >> 2)) < 25) {
          conv1d_ncw_1[(((i0_i1_fused_12 * 100) + (i2_outer_12 * 16)) + i2_inner_12)] = tanhf(conv1d_ncw_1[(((i0_i1_fused_12 * 100) + (i2_outer_12 * 16)) + i2_inner_12)]);
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_13 = 0; i0_i1_fused_13 < 128; ++i0_i1_fused_13) {
    for (int32_t i2_outer_13 = 0; i2_outer_13 < 7; ++i2_outer_13) {
      for (int32_t i2_inner_13 = 0; i2_inner_13 < 16; ++i2_inner_13) {
        if (((i2_outer_13 * 4) + (i2_inner_13 >> 2)) < 27) {
          pad_temp[(((i0_i1_fused_13 * 108) + (i2_outer_13 * 16)) + i2_inner_13)] = ((1 <= ((i2_outer_13 * 2) + (i2_inner_13 >> 3))) ? conv1d_ncw_2[((((i0_i1_fused_13 * 100) + (i2_outer_13 * 16)) + i2_inner_13) - 8)] : 0.000000e+00f);
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t nn_ff_fused_10 = 0; nn_ff_fused_10 < 128; ++nn_ff_fused_10) {
    for (int32_t yy_outer_10 = 0; yy_outer_10 < 7; ++yy_outer_10) {
      for (int32_t yy_inner_10 = 0; yy_inner_10 < 16; ++yy_inner_10) {
        if (((yy_outer_10 * 4) + (yy_inner_10 >> 2)) < 25) {
          conv1d_ncw_3[(((nn_ff_fused_10 * 100) + (yy_outer_10 * 16)) + yy_inner_10)] = 0.000000e+00f;
        }
        if (((yy_outer_10 * 4) + (yy_inner_10 >> 2)) < 25) {
          for (int32_t rc_10 = 0; rc_10 < 128; ++rc_10) {
            for (int32_t ry_6 = 0; ry_6 < 3; ++ry_6) {
              conv1d_ncw_3[(((nn_ff_fused_10 * 100) + (yy_outer_10 * 16)) + yy_inner_10)] = (conv1d_ncw_3[(((nn_ff_fused_10 * 100) + (yy_outer_10 * 16)) + yy_inner_10)] + (pad_temp[((((rc_10 * 108) + (yy_outer_10 * 16)) + (ry_6 * 4)) + yy_inner_10)] * ph_7[(((nn_ff_fused_10 * 384) + (rc_10 * 3)) + ry_6)]));
            }
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_14 = 0; i0_i1_fused_14 < 128; ++i0_i1_fused_14) {
    for (int32_t i2_outer_14 = 0; i2_outer_14 < 7; ++i2_outer_14) {
      for (int32_t i2_inner_14 = 0; i2_inner_14 < 16; ++i2_inner_14) {
        if (((i2_outer_14 * 4) + (i2_inner_14 >> 2)) < 25) {
          conv1d_ncw_3[(((i0_i1_fused_14 * 100) + (i2_outer_14 * 16)) + i2_inner_14)] = (1.000000e+00f / (1.000000e+00f + expf((0.000000e+00f - conv1d_ncw_3[(((i0_i1_fused_14 * 100) + (i2_outer_14 * 16)) + i2_inner_14)]))));
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_4 = 0; ax0_ax1_fused_4 < 128; ++ax0_ax1_fused_4) {
    for (int32_t ax2_outer_4 = 0; ax2_outer_4 < 7; ++ax2_outer_4) {
      for (int32_t ax2_inner_4 = 0; ax2_inner_4 < 16; ++ax2_inner_4) {
        if (((ax2_outer_4 * 4) + (ax2_inner_4 >> 2)) < 25) {
          conv1d_ncw_1[(((ax0_ax1_fused_4 * 100) + (ax2_outer_4 * 16)) + ax2_inner_4)] = (conv1d_ncw_1[(((ax0_ax1_fused_4 * 100) + (ax2_outer_4 * 16)) + ax2_inner_4)] + conv1d_ncw_3[(((ax0_ax1_fused_4 * 100) + (ax2_outer_4 * 16)) + ax2_inner_4)]);
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_15 = 0; i0_i1_fused_15 < 128; ++i0_i1_fused_15) {
    for (int32_t i2_outer_15 = 0; i2_outer_15 < 7; ++i2_outer_15) {
      for (int32_t i2_inner_15 = 0; i2_inner_15 < 16; ++i2_inner_15) {
        if (((i2_outer_15 * 4) + (i2_inner_15 >> 2)) < 25) {
          conv1d_ncw_3[(((i0_i1_fused_15 * 100) + (i2_outer_15 * 16)) + i2_inner_15)] = conv1d_ncw_1[(((i0_i1_fused_15 * 100) + (i2_outer_15 * 16)) + i2_inner_15)];
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t nn_ff_fused_11 = 0; nn_ff_fused_11 < 128; ++nn_ff_fused_11) {
    for (int32_t yy_outer_11 = 0; yy_outer_11 < 7; ++yy_outer_11) {
      for (int32_t yy_inner_11 = 0; yy_inner_11 < 16; ++yy_inner_11) {
        if (((yy_outer_11 * 4) + (yy_inner_11 >> 2)) < 25) {
          pad_temp[(((nn_ff_fused_11 * 100) + (yy_outer_11 * 16)) + yy_inner_11)] = 0.000000e+00f;
        }
        if (((yy_outer_11 * 4) + (yy_inner_11 >> 2)) < 25) {
          for (int32_t rc_11 = 0; rc_11 < 128; ++rc_11) {
            pad_temp[(((nn_ff_fused_11 * 100) + (yy_outer_11 * 16)) + yy_inner_11)] = (pad_temp[(((nn_ff_fused_11 * 100) + (yy_outer_11 * 16)) + yy_inner_11)] + (conv1d_ncw_3[(((rc_11 * 100) + (yy_outer_11 * 16)) + yy_inner_11)] * ph_6[((nn_ff_fused_11 * 128) + rc_11)]));
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t nn_ff_fused_12 = 0; nn_ff_fused_12 < 128; ++nn_ff_fused_12) {
    for (int32_t yy_outer_12 = 0; yy_outer_12 < 7; ++yy_outer_12) {
      for (int32_t yy_inner_12 = 0; yy_inner_12 < 16; ++yy_inner_12) {
        if (((yy_outer_12 * 4) + (yy_inner_12 >> 2)) < 25) {
          conv1d_ncw_3[(((nn_ff_fused_12 * 100) + (yy_outer_12 * 16)) + yy_inner_12)] = 0.000000e+00f;
        }
        if (((yy_outer_12 * 4) + (yy_inner_12 >> 2)) < 25) {
          for (int32_t rc_12 = 0; rc_12 < 128; ++rc_12) {
            conv1d_ncw_3[(((nn_ff_fused_12 * 100) + (yy_outer_12 * 16)) + yy_inner_12)] = (conv1d_ncw_3[(((nn_ff_fused_12 * 100) + (yy_outer_12 * 16)) + yy_inner_12)] + (conv1d_ncw_1[(((rc_12 * 100) + (yy_outer_12 * 16)) + yy_inner_12)] * ph_5[((nn_ff_fused_12 * 64) + rc_12)]));
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_5 = 0; ax0_ax1_fused_5 < 128; ++ax0_ax1_fused_5) {
    for (int32_t ax2_outer_5 = 0; ax2_outer_5 < 7; ++ax2_outer_5) {
      for (int32_t ax2_inner_5 = 0; ax2_inner_5 < 16; ++ax2_inner_5) {
        if (((ax2_outer_5 * 4) + (ax2_inner_5 >> 2)) < 25) {
          conv1d_ncw_3[(((ax0_ax1_fused_5 * 100) + (ax2_outer_5 * 16)) + ax2_inner_5)] = (pad_temp[(((ax0_ax1_fused_5 * 100) + (ax2_outer_5 * 16)) + ax2_inner_5)] + conv1d_ncw_3[(((ax0_ax1_fused_5 * 100) + (ax2_outer_5 * 16)) + ax2_inner_5)]);
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_16 = 0; i0_i1_fused_16 < 128; ++i0_i1_fused_16) {
    for (int32_t i2_outer_16 = 0; i2_outer_16 < 8; ++i2_outer_16) {
      for (int32_t i2_inner_16 = 0; i2_inner_16 < 16; ++i2_inner_16) {
        if (((i2_outer_16 * 4) + (i2_inner_16 >> 2)) < 29) {
          pad_temp[(((i0_i1_fused_16 * 116) + (i2_outer_16 * 16)) + i2_inner_16)] = ((1 <= i2_outer_16) ? conv1d_ncw_3[((((i0_i1_fused_16 * 100) + (i2_outer_16 * 16)) + i2_inner_16) - 16)] : 0.000000e+00f);
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t nn_ff_fused_13 = 0; nn_ff_fused_13 < 128; ++nn_ff_fused_13) {
    for (int32_t yy_outer_13 = 0; yy_outer_13 < 7; ++yy_outer_13) {
      for (int32_t yy_inner_13 = 0; yy_inner_13 < 16; ++yy_inner_13) {
        if (((yy_outer_13 * 4) + (yy_inner_13 >> 2)) < 25) {
          conv1d_ncw_1[(((nn_ff_fused_13 * 100) + (yy_outer_13 * 16)) + yy_inner_13)] = 0.000000e+00f;
        }
        if (((yy_outer_13 * 4) + (yy_inner_13 >> 2)) < 25) {
          for (int32_t rc_13 = 0; rc_13 < 128; ++rc_13) {
            for (int32_t ry_7 = 0; ry_7 < 3; ++ry_7) {
              conv1d_ncw_1[(((nn_ff_fused_13 * 100) + (yy_outer_13 * 16)) + yy_inner_13)] = (conv1d_ncw_1[(((nn_ff_fused_13 * 100) + (yy_outer_13 * 16)) + yy_inner_13)] + (pad_temp[((((rc_13 * 116) + (yy_outer_13 * 16)) + (ry_7 * 8)) + yy_inner_13)] * ph_4[(((nn_ff_fused_13 * 384) + (rc_13 * 3)) + ry_7)]));
            }
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_17 = 0; i0_i1_fused_17 < 128; ++i0_i1_fused_17) {
    for (int32_t i2_outer_17 = 0; i2_outer_17 < 7; ++i2_outer_17) {
      for (int32_t i2_inner_17 = 0; i2_inner_17 < 16; ++i2_inner_17) {
        if (((i2_outer_17 * 4) + (i2_inner_17 >> 2)) < 25) {
          conv1d_ncw_1[(((i0_i1_fused_17 * 100) + (i2_outer_17 * 16)) + i2_inner_17)] = tanhf(conv1d_ncw_1[(((i0_i1_fused_17 * 100) + (i2_outer_17 * 16)) + i2_inner_17)]);
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_18 = 0; i0_i1_fused_18 < 128; ++i0_i1_fused_18) {
    for (int32_t i2_outer_18 = 0; i2_outer_18 < 8; ++i2_outer_18) {
      for (int32_t i2_inner_18 = 0; i2_inner_18 < 16; ++i2_inner_18) {
        if (((i2_outer_18 * 4) + (i2_inner_18 >> 2)) < 29) {
          pad_temp[(((i0_i1_fused_18 * 116) + (i2_outer_18 * 16)) + i2_inner_18)] = ((1 <= i2_outer_18) ? conv1d_ncw_3[((((i0_i1_fused_18 * 100) + (i2_outer_18 * 16)) + i2_inner_18) - 16)] : 0.000000e+00f);
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t nn_ff_fused_14 = 0; nn_ff_fused_14 < 128; ++nn_ff_fused_14) {
    for (int32_t yy_outer_14 = 0; yy_outer_14 < 7; ++yy_outer_14) {
      for (int32_t yy_inner_14 = 0; yy_inner_14 < 16; ++yy_inner_14) {
        if (((yy_outer_14 * 4) + (yy_inner_14 >> 2)) < 25) {
          conv1d_ncw_4[(((nn_ff_fused_14 * 100) + (yy_outer_14 * 16)) + yy_inner_14)] = 0.000000e+00f;
        }
        if (((yy_outer_14 * 4) + (yy_inner_14 >> 2)) < 25) {
          for (int32_t rc_14 = 0; rc_14 < 128; ++rc_14) {
            for (int32_t ry_8 = 0; ry_8 < 3; ++ry_8) {
              conv1d_ncw_4[(((nn_ff_fused_14 * 100) + (yy_outer_14 * 16)) + yy_inner_14)] = (conv1d_ncw_4[(((nn_ff_fused_14 * 100) + (yy_outer_14 * 16)) + yy_inner_14)] + (pad_temp[((((rc_14 * 116) + (yy_outer_14 * 16)) + (ry_8 * 8)) + yy_inner_14)] * ph_3[(((nn_ff_fused_14 * 384) + (rc_14 * 3)) + ry_8)]));
            }
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_19 = 0; i0_i1_fused_19 < 128; ++i0_i1_fused_19) {
    for (int32_t i2_outer_19 = 0; i2_outer_19 < 7; ++i2_outer_19) {
      for (int32_t i2_inner_19 = 0; i2_inner_19 < 16; ++i2_inner_19) {
        if (((i2_outer_19 * 4) + (i2_inner_19 >> 2)) < 25) {
          conv1d_ncw_4[(((i0_i1_fused_19 * 100) + (i2_outer_19 * 16)) + i2_inner_19)] = (1.000000e+00f / (1.000000e+00f + expf((0.000000e+00f - conv1d_ncw_4[(((i0_i1_fused_19 * 100) + (i2_outer_19 * 16)) + i2_inner_19)]))));
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_6 = 0; ax0_ax1_fused_6 < 128; ++ax0_ax1_fused_6) {
    for (int32_t ax2_outer_6 = 0; ax2_outer_6 < 7; ++ax2_outer_6) {
      for (int32_t ax2_inner_6 = 0; ax2_inner_6 < 16; ++ax2_inner_6) {
        if (((ax2_outer_6 * 4) + (ax2_inner_6 >> 2)) < 25) {
          conv1d_ncw_1[(((ax0_ax1_fused_6 * 100) + (ax2_outer_6 * 16)) + ax2_inner_6)] = (conv1d_ncw_1[(((ax0_ax1_fused_6 * 100) + (ax2_outer_6 * 16)) + ax2_inner_6)] + conv1d_ncw_4[(((ax0_ax1_fused_6 * 100) + (ax2_outer_6 * 16)) + ax2_inner_6)]);
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_20 = 0; i0_i1_fused_20 < 128; ++i0_i1_fused_20) {
    for (int32_t i2_outer_20 = 0; i2_outer_20 < 7; ++i2_outer_20) {
      for (int32_t i2_inner_20 = 0; i2_inner_20 < 16; ++i2_inner_20) {
        if (((i2_outer_20 * 4) + (i2_inner_20 >> 2)) < 25) {
          conv1d_ncw_4[(((i0_i1_fused_20 * 100) + (i2_outer_20 * 16)) + i2_inner_20)] = conv1d_ncw_1[(((i0_i1_fused_20 * 100) + (i2_outer_20 * 16)) + i2_inner_20)];
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t nn_ff_fused_15 = 0; nn_ff_fused_15 < 128; ++nn_ff_fused_15) {
    for (int32_t yy_outer_15 = 0; yy_outer_15 < 7; ++yy_outer_15) {
      for (int32_t yy_inner_15 = 0; yy_inner_15 < 16; ++yy_inner_15) {
        if (((yy_outer_15 * 4) + (yy_inner_15 >> 2)) < 25) {
          pad_temp[(((nn_ff_fused_15 * 100) + (yy_outer_15 * 16)) + yy_inner_15)] = 0.000000e+00f;
        }
        if (((yy_outer_15 * 4) + (yy_inner_15 >> 2)) < 25) {
          for (int32_t rc_15 = 0; rc_15 < 128; ++rc_15) {
            pad_temp[(((nn_ff_fused_15 * 100) + (yy_outer_15 * 16)) + yy_inner_15)] = (pad_temp[(((nn_ff_fused_15 * 100) + (yy_outer_15 * 16)) + yy_inner_15)] + (conv1d_ncw_4[(((rc_15 * 100) + (yy_outer_15 * 16)) + yy_inner_15)] * ph_2[((nn_ff_fused_15 * 128) + rc_15)]));
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t nn_ff_fused_16 = 0; nn_ff_fused_16 < 128; ++nn_ff_fused_16) {
    for (int32_t yy_outer_16 = 0; yy_outer_16 < 7; ++yy_outer_16) {
      for (int32_t yy_inner_16 = 0; yy_inner_16 < 16; ++yy_inner_16) {
        if (((yy_outer_16 * 4) + (yy_inner_16 >> 2)) < 25) {
          conv1d_ncw_4[(((nn_ff_fused_16 * 100) + (yy_outer_16 * 16)) + yy_inner_16)] = 0.000000e+00f;
        }
        if (((yy_outer_16 * 4) + (yy_inner_16 >> 2)) < 25) {
          for (int32_t rc_16 = 0; rc_16 < 128; ++rc_16) {
            conv1d_ncw_4[(((nn_ff_fused_16 * 100) + (yy_outer_16 * 16)) + yy_inner_16)] = (conv1d_ncw_4[(((nn_ff_fused_16 * 100) + (yy_outer_16 * 16)) + yy_inner_16)] + (conv1d_ncw_1[(((rc_16 * 100) + (yy_outer_16 * 16)) + yy_inner_16)] * ph_1[((nn_ff_fused_16 * 64) + rc_16)]));
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_7 = 0; ax0_ax1_fused_7 < 128; ++ax0_ax1_fused_7) {
    for (int32_t ax2_outer_7 = 0; ax2_outer_7 < 7; ++ax2_outer_7) {
      for (int32_t ax2_inner_7 = 0; ax2_inner_7 < 16; ++ax2_inner_7) {
        if (((ax2_outer_7 * 4) + (ax2_inner_7 >> 2)) < 25) {
          conv1d_ncw_4[(((ax0_ax1_fused_7 * 100) + (ax2_outer_7 * 16)) + ax2_inner_7)] = (pad_temp[(((ax0_ax1_fused_7 * 100) + (ax2_outer_7 * 16)) + ax2_inner_7)] + conv1d_ncw_4[(((ax0_ax1_fused_7 * 100) + (ax2_outer_7 * 16)) + ax2_inner_7)]);
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_8 = 0; ax0_ax1_fused_8 < 512; ++ax0_ax1_fused_8) {
    for (int32_t ax2_outer_8 = 0; ax2_outer_8 < 7; ++ax2_outer_8) {
      for (int32_t ax2_inner_8 = 0; ax2_inner_8 < 16; ++ax2_inner_8) {
        if (((ax2_outer_8 * 4) + (ax2_inner_8 >> 2)) < 25) {
          T_concat[(((ax0_ax1_fused_8 * 100) + (ax2_outer_8 * 16)) + ax2_inner_8)] = ((384 <= ax0_ax1_fused_8) ? conv1d_ncw_4[((((ax0_ax1_fused_8 * 100) + (ax2_outer_8 * 16)) + ax2_inner_8) - 38400)] : ((256 <= ax0_ax1_fused_8) ? conv1d_ncw_3[((((ax0_ax1_fused_8 * 100) + (ax2_outer_8 * 16)) + ax2_inner_8) - 25600)] : ((128 <= ax0_ax1_fused_8) ? conv1d_ncw_2[((((ax0_ax1_fused_8 * 100) + (ax2_outer_8 * 16)) + ax2_inner_8) - 12800)] : conv1d_ncw[(((ax0_ax1_fused_8 * 100) + (ax2_outer_8 * 16)) + ax2_inner_8)])));
        }
      }
    }
  }
}
