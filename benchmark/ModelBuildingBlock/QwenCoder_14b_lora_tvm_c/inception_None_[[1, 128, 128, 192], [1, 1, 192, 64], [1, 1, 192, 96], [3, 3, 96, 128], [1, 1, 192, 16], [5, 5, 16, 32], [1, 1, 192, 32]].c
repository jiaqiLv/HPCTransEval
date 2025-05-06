void default_function_kernel(float* T_concat, float* ph, float* ph_1, float* ph_2, float* ph_3, float* ph_4, float* ph_5, float* ph_6) {
    // Define the size of the arrays based on the input shapes
    const int total_elements = 128 * 128 * 192;
    const int output_elements = 128 * 128 * 256;

    // Initialize temporary arrays
    float pad_temp[total_elements];
    float pool_max[total_elements];
    float conv2d_nhwc[total_elements];
    float conv2d_nhwc_1[total_elements];
    float conv2d_nhwc_2[total_elements];

    // Copy initial values from ph to pad_temp
    #pragma omp parallel for
    for (int i = 0; i < total_elements; ++i) {
        pad_temp[i] = ph[i];
    }

    // Perform max pooling operation
    #pragma omp parallel for collapse(4)
    for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 12; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
        for (int rv0 = 0; rv0 < 3; ++rv0) {
            for (int rv1 = 0; rv1 < 3; ++rv1) {
                int idx = (ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (rv0 * 24960) + (rv1 * 192);
                pool_max[idx] = fmaxf(pool_max[idx], pad_temp[idx]);
            }
        }
    }

    // Reinitialize pad_temp with values from ph_1
    #pragma omp parallel for
    for (int i = 0; i < total_elements; ++i) {
        pad_temp[i] = ph_1[i];
    }

    // Perform convolution operation with ph_2
    #pragma omp parallel for collapse(4)
    for (int nn_yy_fused_xx_fused_ff_fused_outer = 0; nn_yy_fused_xx_fused_ff_fused_outer < 8; ++nn_yy_fused_xx_fused_ff_fused_outer) {
        for (int ry = 0; ry < 3; ++ry) {
            for (int rx = 0; rx < 3; ++rx) {
                for (int rc = 0; rc < 96; ++rc) {
                    int idx = (nn_yy_fused_xx_fused_ff_fused_outer * 262144) + (ry * 36864) + (rx * 12288) + (rc * 128);
                    conv2d_nhwc[idx] += pad_temp[idx] * ph_2[idx];
                }
            }
        }
    }

    // Reinitialize pad_temp with values from ph_3
    #pragma omp parallel for
    for (int i = 0; i < total_elements; ++i) {
        pad_temp[i] = ph_3[i];
    }

    // Perform convolution operation with ph_4
    #pragma omp parallel for collapse(4)
    for (int nn_yy_fused_xx_fused_ff_fused_outer = 0; nn_yy_fused_xx_fused_ff_fused_outer < 2; ++nn_yy_fused_xx_fused_ff_fused_outer) {
        for (int rc = 0; rc < 192; ++rc) {
            int idx = (nn_yy_fused_xx_fused_ff_fused_outer * 262144) + (rc * 192);
            conv2d_nhwc[idx] += pad_temp[idx] * ph_4[idx];
        }
    }

    // Reinitialize pad_temp with values from ph_5
    #pragma omp parallel for
    for (int i = 0; i < total_elements; ++i) {
        pad_temp[i] = ph_5[i];
    }

    // Perform convolution operation with ph_6
    #pragma omp parallel for collapse(4)
    for (int nn_yy_fused_xx_fused_ff_fused_outer = 0; nn_yy_fused_xx_fused_ff_fused_outer < 4; ++nn_yy_fused_xx_fused_ff_fused_outer) {
        for (int rc = 0; rc < 192; ++rc) {
            int idx = (nn_yy_fused_xx_fused_ff_fused_outer * 262144) + (rc * 192);
            conv2d_nhwc[idx] += pad_temp[idx] * ph_6[idx];
        }
    }

    // Concatenate results into T_concat
    #pragma omp parallel for
    for (int i = 0; i < output_elements; ++i) {
        if (i >= 224 && i < 224 + total_elements) {
            T_concat[i] = pool_max[i - 224];
        } else if (i >= 192 && i < 192 + total_elements) {
            T_concat[i] = conv2d_nhwc[i - 192];
        } else if (i >= 64 && i < 64 + total_elements) {
            T_concat[i] = conv2d_nhwc_1[i - 64];
        } else {
            T_concat[i] = conv2d_nhwc_2[i];
        }
    }
}