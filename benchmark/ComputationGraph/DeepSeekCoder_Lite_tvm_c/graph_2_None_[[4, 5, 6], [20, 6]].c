#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <omp.h>

void default_function_kernel_7(float* T_reshape, float* T_softmax_maxelem, float* T_softmax_norm, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 120; ++i) {
        T_softmax_norm[i] = T_reshape[i] / T_softmax_maxelem[i / 6];
    }
}

void default_function_kernel_3(float* T_reshape, float* T_softmax_maxelem, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 20; ++i) {
        T_softmax_maxelem[i] = -3.402823e+38f;
        for (int k = 0; k < 6; ++k) {
            T_softmax_maxelem[i] = std::max(T_softmax_maxelem[i], T_reshape[i * 6 + k]);
        }
    }
}

void default_function_kernel_2(float* T_reshape, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 120; ++i) {
        T_reshape[i] = std::max(T_reshape[i], 0.000000e+00f);
    }
}

void default_function_kernel(float* T_reshape, float* ph, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 120; ++i) {
        T_reshape[i] = ph[i];
    }
}

void default_function_kernel_6(float* T_reshape, float* T_softmax_maxelem, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 20; ++i) {
        T_softmax_maxelem[i] = 0.000000e+00f;
        for (int k = 0; k < 6; ++k) {
            T_softmax_maxelem[i] += T_reshape[i * 6 + k];
        }
    }
}

void default_function_kernel_1(float* T_reshape, float* ph, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 120; ++i) {
        T_reshape[i] = T_reshape[i] - ph[i];
    }
}

void default_function_kernel_4(float* T_reshape, float* T_softmax_maxelem, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 120; ++i) {
        T_reshape[i] = T_reshape[i] - T_softmax_maxelem[i / 6];
    }
}

void default_function_kernel_5(float* T_reshape, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 120; ++i) {
        int v_ = static_cast<int>(std::floor(std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f) + 1.270000e+02f;
        v_ = v_ << 23;
        T_reshape[i] = std::max(static_cast<float>((*(reinterpret_cast<double*>(&v_)) * ((((((((((((((1.987569e-04f * (std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - static_cast<int>(std::floor(std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - static_cast<int>(std::floor(std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - static_cast<int>(std::floor(std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - static_cast<int>(std::floor(std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - static_cast<int>(std::floor(std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - static_cast<int>(std::floor(std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - static_cast<int>(std::floor(std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - static_cast<int>(std::floor(std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), T_reshape[i]);
    }
}

void default_function_kernel(float* T_reshape, float* ph, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 120; ++i) {
        T_reshape[i] = ph[i];
    }
}

void default_function_kernel_4(float* T_reshape, float* T_softmax_maxelem, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 120; ++i) {
        T_reshape[i] = T_reshape[i] - T_softmax_maxelem[i / 6];
    }
}

void default_function_kernel_5(float* T_reshape, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 120; ++i) {
        int v_ = static_cast<int>(std::floor(std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f) + 1.270000e+02f;
        v_ = v_ << 23;
        T_reshape[i] = std::max(static_cast<float>((*(reinterpret_cast<double*>(&v_)) * ((((((((((((((1.987569e-04f * (std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - static_cast<int>(std::floor(std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - static_cast<int>(std::floor(std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - static_cast<int>(std::floor(std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - static_cast<int>(std::floor(std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - static_cast<int>(std::floor(std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - static_cast<int>(std::floor(std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - static_cast<int>(std::floor(std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) - static_cast<int>(std::floor(std::max(std::min(T_reshape[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), T_reshape[i]);
    }
}