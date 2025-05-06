#include <omp.h>
#include <math.h>
#include <stdlib.h>

void default_function_kernel(float* T_strided_slice, float* ph) {
    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        T_strided_slice[i] = ph[i];
    }
}

void default_function_kernel_8(float* T_cast, float* ph) {
    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        T_cast[i] = ph[i];
    }
}

void default_function_kernel_9(float* T_concat, float* T_strided_slice) {
    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        if (i < 1125) {
            T_concat[i] = T_strided_slice[i] * T_strided_slice[i];
        }
    }
}

void default_function_kernel_10(float* T_concat, float* T_multiply_red) {
    #pragma omp parallel for
    for (int i = 0; i < 10; ++i) {
        T_multiply_red[i] = 0.000000e+00f;
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                T_multiply_red[i] += T_concat[(i * 90) + (j * 9) + k];
            }
        }
    }
}

void default_function_kernel_12(float* T_cast, float* T_strided_slice) {
    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        if (i < 1125) {
            T_cast[i] = T_strided_slice[i];
        }
    }
}

void default_function_kernel_2(float* T_concat, float* T_strided_slice, float* T_strided_slice_1) {
    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        if (i < 1125) {
            T_concat[i] = (i < 1125) ? T_strided_slice[i] : T_strided_slice_1[i];
        }
    }
}

void default_function_kernel_6(float* T_concat, float* T_strided_slice) {
    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        if (i < 1125) {
            T_concat[i] = T_concat[i] / T_strided_slice[i / 9];
        }
    }
}

void default_function_kernel_1(float* T_strided_slice, float* ph) {
    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        T_strided_slice[i] = ph[i];
    }
}

void default_function_kernel_7(float* T_concat, float* T_strided_slice) {
    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        if (i < 1125) {
            T_strided_slice[i] = T_concat[i];
        }
    }
}

void default_function_kernel_5(float* T_concat, float* T_strided_slice) {
    #pragma omp parallel for
    for (int i = 0; i < 125; ++i) {
        T_strided_slice[i] = 0.000000e+00f;
        for (int j = 0; j < 9; ++j) {
            T_strided_slice[i] += T_concat[(i * 9) + j];
        }
    }
}

void default_function_kernel_11(float* T_cast, float* T_multiply_red, float* T_strided_slice) {
    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        if (i < 1125) {
            T_strided_slice[i] = (T_strided_slice[i] * T_cast[(i / 9) * 10 + (i % 9)]) * (1.000000e+00f / sqrtf((T_multiply_red[(i / 9) * 9 + (i % 9)] * 1.000000e-02f) + 1.000000e-05f));
        }
    }
}

void default_function_kernel_3(float* T_concat, float* T_strided_slice) {
    #pragma omp parallel for
    for (int i = 0; i < 125; ++i) {
        T_strided_slice[i] = -3.402823e+38f;
        for (int j = 0; j < 9; ++j) {
            T_strided_slice[i] = fmaxf(T_strided_slice[i], T_concat[(i * 9) + j]);
        }
    }
}

void default_function_kernel_4(float* T_concat, float* T_strided_slice) {
    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        if (i < 1125) {
            T_concat[i] = expf(T_concat[i] - T_strided_slice[i / 9]);
        }
    }
}