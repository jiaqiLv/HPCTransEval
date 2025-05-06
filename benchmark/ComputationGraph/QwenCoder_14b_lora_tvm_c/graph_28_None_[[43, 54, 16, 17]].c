include <cmath>
#include <vector>
#include <omp.h>

void default_function_kernel(float* T_transpose, float* ph, float* T_strided_slice, int size) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 15; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; ++threadIdx_x) {
            if (((blockIdx_x * 8) + (threadIdx_x >> 7)) < 15) {
                int index = (((((blockIdx_x * 16) + (threadIdx_x >> 6)) / 3) * 192) +
                             (((((blockIdx_x * 8) + (threadIdx_x >> 3)) % 24) / 3) * 24) +
                             ((((blockIdx_x * 4) + (threadIdx_x >> 2)) % 6) * 4) +
                             (threadIdx_x & 3));
                
                // Kernel 1: Copy from ph to T_transpose
                T_transpose[index] = ph[index];
                
                // Kernel 2: Apply log2 to T_transpose
                T_transpose[index] = std::log2(T_transpose[index]);
                
                // Kernel 3: Apply cos to T_transpose
                T_transpose[index] = std::cos(T_transpose[index]);
                
                // Kernel 4: Copy from T_transpose to T_strided_slice
                T_strided_slice[blockIdx_x * 1024 + threadIdx_x] = T_transpose[index];
                
                // Kernel 5: Fast exp calculation on T_strided_slice
                float x = T_strided_slice[blockIdx_x * 1024 + threadIdx_x];
                x = std::max(std::min(x, 8.837627f), -8.837626f);
                int v = static_cast<int>(std::floor((x * 1.442695f) + 0.5f)) + 127;
                v <<= 23;
                float result = (*(float*)&v) *
                               (1.987569e-04f * (x - std::floor((x * 1.442695f) + 0.5f)) +
                                1.398200e-03f * (x - std::floor((x * 1.442695f) + 0.5f)) +
                                8.333452e-03f * (x - std::floor((x * 1.442695f) + 0.5f)) +
                                4.166580e-02f * (x - std::floor((x * 1.442695f) + 0.5f)) +
                                1.666667e-01f * (x - std::floor((x * 1.442695f) + 0.5f)) +
                                5.000000e-01f * (x - std::floor((x * 1.442695f) + 0.5f)) +
                                (x - std::floor((x * 1.442695f) + 0.5f)) + 1.0f);
                T_strided_slice[blockIdx_x * 1024 + threadIdx_x] = std::max(result, T_strided_slice[blockIdx_x * 1024 + threadIdx_x]);
            }
        }
    }
}