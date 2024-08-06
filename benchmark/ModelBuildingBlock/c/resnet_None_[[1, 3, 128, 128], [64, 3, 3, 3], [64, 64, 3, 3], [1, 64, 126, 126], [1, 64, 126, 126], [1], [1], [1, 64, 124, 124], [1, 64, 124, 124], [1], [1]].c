void default_function_kernel(float* compute, float* ph, float* ph_1, float* ph_2, float* ph_3, float* ph_4, float* ph_5, float* ph_6, float* ph_7, float* ph_8, float* ph_9, float* ph_10) {
  float pad_temp[49152];
  float conv2d_nchw[1016064];
  float T_reshape[64];
  float conv2d_nchw_1[984064];
  #pragma omp parallel for
  for (int32_t i0_i1_fused = 0; i0_i1_fused < 3; ++i0_i1_fused) {
    for (int32_t i2 = 0; i2 < 128; ++i2) {
      for (int32_t i3_outer = 0; i3_outer < 8; ++i3_outer) {
        for (int32_t i3_inner = 0; i3_inner < 16; ++i3_inner) {
          pad_temp[((((i0_i1_fused * 16384) + (i2 * 128)) + (i3_outer * 16)) + i3_inner)] = ph[((((i0_i1_fused * 16384) + (i2 * 128)) + (i3_outer * 16)) + i3_inner)];
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t nn_ff_fused = 0; nn_ff_fused < 64; ++nn_ff_fused) {
    for (int32_t yy = 0; yy < 126; ++yy) {
      for (int32_t xx_outer = 0; xx_outer < 8; ++xx_outer) {
        for (int32_t xx_inner = 0; xx_inner < 16; ++xx_inner) {
          if (((xx_outer * 8) + (xx_inner >> 1)) < 63) {
            conv2d_nchw[((((nn_ff_fused * 15876) + (yy * 126)) + (xx_outer * 16)) + xx_inner)] = 0.000000e+00f;
          }
          if (((xx_outer * 8) + (xx_inner >> 1)) < 63) {
            for (int32_t rc = 0; rc < 3; ++rc) {
              for (int32_t ry = 0; ry < 3; ++ry) {
                for (int32_t rx = 0; rx < 3; ++rx) {
                  conv2d_nchw[((((nn_ff_fused * 15876) + (yy * 126)) + (xx_outer * 16)) + xx_inner)] = (conv2d_nchw[((((nn_ff_fused * 15876) + (yy * 126)) + (xx_outer * 16)) + xx_inner)] + (pad_temp[((((((rc * 16384) + (yy * 128)) + (ry * 128)) + (xx_outer * 16)) + xx_inner) + rx)] * ph_1[((((nn_ff_fused * 27) + (rc * 9)) + (ry * 3)) + rx)]));
                }
              }
            }
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused = 0; ax0_ax1_fused < 64; ++ax0_ax1_fused) {
    T_reshape[ax0_ax1_fused] = ph_2[ax0_ax1_fused];
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_1 = 0; ax0_ax1_fused_1 < 64; ++ax0_ax1_fused_1) {
    for (int32_t ax2 = 0; ax2 < 126; ++ax2) {
      for (int32_t ax3_outer = 0; ax3_outer < 8; ++ax3_outer) {
        for (int32_t ax3_inner = 0; ax3_inner < 16; ++ax3_inner) {
          if (((ax3_outer * 8) + (ax3_inner >> 1)) < 63) {
            conv2d_nchw[((((ax0_ax1_fused_1 * 15876) + (ax2 * 126)) + (ax3_outer * 16)) + ax3_inner)] = (conv2d_nchw[((((ax0_ax1_fused_1 * 15876) + (ax2 * 126)) + (ax3_outer * 16)) + ax3_inner)] - T_reshape[ax0_ax1_fused_1]);
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_2 = 0; ax0_ax1_fused_2 < 64; ++ax0_ax1_fused_2) {
    T_reshape[ax0_ax1_fused_2] = ph_3[ax0_ax1_fused_2];
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_3 = 0; ax0_ax1_fused_3 < 64; ++ax0_ax1_fused_3) {
    T_reshape[ax0_ax1_fused_3] = (T_reshape[ax0_ax1_fused_3] + 1.000000e-05f);
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_1 = 0; i0_i1_fused_1 < 64; ++i0_i1_fused_1) {
    T_reshape[i0_i1_fused_1] = sqrtf(T_reshape[i0_i1_fused_1]);
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_4 = 0; ax0_ax1_fused_4 < 64; ++ax0_ax1_fused_4) {
    for (int32_t ax2_1 = 0; ax2_1 < 126; ++ax2_1) {
      for (int32_t ax3_outer_1 = 0; ax3_outer_1 < 8; ++ax3_outer_1) {
        for (int32_t ax3_inner_1 = 0; ax3_inner_1 < 16; ++ax3_inner_1) {
          if (((ax3_outer_1 * 8) + (ax3_inner_1 >> 1)) < 63) {
            conv2d_nchw[((((ax0_ax1_fused_4 * 15876) + (ax2_1 * 126)) + (ax3_outer_1 * 16)) + ax3_inner_1)] = (conv2d_nchw[((((ax0_ax1_fused_4 * 15876) + (ax2_1 * 126)) + (ax3_outer_1 * 16)) + ax3_inner_1)] / T_reshape[ax0_ax1_fused_4]);
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_5 = 0; ax0_ax1_fused_5 < 64; ++ax0_ax1_fused_5) {
    T_reshape[ax0_ax1_fused_5] = ph_4[0];
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_6 = 0; ax0_ax1_fused_6 < 64; ++ax0_ax1_fused_6) {
    for (int32_t ax2_2 = 0; ax2_2 < 126; ++ax2_2) {
      for (int32_t ax3_outer_2 = 0; ax3_outer_2 < 8; ++ax3_outer_2) {
        for (int32_t ax3_inner_2 = 0; ax3_inner_2 < 16; ++ax3_inner_2) {
          if (((ax3_outer_2 * 8) + (ax3_inner_2 >> 1)) < 63) {
            conv2d_nchw[((((ax0_ax1_fused_6 * 15876) + (ax2_2 * 126)) + (ax3_outer_2 * 16)) + ax3_inner_2)] = (conv2d_nchw[((((ax0_ax1_fused_6 * 15876) + (ax2_2 * 126)) + (ax3_outer_2 * 16)) + ax3_inner_2)] * T_reshape[ax0_ax1_fused_6]);
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_7 = 0; ax0_ax1_fused_7 < 64; ++ax0_ax1_fused_7) {
    T_reshape[ax0_ax1_fused_7] = ph_5[0];
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_8 = 0; ax0_ax1_fused_8 < 64; ++ax0_ax1_fused_8) {
    for (int32_t ax2_3 = 0; ax2_3 < 126; ++ax2_3) {
      for (int32_t ax3_outer_3 = 0; ax3_outer_3 < 8; ++ax3_outer_3) {
        for (int32_t ax3_inner_3 = 0; ax3_inner_3 < 16; ++ax3_inner_3) {
          if (((ax3_outer_3 * 8) + (ax3_inner_3 >> 1)) < 63) {
            conv2d_nchw[((((ax0_ax1_fused_8 * 15876) + (ax2_3 * 126)) + (ax3_outer_3 * 16)) + ax3_inner_3)] = (conv2d_nchw[((((ax0_ax1_fused_8 * 15876) + (ax2_3 * 126)) + (ax3_outer_3 * 16)) + ax3_inner_3)] + T_reshape[ax0_ax1_fused_8]);
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_2 = 0; i0_i1_fused_2 < 64; ++i0_i1_fused_2) {
    for (int32_t i2_1 = 0; i2_1 < 126; ++i2_1) {
      for (int32_t i3_outer_1 = 0; i3_outer_1 < 8; ++i3_outer_1) {
        for (int32_t i3_inner_1 = 0; i3_inner_1 < 16; ++i3_inner_1) {
          if (((i3_outer_1 * 8) + (i3_inner_1 >> 1)) < 63) {
            conv2d_nchw[((((i0_i1_fused_2 * 15876) + (i2_1 * 126)) + (i3_outer_1 * 16)) + i3_inner_1)] = max(conv2d_nchw[((((i0_i1_fused_2 * 15876) + (i2_1 * 126)) + (i3_outer_1 * 16)) + i3_inner_1)], 0.000000e+00f);
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t nn_ff_fused_1 = 0; nn_ff_fused_1 < 64; ++nn_ff_fused_1) {
    for (int32_t yy_1 = 0; yy_1 < 124; ++yy_1) {
      for (int32_t xx_outer_1 = 0; xx_outer_1 < 8; ++xx_outer_1) {
        for (int32_t xx_inner_1 = 0; xx_inner_1 < 16; ++xx_inner_1) {
          if (((xx_outer_1 * 4) + (xx_inner_1 >> 2)) < 31) {
            conv2d_nchw_1[((((nn_ff_fused_1 * 15376) + (yy_1 * 124)) + (xx_outer_1 * 16)) + xx_inner_1)] = 0.000000e+00f;
          }
          if (((xx_outer_1 * 4) + (xx_inner_1 >> 2)) < 31) {
            for (int32_t rc_1 = 0; rc_1 < 64; ++rc_1) {
              for (int32_t ry_1 = 0; ry_1 < 3; ++ry_1) {
                for (int32_t rx_1 = 0; rx_1 < 3; ++rx_1) {
                  conv2d_nchw_1[((((nn_ff_fused_1 * 15376) + (yy_1 * 124)) + (xx_outer_1 * 16)) + xx_inner_1)] = (conv2d_nchw_1[((((nn_ff_fused_1 * 15376) + (yy_1 * 124)) + (xx_outer_1 * 16)) + xx_inner_1)] + (conv2d_nchw[((((((rc_1 * 15876) + (yy_1 * 126)) + (ry_1 * 126)) + (xx_outer_1 * 16)) + xx_inner_1) + rx_1)] * ph_6[((((nn_ff_fused_1 * 576) + (rc_1 * 9)) + (ry_1 * 3)) + rx_1)]));
                }
              }
            }
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_9 = 0; ax0_ax1_fused_9 < 64; ++ax0_ax1_fused_9) {
    T_reshape[ax0_ax1_fused_9] = ph_7[ax0_ax1_fused_9];
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_10 = 0; ax0_ax1_fused_10 < 64; ++ax0_ax1_fused_10) {
    for (int32_t ax2_4 = 0; ax2_4 < 124; ++ax2_4) {
      for (int32_t ax3_outer_4 = 0; ax3_outer_4 < 8; ++ax3_outer_4) {
        for (int32_t ax3_inner_4 = 0; ax3_inner_4 < 16; ++ax3_inner_4) {
          if (((ax3_outer_4 * 4) + (ax3_inner_4 >> 2)) < 31) {
            conv2d_nchw_1[((((ax0_ax1_fused_10 * 15376) + (ax2_4 * 124)) + (ax3_outer_4 * 16)) + ax3_inner_4)] = (conv2d_nchw_1[((((ax0_ax1_fused_10 * 15376) + (ax2_4 * 124)) + (ax3_outer_4 * 16)) + ax3_inner_4)] - T_reshape[ax0_ax1_fused_10]);
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_11 = 0; ax0_ax1_fused_11 < 64; ++ax0_ax1_fused_11) {
    T_reshape[ax0_ax1_fused_11] = ph_8[ax0_ax1_fused_11];
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_12 = 0; ax0_ax1_fused_12 < 64; ++ax0_ax1_fused_12) {
    T_reshape[ax0_ax1_fused_12] = (T_reshape[ax0_ax1_fused_12] + 1.000000e-05f);
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_3 = 0; i0_i1_fused_3 < 64; ++i0_i1_fused_3) {
    T_reshape[i0_i1_fused_3] = sqrtf(T_reshape[i0_i1_fused_3]);
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_13 = 0; ax0_ax1_fused_13 < 64; ++ax0_ax1_fused_13) {
    for (int32_t ax2_5 = 0; ax2_5 < 124; ++ax2_5) {
      for (int32_t ax3_outer_5 = 0; ax3_outer_5 < 8; ++ax3_outer_5) {
        for (int32_t ax3_inner_5 = 0; ax3_inner_5 < 16; ++ax3_inner_5) {
          if (((ax3_outer_5 * 4) + (ax3_inner_5 >> 2)) < 31) {
            conv2d_nchw_1[((((ax0_ax1_fused_13 * 15376) + (ax2_5 * 124)) + (ax3_outer_5 * 16)) + ax3_inner_5)] = (conv2d_nchw_1[((((ax0_ax1_fused_13 * 15376) + (ax2_5 * 124)) + (ax3_outer_5 * 16)) + ax3_inner_5)] / T_reshape[ax0_ax1_fused_13]);
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_14 = 0; ax0_ax1_fused_14 < 64; ++ax0_ax1_fused_14) {
    T_reshape[ax0_ax1_fused_14] = ph_9[0];
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_15 = 0; ax0_ax1_fused_15 < 64; ++ax0_ax1_fused_15) {
    for (int32_t ax2_6 = 0; ax2_6 < 124; ++ax2_6) {
      for (int32_t ax3_outer_6 = 0; ax3_outer_6 < 8; ++ax3_outer_6) {
        for (int32_t ax3_inner_6 = 0; ax3_inner_6 < 16; ++ax3_inner_6) {
          if (((ax3_outer_6 * 4) + (ax3_inner_6 >> 2)) < 31) {
            conv2d_nchw_1[((((ax0_ax1_fused_15 * 15376) + (ax2_6 * 124)) + (ax3_outer_6 * 16)) + ax3_inner_6)] = (conv2d_nchw_1[((((ax0_ax1_fused_15 * 15376) + (ax2_6 * 124)) + (ax3_outer_6 * 16)) + ax3_inner_6)] * T_reshape[ax0_ax1_fused_15]);
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_16 = 0; ax0_ax1_fused_16 < 64; ++ax0_ax1_fused_16) {
    T_reshape[ax0_ax1_fused_16] = ph_10[0];
  }
  #pragma omp parallel for
  for (int32_t ax0_ax1_fused_17 = 0; ax0_ax1_fused_17 < 64; ++ax0_ax1_fused_17) {
    for (int32_t ax2_7 = 0; ax2_7 < 124; ++ax2_7) {
      for (int32_t ax3_outer_7 = 0; ax3_outer_7 < 8; ++ax3_outer_7) {
        for (int32_t ax3_inner_7 = 0; ax3_inner_7 < 16; ++ax3_inner_7) {
          if (((ax3_outer_7 * 4) + (ax3_inner_7 >> 2)) < 31) {
            conv2d_nchw_1[((((ax0_ax1_fused_17 * 15376) + (ax2_7 * 124)) + (ax3_outer_7 * 16)) + ax3_inner_7)] = (conv2d_nchw_1[((((ax0_ax1_fused_17 * 15376) + (ax2_7 * 124)) + (ax3_outer_7 * 16)) + ax3_inner_7)] + T_reshape[ax0_ax1_fused_17]);
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_i1_fused_4 = 0; i0_i1_fused_4 < 64; ++i0_i1_fused_4) {
    for (int32_t i2_2 = 0; i2_2 < 124; ++i2_2) {
      for (int32_t i3_outer_2 = 0; i3_outer_2 < 8; ++i3_outer_2) {
        for (int32_t i3_inner_2 = 0; i3_inner_2 < 16; ++i3_inner_2) {
          if (((i3_outer_2 * 4) + (i3_inner_2 >> 2)) < 31) {
            compute[((((i0_i1_fused_4 * 15376) + (i2_2 * 124)) + (i3_outer_2 * 16)) + i3_inner_2)] = max(conv2d_nchw_1[((((i0_i1_fused_4 * 15376) + (i2_2 * 124)) + (i3_outer_2 * 16)) + i3_inner_2)], 0.000000e+00f);
          }
        }
      }
    }
  }
}

