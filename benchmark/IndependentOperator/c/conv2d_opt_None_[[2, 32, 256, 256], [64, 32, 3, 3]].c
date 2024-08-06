void default_function_kernel(float* data, float* kernel, float* output_unpack) {
  float data_vec[4194304];
  float kernel_vec[18432];
  #pragma omp parallel for
  for (int32_t bs_c_fused_h_fused = 0; bs_c_fused_h_fused < 4096; ++bs_c_fused_h_fused) {
    for (int32_t w = 0; w < 256; ++w) {
      for (int32_t vc = 0; vc < 4; ++vc) {
        data_vec[(((bs_c_fused_h_fused * 1024) + (w * 4)) + vc)] = data[(((((bs_c_fused_h_fused >> 8) * 262144) + (vc * 65536)) + ((bs_c_fused_h_fused & 255) * 256)) + w)];
      }
    }
  }
  #pragma omp parallel for
  for (int32_t occ_k_h_fused = 0; occ_k_h_fused < 48; ++occ_k_h_fused) {
    for (int32_t icc = 0; icc < 8; ++icc) {
      for (int32_t k_w = 0; k_w < 3; ++k_w) {
        for (int32_t icb = 0; icb < 4; ++icb) {
          for (int32_t ocb = 0; ocb < 4; ++ocb) {
            kernel_vec[(((((((occ_k_h_fused / 3) * 1152) + (icc * 144)) + ((occ_k_h_fused % 3) * 48)) + (k_w * 16)) + (icb * 4)) + ocb)] = kernel[(((((((occ_k_h_fused / 3) * 1152) + (ocb * 288)) + (icc * 36)) + (icb * 9)) + ((occ_k_h_fused % 3) * 3)) + k_w)];
          }
        }
      }
    }
  }
  #pragma omp parallel for
  for (int32_t n_c_outer_fused_h_fused = 0; n_c_outer_fused_h_fused < 8128; ++n_c_outer_fused_h_fused) {
    float conv2d_NCHWc[1016];
    float conv2d_NCHWc_global[8];
    for (int32_t ow_outer = 0; ow_outer < 127; ++ow_outer) {
      for (int32_t oc_block_c_init = 0; oc_block_c_init < 4; ++oc_block_c_init) {
        conv2d_NCHWc_global[oc_block_c_init] = 0.000000e+00f;
      }
      for (int32_t oc_block_c_init_1 = 0; oc_block_c_init_1 < 4; ++oc_block_c_init_1) {
        conv2d_NCHWc_global[(oc_block_c_init_1 + 4)] = 0.000000e+00f;
      }
      for (int32_t ic_outer = 0; ic_outer < 8; ++ic_outer) {
        for (int32_t kh = 0; kh < 3; ++kh) {
          for (int32_t kw = 0; kw < 3; ++kw) {
            for (int32_t ic_inner = 0; ic_inner < 4; ++ic_inner) {
              for (int32_t oc_block_c = 0; oc_block_c < 4; ++oc_block_c) {
                conv2d_NCHWc_global[oc_block_c] = (conv2d_NCHWc_global[oc_block_c] + (data_vec[((((((((n_c_outer_fused_h_fused / 4064) * 2097152) + (ic_outer * 262144)) + (kh * 1024)) + ((n_c_outer_fused_h_fused % 254) * 1024)) + (ow_outer * 8)) + (kw * 4)) + ic_inner)] * kernel_vec[((((((((n_c_outer_fused_h_fused % 4064) / 254) * 1152) + (ic_outer * 144)) + (kh * 48)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c)]));
              }
              for (int32_t oc_block_c_1 = 0; oc_block_c_1 < 4; ++oc_block_c_1) {
                conv2d_NCHWc_global[(oc_block_c_1 + 4)] = (conv2d_NCHWc_global[(oc_block_c_1 + 4)] + (data_vec[(((((((((n_c_outer_fused_h_fused / 4064) * 2097152) + (ic_outer * 262144)) + (kh * 1024)) + ((n_c_outer_fused_h_fused % 254) * 1024)) + (ow_outer * 8)) + (kw * 4)) + ic_inner) + 4)] * kernel_vec[((((((((n_c_outer_fused_h_fused % 4064) / 254) * 1152) + (ic_outer * 144)) + (kh * 48)) + (kw * 16)) + (ic_inner * 4)) + oc_block_c_1)]));
              }
            }
          }
        }
      }
      for (int32_t ow_inner = 0; ow_inner < 2; ++ow_inner) {
        for (int32_t oc_block = 0; oc_block < 4; ++oc_block) {
          conv2d_NCHWc[(((ow_outer * 8) + (ow_inner * 4)) + oc_block)] = conv2d_NCHWc_global[((ow_inner * 4) + oc_block)];
        }
      }
    }
    for (int32_t w_outer = 0; w_outer < 127; ++w_outer) {
      for (int32_t w_inner = 0; w_inner < 2; ++w_inner) {
        for (int32_t c_inner = 0; c_inner < 4; ++c_inner) {
          output_unpack[((((((n_c_outer_fused_h_fused / 254) * 258064) + (c_inner * 64516)) + ((n_c_outer_fused_h_fused % 254) * 254)) + (w_outer * 2)) + w_inner)] = conv2d_NCHWc[(((w_outer * 8) + (w_inner * 4)) + c_inner)];
        }
      }
    }
  }
}
