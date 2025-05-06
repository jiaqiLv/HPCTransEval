#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <omp.h>

void default_function_kernel(float* T_reverse_sequence, float* T_transpose, float* T_strided_slice, float* ph, int num_threads) {
    omp_set_num_threads(num_threads);
    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        float value = T_reverse_sequence[i];
        value = std::max(std::min(value, 88.37627f), -88.37626f);
        int v = static_cast<int>(std::floor(value * 1.442695f + 0.5f)) + 127;
        v <<= 23;
        float adjusted_value = (*reinterpret_cast<float*>(&v)) * (value - static_cast<int>(std::floor(value * 1.442695f + 0.5f)) * 0.6931472f + 1.398200e-03f) * (value - static_cast<int>(std::floor(value * 1.442695f + 0.5f)) * 0.6931472f) + 8.333452e-03f) * (value - static_cast<int>(std::floor(value * 1.442695f + 0.5f)) * 0.6931472f) + 4.166580e-02f) * (value - static_cast<int>(std::floor(value * 1.442695f + 0.5f)) * 0.6931472f) + 1.666667e-01f) * (value - static_cast<int>(std::floor(value * 1.442695f + 0.5f)) * 0.6931472f) + 5.000000e-01f) * (value - static_cast<int>(std::floor(value * 1.442695f + 0.5f)) * 0.6931472f)) + (value - static_cast<int>(std::floor(value * 1.442695f + 0.5f)) * 0.6931472f)) + 1.000000e+00f);
        T_reverse_sequence[i] = std::max(adjusted_value, T_reverse_sequence[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        T_transpose[i] = T_reverse_sequence[(i % 17) * 45 + i / 17];
    }

    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        T_strided_slice[i] = T_reverse_sequence[((i / 45) * 45 + (i % 9) + 36) - ((i % 45) / 9) * 9];
    }

    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        ph[((i / 9) * 12 + (i % 9)) + 61] = T_strided_slice[i];
    }
}

int main() {
    // Example usage
    int num_threads = 4; // Set the number of threads
    std::vector<float> T_reverse_sequence(1125); // Example data
    std::vector<float> T_transpose(1125);
    std::vector<float> T_strided_slice(1125);
    std::vector<float> ph(1125); // Example data

    // Initialize data (not shown here for brevity)

    default_function_kernel(&T_reverse_sequence[0], &T_transpose[0], &T_strided_slice[0], &ph[0], num_threads);

    // Output results or perform further actions (not shown here for brevity)
    return 0;
}