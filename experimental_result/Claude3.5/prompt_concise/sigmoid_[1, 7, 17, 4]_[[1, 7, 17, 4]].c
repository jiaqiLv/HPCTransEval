#include <math.h>

void default_function_kernel_cpu(float* compute, float* data) {
    for (int blockIdx_x = 0; blockIdx_x < 1; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < 7; ++threadIdx_x) {
            int index = (blockIdx_x * 7) + threadIdx_x;
            compute[index] = 1.000000e+00f / (1.000000e+00f + expf(0.000000e+00f - data[index]));
        }
    }
}
