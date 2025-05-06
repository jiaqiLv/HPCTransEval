void default_function_kernel(float* compute, float* ph, float* ph_1, float* ph_2, float* ph_3, float* ph_4, float* ph_5, float* ph_6, float* ph_7, float* ph_8, float* ph_9, float* ph_10) {
    int num_threads = omp_get_max_threads();
    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            ph[idx] = ph[idx];
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 11907) {
            for (int rc = 0; rc < 3; ++rc) {
                if (idx < 11907) {
                    ph[idx] = (ph[idx] - sqrtf(ph[idx]));
                }
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            ph[idx] = ph[0];
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            ph[idx] = (ph[idx] + 1.000000e-05f);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            ph[idx] = sqrtf(ph[idx]);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            ph[idx] = (ph[idx] * T_reshape[(((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3969)]);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            ph[idx] = ph[0];
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            ph[idx] = (ph[idx] / T_reshape[(((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3969)]);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 11907) {
            for (int ry = 0; ry < 3; ++ry) {
                for (int rx = 0; rx < 3; ++rx) {
                    if (idx < 11907) {
                        group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (pad_temp[((((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3969) * 16384) + (((((((int)blockIdx.x) * 512) + (((int)threadIdx.x) >> 1)) % 7938) / 63) * 128)) + (ry * 128)) + rx) + (((((int)blockIdx.x) * 16) + ((int)threadIdx.x)) % 126))] * ph[((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3969) * 27) + (ry * 3)) + rx)]));
                    }
                }
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] * T_reshape[(((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3969)]);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + T_reshape[(((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3969)]);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ph[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            ph[idx] = ph[((int)threadIdx.x)];
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            ph[idx] = 0.000000e+00f;
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            for (int ry = 0; ry < 3; ++ry) {
                for (int rx = 0; rx < 3; ++rx) {
                    if (idx < 11907) {
                        group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (pad_temp[((((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3969) * 16384) + (((((((int)blockIdx.x) * 512) + (((int)threadIdx.x) >> 1)) % 7938) / 63) * 128)) + (ry * 128)) + rx) + (((((int)blockIdx.x) * 16) + ((int)threadIdx.x)) % 126))] * ph[((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3969) * 27) + (ry * 3)) + rx)]));
                    }
                }
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] - T_reshape[(((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3969)]);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 11907) {
            for (int ry = 0; ry < 3; ++ry) {
                for (int rx = 0; rx < 3; ++rx) {
                    if (idx < 11907) {
                        group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] * T_reshape[(((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3969)]);
                    }
                }
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + T_reshape[(((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3969)]);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            pad_temp[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ph[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            ph[idx] = ph[((int)threadIdx.x)];
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            ph[idx] = 0.000000e+00f;
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 11907) {
            for (int ry = 0; ry < 3; ++ry) {
                for (int rx = 0; rx < 3; ++rx) {
                    if (idx < 11907) {
                        group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + (pad_temp[((((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3969) * 16384) + (((((((int)blockIdx.x) * 512) + (((int)threadIdx.x) >> 1)) % 7938) / 63) * 128)) + (ry * 128)) + rx) + (((((int)blockIdx.x) * 16) + ((int)threadIdx.x)) % 126))] * ph[((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3969) * 27) + (ry * 3)) + rx)]));
                    }
                }
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] * T_reshape[(((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3969)]);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = max(group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))], 0.000000e+00f);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int idx = thread_id;

        if (idx < 1024) {
            group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = (group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + T_reshape[(((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3969)]);
        }
    }
}