void default_function_kernel(float* T_cast, float* ph, float* ph_1) {
    int num_threads = omp_get_max_threads();
    #pragma omp parallel for
    for (int i = 0; i < 11 * 22 * 33 * 44; ++i) {
        T_cast[i] = ph[i];
    }

    #pragma omp parallel for
    for (int i = 0; i < 20 * 10 * 10 * 9; ++i) {
        int idx = i;
        int blockIdx_x = idx / 1024;
        int threadIdx_x = idx % 1024;
        if (idx < 1125) {
            T_concat[idx] = T_strided_slice[idx] * T_strided_slice[idx];
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 9; ++k) {
                int idx = i * 90 + j * 9 + k;
                T_multiply_red[idx] = 0.0;
                for (int k1 = 0; k1 < 10; ++k1) {
                    for (int k2 = 0; k2 < 10; ++k2) {
                        int idx2 = (i * 10 + k1) * 9 + j * 9 + k2;
                        T_multiply_red[idx] += T_concat[idx2];
                    }
                }
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        int idx = i;
        int blockIdx_x = idx / 1024;
        int threadIdx_x = idx % 1024;
        if (idx < 1125) {
            T_cast[idx] = T_strided_slice[idx];
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        int idx = i;
        int blockIdx_x = idx / 1024;
        int threadIdx_x = idx % 1024;
        if (idx < 1125) {
            T_concat[idx] = T_concat[idx] / T_strided_slice[(i / 9) * 90 + (i % 9) * 9];
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        int idx = i;
        int blockIdx_x = idx / 1024;
        int threadIdx_x = idx % 1024;
        if (idx < 1125) {
            T_strided_slice[idx] = ph[((((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 225) * 31944) + (((((((int)blockIdx.x) * 62) + (((int)threadIdx.x) >> 1)) % 450) / 45) * 1452)) + (((((((int)blockIdx.x) * 34) + ((int)threadIdx.x)) % 90) / 9) * 44)) + (((((int)blockIdx.x) * 7) + ((int)threadIdx.x)) % 9)) + 16973)];
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        int idx = i;
        int blockIdx_x = idx / 1024;
        int threadIdx_x = idx % 1024;
        if (idx < 1125) {
            T_strided_slice[idx] = T_concat[(((((((((int)blockIdx.x) * 256) + (((int)threadIdx.x) >> 2)) / 225) * 900) + (((((((int)blockIdx.x) * 34) + ((int)threadIdx.x)) % 90) / 9) * 90)) + (((((((int)blockIdx.x) * 62) + (((int)threadIdx.x) >> 1)) % 450) / 45) * 9)) + (((((int)blockIdx.x) * 7) + ((int)threadIdx.x)) % 9))];
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 125; ++i) {
        int idx = i;
        int blockIdx_x = idx / 1024;
        int threadIdx_x = idx % 1024;
        if (idx < 125) {
            T_strided_slice[idx] = 0.0;
        }
        for (int k = 0; k < 9; ++k) {
            if (idx < 125) {
                T_strided_slice[idx] += T_concat[(((int)blockIdx.x) * 9216) + (((int)threadIdx.x) * 9) + k];
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        int idx = i;
        int blockIdx_x = idx / 1024;
        int threadIdx_x = idx % 1024;
        if (idx < 1125) {
            T_strided_slice[idx] = T_cast[idx] * (1.0 / sqrtf((T_multiply_red[(idx / 9) * 9 + (idx % 9)] * 0.01) + 1.0e-5));
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 125; ++i) {
        int idx = i;
        int blockIdx_x = idx / 1024;
        int threadIdx_x = idx % 1024;
        if (idx < 125) {
            T_strided_slice[idx] = -3.402823e+38;
        }
        for (int k = 0; k < 9; ++k) {
            if (idx < 125) {
                T_strided_slice[idx] = fmax(T_strided_slice[idx], T_concat[(((int)blockIdx.x) * 9216) + (((int)threadIdx.x) * 9) + k]);
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        int idx = i;
        int blockIdx_x = idx / 1024;
        int threadIdx_x = idx % 1024;
        if (idx < 1125) {
            T_concat[idx] = exp(T_concat[idx] - T_strided_slice[(idx / 9) * 90 + (idx % 9) * 9]);
        }
    }
}