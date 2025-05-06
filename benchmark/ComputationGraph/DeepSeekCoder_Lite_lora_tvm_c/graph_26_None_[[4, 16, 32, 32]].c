#include <cmath>
#include <algorithm>
#include <omp.h>

void default_function_kernel(float* __restrict__ ph, float* __restrict__ resize, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        if (((((i / threads_per_block) * 4) + (i % threads_per_block) / 25) < 625)) {
            int idx = i;
            float value = ph[((((((i / threads_per_block) * 256) + ((i % threads_per_block) / 2)) / 625) * 1024) + (std::min(std::max(static_cast<int>(std::floor((static_cast<float>(i % 1250) / 25 + 0.5) * 6.4 - 0.5)), 31), 0) * 32)) + std::min(std::max(static_cast<int>(std::floor((static_cast<float>(i % 50) + 0.5) * 6.4 - 0.5)), 31), 0)];
            resize[i] = value * (1.0 - (static_cast<float>(i % 50) + 0.5) * 6.4 / 25 - std::floor((static_cast<float>(i % 50) + 0.5) * 6.4 / 25)) + ph[((((((i / threads_per_block) * 256) + ((i % threads_per_block) / 2)) / 625) * 1024) + (std::min(std::max(static_cast<int>(std::floor((static_cast<float>(i % 1250) / 25 + 0.5) * 6.4 - 0.5)), 31), 0) * 32)) + std::min(std::max(static_cast<int>(std::floor((static_cast<float>(i % 50) + 0.5) * 6.4 - 0.5)) + 1, 31), 0) * (1.0 - (static_cast<float>(i % 50) + 0.5) * 6.4 / 25 - std::floor((static_cast<float>(i % 50) + 0.5) * 6.4 / 25))) + ph[((((((i / threads_per_block) * 256) + ((i % threads_per_block) / 2)) / 625) * 1024) + (std::min(std::max(static_cast<int>(std::floor((static_cast<float>(i % 1250) / 25 + 0.5) * 6.4 - 0.5)) + 1, 31), 0) * 32)) + std::min(std::max(static_cast<int>(std::floor((static_cast<float>(i % 50) + 0.5) * 6.4 - 0.5)) + 1, 31), 0) * (1.0 - (static_cast<float>(i % 50) + 0.5) * 6.4 / 25 - std::floor((static_cast<float>(i % 50) + 0.5) * 6.4 / 25)));
        }
    }
}

void default_function_kernel_3(float* __restrict__ resize, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        if (((((i / threads_per_block) * 4) + (i % threads_per_block) / 25) < 625)) {
            int idx = i;
            resize[i] = 1.0 / (1.0 + std::exp(-resize[i]));
        }
    }
}

void default_function_kernel_2(float* __restrict__ resize, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        if (((((i / threads_per_block) * 4) + (i % threads_per_block) / 25) < 625)) {
            int idx = i;
            resize[i] = std::cos(resize[i]);
        }
    }
}

void default_function_kernel_1(float* __restrict__ resize, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        if (((((i / threads_per_block) * 4) + (i % threads_per_block) / 25) < 625)) {
            int idx = i;
            resize[i] = std::asin(resize[i]);
        }
    }
}

void default_function_kernel_4(float* __restrict__ T_fast_exp, float* __restrict__ resize, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        if (((((i / threads_per_block) * 4) + (i % threads_per_block) / 25) < 625)) {
            int idx = i;
            int v_ = static_cast<int>(std::floor(std::max(std::min(resize[i], 88.37627f), -88.37626f) * 1.442695f) + 5.0 + 127.0) << 23;
            T_fast_exp[i] = std::max((static_cast<float>(v_) * ((((((((((((((1.987569e-04f * (std::max(std::min(resize[i], 88.37627f), -88.37626f) - static_cast<float>(std::floor(std::max(std::min(resize[i], 88.37627f), -88.37626f) * 1.442695f) + 5.0f)) * 6.931472e-01f))) + 1.398200e-03f) * (std::max(std::min(resize[i], 88.37627f), -88.37626f) - static_cast<float>(std::floor(std::max(std::min(resize[i], 88.37627f), -88.37626f) * 1.442695f) + 5.0f)) * 6.931472e-01f))) + 8.333452e-03f) * (std::max(std::min(resize[i], 88.37627f), -88.37626f) - static_cast<float>(std::floor(std::max(std::min(resize[i], 88.37627f), -88.37626f) * 1.442695f) + 5.0f)) * 6.931472e-01f))) + 8.333452e-03f) * (std::max(std::min(resize[i], 88.37627f), -88.37626f) - static_cast<float>(std::floor(std::max(std::min(resize[i], 88.37627f), -88.37626f) * 1.442695f) + 5.0f)) * 6.931472e-01f))) + 4.166580e-02f) * (std::max(std::min(resize[i], 88.37627f), -88.37626f) - static_cast<float>(std::floor(std::max(std::min(resize[i], 88.37627f), -88.37626f) * 1.442695f) + 5.0f)) * 6.931472e-01f))) + 1.666667e-02f) * (std::max(std::min(resize[i], 88.37627f), -88.37626f) - static_cast<float>(std::floor(std::max(std::min(resize[i], 88.37627f), -88.37626f) * 1.442695f) + 5.0f)) * 6.931472e-01f))) + 5.000000e-01f) * (std::max(std::min(resize[i], 88.37627f), -88.37626f) - static_cast<float>(std::floor(std::max(std::min(resize[i], 88.37627f), -88.37626f) * 1.442695f) + 5.0f)) * 6.931472e-01f))) * (std::max(std::min(resize[i], 88.37627f), -88.37626f) - static_cast<float>(std::floor(std::max(std::min(resize[i], 88.37627f), -88.37626f) * 1.442695f) + 5.0f)) * 6.931472e-01f))) + (std::max(std::min(resize[i], 88.37627f), -88.37626f) - static_cast<float>(std::floor(std::max(std::min(resize[i], 88.37627f), -88.37626f) * 1.442695f) + 5.0f)) * 6.931472e-01f))) + 1.000000e+00f)), resize[i]);
        }
    }
}