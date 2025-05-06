void default_function_kernel(float* data, float* kernel, float* output_unpack) {
    #pragma omp parallel for collapse(4)
    for (int n = 0; n < 2; ++n) {
        for (int c_out = 0; c_out < 64; ++c_out) {
            for (int h_out = 0; h_out < 254; ++h_out) {
                for (int w_out = 0; w_out < 254; ++w_out) {
                    float conv2d_nchw_local[8] = {0.0f};
                    for (int rc_outer = 0; rc_outer < 16; ++rc_outer) {
                        for (int rc_inner = 0; rc_inner < 2; ++rc_inner) {
                            for (int ry_inner = 0; ry_inner < 3; ++ry_inner) {
                                for (int rx_inner = 0; rx_inner < 3; ++rx_inner) {
                                    for (int yy_c = 0; yy_c < 2; ++yy_c) {
                                        int c_in = (c_out / 2) * 32 + (c_out % 2) * 32;
                                        int k_idx = (c_out * 32 + c_in) * 9 + (ry_inner * 3 + rx_inner);
                                        int d_idx = (n * 32 * 256 * 256) + (c_in * 256 * 256) + ((h_out + ry_inner) * 256) + (w_out + rx_inner);
                                        conv2d_nchw_local[yy_c] += data[d_idx] * kernel[k_idx];
                                        conv2d_nchw_local[yy_c + 2] += data[d_idx] * kernel[k_idx + 144];
                                        conv2d_nchw_local[yy_c + 4] += data[d_idx] * kernel[k_idx + 288];
                                        conv2d_nchw_local[yy_c + 6] += data[d_idx] * kernel[k_idx + 432];
                                    }
                                }
                            }
                        }
                    }
                    for (int yy_inner_inner_inner = 0; yy_inner_inner_inner < 2; ++yy_inner_inner_inner) {
                        int o_idx = (n * 64 * 254 * 254) + (c_out * 254 * 254) + (h_out * 254) + w_out;
                        output_unpack[o_idx] = conv2d_nchw_local[yy_inner_inner_inner];
                        output_unpack[o_idx + 516128] = conv2d_nchw_local[yy_inner_inner_inner + 2];
                        output_unpack[o_idx + 1032256] = conv2d_nchw_local[yy_inner_inner_inner + 4];
                        output_unpack[o_idx + 1548384] = conv2d_nchw_local[yy_inner_inner_inner + 6];
                    }
                }
            }
        }
    }
}