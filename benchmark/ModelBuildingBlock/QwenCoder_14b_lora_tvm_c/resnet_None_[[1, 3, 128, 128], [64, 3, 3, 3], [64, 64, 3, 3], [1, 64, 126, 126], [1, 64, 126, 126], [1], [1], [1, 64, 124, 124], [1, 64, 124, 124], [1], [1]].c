void default_function_kernel(float* compute, float* ph, float* ph_1, float* ph_2, float* ph_3, float* ph_4, float* ph_5, float* ph_6, float* ph_7, float* ph_8, float* ph_9, float* ph_10) {
    // Initialize T_reshape arrays
    float T_reshape_1[1024];
    float T_reshape_2[1024];
    float T_reshape_3[1024];
    float T_reshape_4[1024];
    float T_reshape_5[1024];
    float T_reshape_6[1024];
    float T_reshape_7[1024];
    float T_reshape_8[1024];
    float T_reshape_9[1024];
    float T_reshape_10[1024];

    // Initialize conv2d_nchw arrays
    float conv2d_nchw_1[262144];
    float conv2d_nchw_2[262144];
    float conv2d_nchw_3[262144];
    float conv2d_nchw_4[262144];
    float conv2d_nchw_5[262144];
    float conv2d_nchw_6[262144];
    float conv2d_nchw_7[262144];
    float conv2d_nchw_8[262144];
    float conv2d_nchw_9[262144];
    float conv2d_nchw_10[262144];

    // Initialize pad_temp array
    float pad_temp[1024];

    // Copy ph to pad_temp
    #pragma omp parallel for
    for (int i = 0; i < 1024; i++) {
        pad_temp[i] = ph[i];
    }

    // Copy ph_1 to T_reshape_1
    #pragma omp parallel for
    for (int i = 0; i < 1024; i++) {
        T_reshape_1[i] = ph_1[i];
    }

    // Copy ph_2 to T_reshape_2
    #pragma omp parallel for
    for (int i = 0; i < 1024; i++) {
        T_reshape_2[i] = ph_2[i];
    }

    // Copy ph_3 to T_reshape_3
    #pragma omp parallel for
    for (int i = 0; i < 1024; i++) {
        T_reshape_3[i] = ph_3[i];
    }

    // Copy ph_4 to T_reshape_4
    #pragma omp parallel for
    for (int i = 0; i < 1024; i++) {
        T_reshape_4[i] = ph_4[i];
    }

    // Copy ph_5 to T_reshape_5
    #pragma omp parallel for
    for (int i = 0; i < 1024; i++) {
        T_reshape_5[i] = ph_5[i];
    }

    // Copy ph_6 to T_reshape_6
    #pragma omp parallel for
    for (int i = 0; i < 1024; i++) {
        T_reshape_6[i] = ph_6[i];
    }

    // Copy ph_7 to T_reshape_7
    #pragma omp parallel for
    for (int i = 0; i < 1024; i++) {
        T_reshape_7[i] = ph_7[i];
    }

    // Copy ph_8 to T_reshape_8
    #pragma omp parallel for
    for (int i = 0; i < 1024; i++) {
        T_reshape_8[i] = ph_8[i];
    }

    // Copy ph_9 to T_reshape_9
    #pragma omp parallel for
    for (int i = 0; i < 1024; i++) {
        T_reshape_9[i] = ph_9[i];
    }

    // Copy ph_10 to T_reshape_10
    #pragma omp parallel for
    for (int i = 0; i < 1024; i++) {
        T_reshape_10[i] = ph_10[i];
    }

    // Perform operations on conv2d_nchw_1
    #pragma omp parallel for collapse(4)
    for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 4; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
        for (int i = 0; i < 1024; i++) {
            if ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 1024) + i) < 3969)) {
                conv2d_nchw_1[(ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + i] = 0.0f;
                for (int rc = 0; rc < 3; ++rc) {
                    for (int ry = 0; ry < 3; ++ry) {
                        for (int rx = 0; rx < 3; ++rx) {
                            conv2d_nchw_1[(ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + i] += (pad_temp[(((((rc * 16384) + ((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 131072) + i) % 7938) / 63) * 128)) + (ry * 128)) + rx) + i) % 126)] * ph[((((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 65536) + i) / 3969) * 27) + (rc * 9)) + (ry * 3)) + rx)]);
                        }
                    }
                }
            }
        }
    }

    // Perform operations on conv2d_nchw_2
    #pragma omp parallel for collapse(4)
    for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 4; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
        for (int i = 0; i < 1024; i++) {
            if ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 1024) + i) < 3969)) {
                conv2d_nchw_2[(ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + i] = 0.0f;
                for (int rc = 0; rc < 64; ++rc) {
                    for (int ry = 0; ry < 3; ++ry) {
                        for (int rx = 0; rx < 3; ++rx) {
                            conv2d_nchw_2[(ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + i] += (conv2d_nchw_1[(((((rc * 15876) + ((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 65536) + i) % 3844) / 31) * 126)) + (ry * 126)) + rx) + i) % 124)] * ph[(((((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 16384) + i) % 61504) / 961) * 576) + (rc * 9)) + (ry * 3)) + rx)]);
                        }
                    }
                }
            }
        }
    }

    // Perform operations on conv2d_nchw_3
    #pragma omp parallel for collapse(4)
    for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 4; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
        for (int i = 0; i < 1024; i++) {
            if ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 1024) + i) < 3969)) {
                conv2d_nchw_3[(ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + i] = 0.0f;
                for (int rc = 0; rc < 64; ++rc) {
                    for (int ry = 0; ry < 3; ++ry) {
                        for (int rx = 0; rx < 3; ++rx) {
                            conv2d_nchw_3[(ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + i] += (conv2d_nchw_2[(((((rc * 15876) + ((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 65536) + i) % 3844) / 31) * 126)) + (ry * 126)) + rx) + i) % 124)] * ph[(((((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 16384) + i) % 61504) / 961) * 576) + (rc * 9)) + (ry * 3)) + rx)]);
                        }
                    }
                }
            }
        }
    }

    // Perform operations on conv2d_nchw_4
    #pragma omp parallel for collapse(4)
    for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 4; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
        for (int i = 0; i < 1024; i++) {
            if ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 1024) + i) < 3969)) {
                conv2d_nchw_4[(ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + i] = 0.0f;
                for (int rc = 0; rc < 64; ++rc) {
                    for (int ry = 0; ry < 3; ++ry) {
                        for (int rx = 0; rx < 3; ++rx) {
                            conv2d_nchw_4[(ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + i] += (conv2d_nchw_3[(((((rc * 15876) + ((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 65536) + i) % 3844) / 31) * 126)) + (ry * 126)) + rx) + i) % 124)] * ph[(((((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 16384) + i) % 61504) / 961) * 576) + (rc * 9)) + (ry * 3)) + rx)]);
                        }
                    }
                }
            }
        }
    }

    // Perform operations on conv2d_nchw_5
    #pragma omp parallel for collapse(4)
    for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 4; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
        for (int i = 0; i < 1024; i++) {
            if ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 1024) + i) < 3969)) {
                conv2d_nchw_5[(ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + i] = 0.0f;
                for (int rc = 0; rc < 64; ++rc) {
                    for (int ry = 0; ry < 3; ++ry) {
                        for (int rx = 0; rx < 3; ++rx) {
                            conv2d_nchw_5[(ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + i] += (conv2d_nchw_4[(((((rc * 15876) + ((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 65536) + i) % 3844) / 31) * 126)) + (ry * 126)) + rx) + i) % 124)] * ph[(((((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 16384) + i) % 61504) / 961) * 576) + (rc * 9)) + (ry * 3)) + rx)]);
                        }
                    }
                }
            }
        }
    }

    // Perform operations on conv2d_nchw_6
    #pragma omp parallel for collapse(4)
    for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 4; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
        for (int i = 0; i < 1024; i++) {
            if ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 1024) + i) < 3969)) {
                conv2d_nchw_6[(ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + i] = 0.0f;
                for (int rc = 0; rc < 64; ++rc) {
                    for (int ry = 0; ry < 3; ++ry) {
                        for (int rx = 0; rx < 3; ++rx) {
                            conv2d_nchw_6[(ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + i] += (conv2d_nchw_5[(((((rc * 15876) + ((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 65536) + i) % 3844) / 31) * 126)) + (ry * 126)) + rx) + i) % 124)] * ph[(((((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 16384) + i) % 61504) / 961) * 576) + (rc * 9)) + (ry * 3)) + rx)]);
                        }
                    }
                }
            }
        }
    }

    // Perform operations on conv2d_nchw_7
    #pragma omp parallel for collapse(4)
    for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 4; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
        for (int i = 0; i < 1024; i++) {
            if ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 1024) + i) < 3969)) {
                conv2d_nchw_7[(ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + i] = 0.0f;
                for (int rc = 0; rc < 64; ++rc) {
                    for (int ry = 0; ry < 3; ++ry) {
                        for (int rx = 0; rx < 3; ++rx) {
                            conv2d_nchw_7[(ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + i] += (conv2d_nchw_6[(((((rc * 15876) + ((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 65536) + i) % 3844) / 31) * 126)) + (ry * 126)) + rx) + i) % 124)] * ph[(((((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 16384) + i) % 61504) / 961) * 576) + (rc * 9)) + (ry * 3)) + rx)]);
                        }
                    }
                }
            }
        }
    }

    // Perform operations on conv2d_nchw_8
    #pragma omp parallel for collapse(4)
    for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 4; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
        for (int i = 0; i < 1024; i++) {
            if ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 1024) + i) < 3969)) {
                conv2d_nchw_8[(ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + i] = 0.0f;
                for (int rc = 0; rc < 64; ++rc) {
                    for (int ry = 0; ry < 3; ++ry) {
                        for (int rx = 0; rx < 3; ++rx) {
                            conv2d_nchw_8[(ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + i] += (conv2d_nchw_7[(((((rc * 15876) + ((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 65536) + i) % 3844) / 31) * 126)) + (ry * 126)) + rx) + i) % 124)] * ph[(((((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 16384) + i) % 61504) / 961) * 576) + (rc * 9)) + (ry * 3)) + rx)]);
                        }
                    }
                }
            }
        }
    }

    // Perform operations on conv2d_nchw_9
    #pragma omp parallel for collapse(4)
    for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 4; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
        for (int i = 0; i < 1024; i++) {
            if ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 1024) + i) < 3969)) {
                conv2d_nchw_9[(ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + i] = 0.0f;
                for (int rc = 0; rc < 64; ++rc) {
                    for (int ry = 0; ry < 3; ++ry) {
                        for (int rx = 0; rx < 3; ++rx) {
                            conv2d_nchw_9[(ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + i] += (conv2d_nchw_8[(((((rc * 15876) + ((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 65536) + i) % 3844) / 31) * 126)) + (ry * 126)) + rx) + i) % 124)] * ph[(((((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 16384) + i) % 61504) / 961) * 576) + (rc * 9)) + (ry * 3)) + rx)]);
                        }
                    }
                }
            }
        }
    }

    // Perform operations on conv2d_nchw_10
    #pragma omp parallel for collapse(4)
    for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 4; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
        for (int i = 0; i < 1024; i++) {
            if ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 1024) + i) < 3969)) {
                conv2d_nchw_10[(ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + i] = 0.0f;
                for (int rc = 0; rc < 64; ++rc) {
                    for (int ry = 0; ry < 3; ++ry) {
                        for (int rx = 0; rx < 3; ++rx) {
                            conv2d_nchw_10[(ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + i] += (conv2d_nchw_9[(((((rc * 15876) + ((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 65536) + i) % 3844) / 31) * 126)) + (ry * 126)) + rx) + i) % 124)] * ph[(((((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 16384) + i) % 61504) / 961) * 576) + (rc * 9)) + (ry * 3)) + rx)]);
                        }
                    }
                }
            }
        }
    }

    // Perform operations on compute
    #pragma omp parallel for collapse(4)
    for (int i0_i1_fused_i2_fused_i3_fused_outer = 0; i0_i1_fused_i2_fused_i3_fused_outer < 4; ++i0_i1_fused_i2_fused_i3_fused_outer) {
        for (int i = 0; i < 1024; i++) {
            if (((i0_i1_fused_i2_fused_i3_fused_outer * 256) + i) < 961) {
                compute[(i0_i1_fused_i2_fused_i3_fused_outer * 262144) + i] = fmaxf(conv2d_nchw_10[(i0_i1_fused_i2_fused_i3_fused_outer * 262144) + i], 0.0f);
            }
        }
    }
}