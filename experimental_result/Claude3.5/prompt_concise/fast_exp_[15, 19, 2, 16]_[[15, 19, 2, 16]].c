#include <math.h>

void default_function_kernel_CPU(float* T_fast_exp, float* data) {
    int gridDim_x = 15;
    int blockDim_x = 24;

    for (int blockIdx_x = 0; blockIdx_x < gridDim_x; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < blockDim_x; threadIdx_x++) {
            int index = blockIdx_x * blockDim_x + threadIdx_x;

            if (index < 15 * 19 * 2 * 16) {
                float value = data[index];

                float clamped_value = fmaxf(fminf(value, 88.37627f), -88.37626f);
                float exp_value = expf(clamped_value);

                // Complex expression, simplified for readability
                float result = exp_value * (1 + clamped_value - floorf((clamped_value * 1.442695f + 0.5f)) * 0.6931472f);

                T_fast_exp[index] = result;
            }
        }
    }
}

// |End-of-Code|