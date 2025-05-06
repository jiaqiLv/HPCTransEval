#include <omp.h>
#include <math.h>
#include <stdlib.h>

void default_function_kernel_8(float* __restrict__ T_cast, float* __restrict__ ph, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 11 * 22 * 33 * 44; ++i) {
        T_cast[i] = ph[i];
    }
}

void default_function_kernel_9(float* __restrict__ T_concat, float* __restrict__ T_strided_slice, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 11 * 20 * 10 * 10 * 9; ++i) {
        if (((i / 1024) * 64 + (i % 1024) / 32) < 1125) {
            T_concat[i] = T_strided_slice[i] * T_strided_slice[i];
        }
    }
}

void default_function_kernel_10(float* __restrict__ T_concat, float* __restrict__ T_multiply_red, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 20 * 10 * 10 * 9; ++i) {
        T_multiply_red[i] = 0.0f;
        for (int k1 = 0; k1 < 10; ++k1) {
            for (int k2 = 0; k2 < 10; ++k2) {
                T_multiply_red[i] += T_concat[(i / 9) * 900 + k1 * 90 + k2 * 9 + (i % 9)];
            }
        }
    }
}

void default_function_kernel_12(float* __restrict__ T_cast, float* __restrict__ T_strided_slice, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 11 * 20 * 10 * 10 * 9; ++i) {
        if (((i / 1024) * 64 + (i % 1024) / 32) < 1125) {
            T_cast[i] = T_strided_slice[i];
        }
    }
}

void default_function_kernel_2(float* __restrict__ T_concat, float* __restrict__ T_strided_slice, float* __restrict__ T_strided_slice_1, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 11 * 20 * 10 * 10 * 9; ++i) {
        if (((i / 1024) * 64 + (i % 1024) / 32) < 1125) {
            int idx = (1125 <= ((i / 1024) * 128 + (i % 1024) / 4) ? i - 9000 : i);
            T_concat[i] = T_strided_slice[idx];
        }
    }
}

void default_function_kernel_6(float* __restrict__ T_concat, float* __restrict__ T_strided_slice, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 11 * 20 * 10 * 10 * 9; ++i) {
        if (((i / 1024) * 64 + (i % 1024) / 32) < 1125) {
            T_concat[i] = T_concat[i] / T_strided_slice[(i / 9) * 9 + (i % 9)];
        }
    }
}

void default_function_kernel(float* __restrict__ T_strided_slice, float* __restrict__ ph, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 11 * 20 * 10 * 10 * 9; ++i) {
        if (((i / 1024) * 128 + (i % 1024) / 4) < 1125) {
            T_strided_slice[i] = ph[((((((((i / 1024) * 256 + (i % 1024) / 4) / 225) * 31944) + ((((i / 1024) * 62 + (i % 1024) / 4) % 450) / 45) * 1452) + ((((i / 1024) * 34 + (i % 1024)) % 90) / 9) * 44 + ((i / 1024) * 7 + (i % 1024)) % 9) + 50414)];
        }
    }
}

void default_function_kernel_11(float* __restrict__ T_cast, float* __restrict__ T_multiply_red, float* __restrict__ T_strided_slice, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 11 * 20 * 10 * 10 * 9; ++i) {
        if (((i / 1024) * 64 + (i % 1024) / 32) < 1125) {
            T_strided_slice[i] = T_strided_slice[i] * T_cast[(i / 9) * 10 + (i % 9)] * (1.0f / sqrtf((T_multiply_red[(i / 1024) * 9 + (i % 1024) / 32] * 0.01f) + 1.0f));
        }
    }
}

void default_function_kernel_3(float* __restrict__ T_concat, float* __restrict__ T_strided_slice, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 11 * 20 * 10 * 10 * 9; ++i) {
        if (((i / 1024) * 64 + (i % 1024) / 32) < 125) {
            T_strided_slice[i] = -3.402823e+38f;
        }
        for (int k = 0; k < 9; ++k) {
            if (((i / 1024) * 64 + (i % 1024) / 32) < 125) {
                T_strided_slice[i] = fmax(T_strided_slice[i], T_concat[(i / 1024) * 9216 + (i % 1024) * 9 + k]);
            }
        }
    }
}

void default_function_kernel_4(float* __restrict__ T_concat, float* __restrict__ T_strided_slice, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 11 * 20 * 10 * 10 * 9; ++i) {
        if (((i / 1024) * 64 + (i % 1024) / 32) < 1125) {
            T_concat[i] = expf(T_concat[i] - T_strided_slice[(i / 9) * 9]);
        }
    }
}