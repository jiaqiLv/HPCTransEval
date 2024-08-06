void default_function_kernel(float* T_add, float* ph, float* ph_1, float* ph_2, float* ph_3, float* ph_4, float* ph_5, float* ph_6, float* ph_7, float* ph_8, float* ph_9, float* ph_10, float* ph_11, float* ph_12) {
  float T_matmul_NN[512];
  float T_matmul_NN_1[512];
  float T_matmul_NN_2[512];
  float T_matmul_NN_3[512];
  float T_matmul_NN_4[512];
  #pragma omp parallel for
  for (int32_t i0 = 0; i0 < 2; ++i0) {
    for (int32_t i1_outer = 0; i1_outer < 16; ++i1_outer) {
      for (int32_t i1_inner = 0; i1_inner < 16; ++i1_inner) {
        T_matmul_NN[(((i0 * 256) + (i1_outer * 16)) + i1_inner)] = 0.000000e+00f;
        for (int32_t k = 0; k < 1000; ++k) {
          T_matmul_NN[(((i0 * 256) + (i1_outer * 16)) + i1_inner)] = (T_matmul_NN[(((i0 * 256) + (i1_outer * 16)) + i1_inner)] + (ph[((i0 * 1000) + k)] * ph_1[(((k * 256) + (i1_outer * 16)) + i1_inner)]));
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_1 = 0; i0_1 < 2; ++i0_1) {
    for (int32_t i1_outer_1 = 0; i1_outer_1 < 16; ++i1_outer_1) {
      for (int32_t i1_inner_1 = 0; i1_inner_1 < 16; ++i1_inner_1) {
        T_matmul_NN_1[(((i0_1 * 256) + (i1_outer_1 * 16)) + i1_inner_1)] = 0.000000e+00f;
        for (int32_t k_1 = 0; k_1 < 256; ++k_1) {
          T_matmul_NN_1[(((i0_1 * 256) + (i1_outer_1 * 16)) + i1_inner_1)] = (T_matmul_NN_1[(((i0_1 * 256) + (i1_outer_1 * 16)) + i1_inner_1)] + (ph_2[((i0_1 * 256) + k_1)] * ph_3[(((k_1 * 256) + (i1_outer_1 * 16)) + i1_inner_1)]));
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0 = 0; ax0 < 2; ++ax0) {
    for (int32_t ax1_outer = 0; ax1_outer < 16; ++ax1_outer) {
      for (int32_t ax1_inner = 0; ax1_inner < 16; ++ax1_inner) {
        T_matmul_NN[(((ax0 * 256) + (ax1_outer * 16)) + ax1_inner)] = (T_matmul_NN[(((ax0 * 256) + (ax1_outer * 16)) + ax1_inner)] + T_matmul_NN_1[(((ax0 * 256) + (ax1_outer * 16)) + ax1_inner)]);
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_1 = 0; ax0_1 < 2; ++ax0_1) {
    for (int32_t ax1_outer_1 = 0; ax1_outer_1 < 16; ++ax1_outer_1) {
      for (int32_t ax1_inner_1 = 0; ax1_inner_1 < 16; ++ax1_inner_1) {
        T_matmul_NN[(((ax0_1 * 256) + (ax1_outer_1 * 16)) + ax1_inner_1)] = (T_matmul_NN[(((ax0_1 * 256) + (ax1_outer_1 * 16)) + ax1_inner_1)] + ph_4[((ax1_outer_1 * 16) + ax1_inner_1)]);
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_2 = 0; i0_2 < 2; ++i0_2) {
    for (int32_t i1_outer_2 = 0; i1_outer_2 < 16; ++i1_outer_2) {
      for (int32_t i1_inner_2 = 0; i1_inner_2 < 16; ++i1_inner_2) {
        T_matmul_NN[(((i0_2 * 256) + (i1_outer_2 * 16)) + i1_inner_2)] = (1.000000e+00f / (1.000000e+00f + expf((0.000000e+00f - T_matmul_NN[(((i0_2 * 256) + (i1_outer_2 * 16)) + i1_inner_2)]))));
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_2 = 0; ax0_2 < 2; ++ax0_2) {
    for (int32_t ax1_outer_2 = 0; ax1_outer_2 < 16; ++ax1_outer_2) {
      for (int32_t ax1_inner_2 = 0; ax1_inner_2 < 16; ++ax1_inner_2) {
        T_matmul_NN_1[(((ax0_2 * 256) + (ax1_outer_2 * 16)) + ax1_inner_2)] = (T_matmul_NN[(((ax0_2 * 256) + (ax1_outer_2 * 16)) + ax1_inner_2)] * ph_2[(((ax0_2 * 256) + (ax1_outer_2 * 16)) + ax1_inner_2)]);
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_3 = 0; ax0_3 < 2; ++ax0_3) {
    for (int32_t ax1_outer_3 = 0; ax1_outer_3 < 16; ++ax1_outer_3) {
      for (int32_t ax1_inner_3 = 0; ax1_inner_3 < 16; ++ax1_inner_3) {
        T_matmul_NN[(((ax0_3 * 256) + (ax1_outer_3 * 16)) + ax1_inner_3)] = (1.000000e+00f - T_matmul_NN[(((ax0_3 * 256) + (ax1_outer_3 * 16)) + ax1_inner_3)]);
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_3 = 0; i0_3 < 2; ++i0_3) {
    for (int32_t i1_outer_3 = 0; i1_outer_3 < 16; ++i1_outer_3) {
      for (int32_t i1_inner_3 = 0; i1_inner_3 < 16; ++i1_inner_3) {
        T_matmul_NN_2[(((i0_3 * 256) + (i1_outer_3 * 16)) + i1_inner_3)] = 0.000000e+00f;
        for (int32_t k_2 = 0; k_2 < 1000; ++k_2) {
          T_matmul_NN_2[(((i0_3 * 256) + (i1_outer_3 * 16)) + i1_inner_3)] = (T_matmul_NN_2[(((i0_3 * 256) + (i1_outer_3 * 16)) + i1_inner_3)] + (ph[((i0_3 * 1000) + k_2)] * ph_5[(((k_2 * 256) + (i1_outer_3 * 16)) + i1_inner_3)]));
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_4 = 0; i0_4 < 2; ++i0_4) {
    for (int32_t i1_outer_4 = 0; i1_outer_4 < 16; ++i1_outer_4) {
      for (int32_t i1_inner_4 = 0; i1_inner_4 < 16; ++i1_inner_4) {
        T_matmul_NN_3[(((i0_4 * 256) + (i1_outer_4 * 16)) + i1_inner_4)] = 0.000000e+00f;
        for (int32_t k_3 = 0; k_3 < 1000; ++k_3) {
          T_matmul_NN_3[(((i0_4 * 256) + (i1_outer_4 * 16)) + i1_inner_4)] = (T_matmul_NN_3[(((i0_4 * 256) + (i1_outer_4 * 16)) + i1_inner_4)] + (ph[((i0_4 * 1000) + k_3)] * ph_6[(((k_3 * 256) + (i1_outer_4 * 16)) + i1_inner_4)]));
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_5 = 0; i0_5 < 2; ++i0_5) {
    for (int32_t i1_outer_5 = 0; i1_outer_5 < 16; ++i1_outer_5) {
      for (int32_t i1_inner_5 = 0; i1_inner_5 < 16; ++i1_inner_5) {
        T_matmul_NN_4[(((i0_5 * 256) + (i1_outer_5 * 16)) + i1_inner_5)] = 0.000000e+00f;
        for (int32_t k_4 = 0; k_4 < 256; ++k_4) {
          T_matmul_NN_4[(((i0_5 * 256) + (i1_outer_5 * 16)) + i1_inner_5)] = (T_matmul_NN_4[(((i0_5 * 256) + (i1_outer_5 * 16)) + i1_inner_5)] + (ph_2[((i0_5 * 256) + k_4)] * ph_7[(((k_4 * 256) + (i1_outer_5 * 16)) + i1_inner_5)]));
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_4 = 0; ax0_4 < 2; ++ax0_4) {
    for (int32_t ax1_outer_4 = 0; ax1_outer_4 < 16; ++ax1_outer_4) {
      for (int32_t ax1_inner_4 = 0; ax1_inner_4 < 16; ++ax1_inner_4) {
        T_matmul_NN_3[(((ax0_4 * 256) + (ax1_outer_4 * 16)) + ax1_inner_4)] = (T_matmul_NN_3[(((ax0_4 * 256) + (ax1_outer_4 * 16)) + ax1_inner_4)] + T_matmul_NN_4[(((ax0_4 * 256) + (ax1_outer_4 * 16)) + ax1_inner_4)]);
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_5 = 0; ax0_5 < 2; ++ax0_5) {
    for (int32_t ax1_outer_5 = 0; ax1_outer_5 < 16; ++ax1_outer_5) {
      for (int32_t ax1_inner_5 = 0; ax1_inner_5 < 16; ++ax1_inner_5) {
        T_matmul_NN_3[(((ax0_5 * 256) + (ax1_outer_5 * 16)) + ax1_inner_5)] = (T_matmul_NN_3[(((ax0_5 * 256) + (ax1_outer_5 * 16)) + ax1_inner_5)] + ph_8[((ax1_outer_5 * 16) + ax1_inner_5)]);
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_6 = 0; i0_6 < 2; ++i0_6) {
    for (int32_t i1_outer_6 = 0; i1_outer_6 < 16; ++i1_outer_6) {
      for (int32_t i1_inner_6 = 0; i1_inner_6 < 16; ++i1_inner_6) {
        T_matmul_NN_3[(((i0_6 * 256) + (i1_outer_6 * 16)) + i1_inner_6)] = (1.000000e+00f / (1.000000e+00f + expf((0.000000e+00f - T_matmul_NN_3[(((i0_6 * 256) + (i1_outer_6 * 16)) + i1_inner_6)]))));
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_6 = 0; ax0_6 < 2; ++ax0_6) {
    for (int32_t ax1_outer_6 = 0; ax1_outer_6 < 16; ++ax1_outer_6) {
      for (int32_t ax1_inner_6 = 0; ax1_inner_6 < 16; ++ax1_inner_6) {
        T_matmul_NN_3[(((ax0_6 * 256) + (ax1_outer_6 * 16)) + ax1_inner_6)] = (T_matmul_NN_3[(((ax0_6 * 256) + (ax1_outer_6 * 16)) + ax1_inner_6)] * ph_2[(((ax0_6 * 256) + (ax1_outer_6 * 16)) + ax1_inner_6)]);
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_7 = 0; i0_7 < 2; ++i0_7) {
    for (int32_t i1_outer_7 = 0; i1_outer_7 < 16; ++i1_outer_7) {
      for (int32_t i1_inner_7 = 0; i1_inner_7 < 16; ++i1_inner_7) {
        T_matmul_NN_4[(((i0_7 * 256) + (i1_outer_7 * 16)) + i1_inner_7)] = 0.000000e+00f;
        for (int32_t k_5 = 0; k_5 < 256; ++k_5) {
          T_matmul_NN_4[(((i0_7 * 256) + (i1_outer_7 * 16)) + i1_inner_7)] = (T_matmul_NN_4[(((i0_7 * 256) + (i1_outer_7 * 16)) + i1_inner_7)] + (T_matmul_NN_3[((i0_7 * 256) + k_5)] * ph_9[(((k_5 * 256) + (i1_outer_7 * 16)) + i1_inner_7)]));
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_7 = 0; ax0_7 < 2; ++ax0_7) {
    for (int32_t ax1_outer_7 = 0; ax1_outer_7 < 16; ++ax1_outer_7) {
      for (int32_t ax1_inner_7 = 0; ax1_inner_7 < 16; ++ax1_inner_7) {
        T_matmul_NN_2[(((ax0_7 * 256) + (ax1_outer_7 * 16)) + ax1_inner_7)] = (T_matmul_NN_2[(((ax0_7 * 256) + (ax1_outer_7 * 16)) + ax1_inner_7)] + T_matmul_NN_4[(((ax0_7 * 256) + (ax1_outer_7 * 16)) + ax1_inner_7)]);
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_8 = 0; ax0_8 < 2; ++ax0_8) {
    for (int32_t ax1_outer_8 = 0; ax1_outer_8 < 16; ++ax1_outer_8) {
      for (int32_t ax1_inner_8 = 0; ax1_inner_8 < 16; ++ax1_inner_8) {
        T_matmul_NN_2[(((ax0_8 * 256) + (ax1_outer_8 * 16)) + ax1_inner_8)] = (T_matmul_NN_2[(((ax0_8 * 256) + (ax1_outer_8 * 16)) + ax1_inner_8)] + ph_10[((ax1_outer_8 * 16) + ax1_inner_8)]);
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_8 = 0; i0_8 < 2; ++i0_8) {
    for (int32_t i1_outer_8 = 0; i1_outer_8 < 16; ++i1_outer_8) {
      for (int32_t i1_inner_8 = 0; i1_inner_8 < 16; ++i1_inner_8) {
        T_matmul_NN_2[(((i0_8 * 256) + (i1_outer_8 * 16)) + i1_inner_8)] = tanhf(T_matmul_NN_2[(((i0_8 * 256) + (i1_outer_8 * 16)) + i1_inner_8)]);
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_9 = 0; ax0_9 < 2; ++ax0_9) {
    for (int32_t ax1_outer_9 = 0; ax1_outer_9 < 16; ++ax1_outer_9) {
      for (int32_t ax1_inner_9 = 0; ax1_inner_9 < 16; ++ax1_inner_9) {
        T_matmul_NN[(((ax0_9 * 256) + (ax1_outer_9 * 16)) + ax1_inner_9)] = (T_matmul_NN[(((ax0_9 * 256) + (ax1_outer_9 * 16)) + ax1_inner_9)] * T_matmul_NN_2[(((ax0_9 * 256) + (ax1_outer_9 * 16)) + ax1_inner_9)]);
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_10 = 0; ax0_10 < 2; ++ax0_10) {
    for (int32_t ax1_outer_10 = 0; ax1_outer_10 < 16; ++ax1_outer_10) {
      for (int32_t ax1_inner_10 = 0; ax1_inner_10 < 16; ++ax1_inner_10) {
        T_matmul_NN_1[(((ax0_10 * 256) + (ax1_outer_10 * 16)) + ax1_inner_10)] = (T_matmul_NN_1[(((ax0_10 * 256) + (ax1_outer_10 * 16)) + ax1_inner_10)] + T_matmul_NN[(((ax0_10 * 256) + (ax1_outer_10 * 16)) + ax1_inner_10)]);
      }
    }
  }
  #pragma omp parallel for
  for (int32_t i0_9 = 0; i0_9 < 2; ++i0_9) {
    for (int32_t i1_outer_9 = 0; i1_outer_9 < 8; ++i1_outer_9) {
      for (int32_t i1_inner_9 = 0; i1_inner_9 < 16; ++i1_inner_9) {
        T_matmul_NN_3[(((i0_9 * 128) + (i1_outer_9 * 16)) + i1_inner_9)] = 0.000000e+00f;
        for (int32_t k_6 = 0; k_6 < 256; ++k_6) {
          T_matmul_NN_3[(((i0_9 * 128) + (i1_outer_9 * 16)) + i1_inner_9)] = (T_matmul_NN_3[(((i0_9 * 128) + (i1_outer_9 * 16)) + i1_inner_9)] + (T_matmul_NN_1[((i0_9 * 256) + k_6)] * ph_11[(((k_6 * 128) + (i1_outer_9 * 16)) + i1_inner_9)]));
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t ax0_11 = 0; ax0_11 < 2; ++ax0_11) {
    for (int32_t ax1_outer_11 = 0; ax1_outer_11 < 8; ++ax1_outer_11) {
      for (int32_t ax1_inner_11 = 0; ax1_inner_11 < 16; ++ax1_inner_11) {
        T_add[(((ax0_11 * 128) + (ax1_outer_11 * 16)) + ax1_inner_11)] = (T_matmul_NN_3[(((ax0_11 * 128) + (ax1_outer_11 * 16)) + ax1_inner_11)] + ph_12[((ax1_outer_11 * 16) + ax1_inner_11)]);
      }
    }
  }
}
