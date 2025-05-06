
void default_function_kernel(float* compute, float* ph, float* ph_1, float* ph_2, float* ph_3, float* ph_4, float* ph_5, float* ph_6, float* ph_7, float* ph_8, float* ph_9, float* ph_10) {
    int num_threads = omp_get_max_threads();
    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int idx = omp_get_thread_num() * 1024;
        for (int j = 0; j < 1024; ++j) {
            if (idx + j < 11907) {
                compute[idx + j] = ph[j];
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int idx = omp_get_thread_num() * 1024;
        for (int j = 0; j < 1024; ++j) {
            if (idx + j < 11907) {
                compute[idx + j] = sqrtf(compute[idx + j]);
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int idx = omp_get_thread_num() * 1024;
        for (int j = 0; j < 1024; ++j) {
            if (idx + j < 11907) {
                compute[idx + j] = compute[idx + j] + 1.000000e-05f;
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int idx = omp_get_thread_num() * 1024;
        for (int j = 0; j < 1024; ++j) {
            if (idx + j < 11907) {
                compute[idx + j] = compute[idx + j] * T_reshape[(((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3969)];
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int idx = omp_get_thread_num() * 1024;
        for (int j = 0; j < 1024; ++j) {
            if (idx + j < 11907) {
                compute[idx + j] = compute[idx + j] / T_reshape[(((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3969)];
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int idx = omp_get_thread_num() * 1024;
        for (int j = 0; j < 1024; ++j) {
            if (idx + j < 11907) {
                compute[idx + j] = max(compute[idx + j], 0.000000e+00f);
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int idx = omp_get_thread_num() * 1024;
        for (int j = 0; j < 1024; ++j) {
            if (idx + j < 11907) {
                compute[idx + j] = group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] + T_reshape[(((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3969)];
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int idx = omp_get_thread_num() * 1024;
        for (int j = 0; j < 1024; ++j) {
            if (idx + j < 11907) {
                compute[idx + j] = group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] * T_reshape[(((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3969)];
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int idx = omp_get_thread_num() * 1024;
        for (int j = 0; j < 1024; ++j) {
            if (idx + j < 11907) {
                compute[idx + j] = group_conv2d_nchw[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] - T_reshape[(((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 3969)];
            }
        }
    }
}