#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* T_fast_exp, float* data) {
    #pragma omp parallel for
    for (int blockIdx_x = 0; blockIdx_x < 15; blockIdx_x++) {
        for (int blockIdx_y = 0; blockIdx_y < 19; blockIdx_y++) {
            for (int blockIdx_z = 0; blockIdx_z < 2; blockIdx_z++) {
                for (int threadIdx_x = 0; threadIdx_x < 16; threadIdx_x++) {
                    int index = ((blockIdx_x * 19 * 2 * 16) + (blockIdx_y * 2 * 16) + (blockIdx_z * 16) + threadIdx_x);

                    float v_ = floorf(fmaxf(fminf(data[index], 88.37627f), -88.37626f) * 1.442695f + 0.5f) + 127.0f;
                    int v_int = ((int)v_) << 23;

                    float result = fmaxf(*(float*)(&v_int) *
                        (
                            (
                                1.987569e-04f * (fmaxf(fminf(data[index], 88.37627f), -88.37626f) - (floorf(fmaxf(fminf(data[index], 88.37627f), -88.37626f) * 1.442695f) * 0.6931472f))
                                + 1.398200e-03f * (fmaxf(fminf(data[index], 88.37627f), -88.37626f) - (floorf(fmaxf(fminf(data[index], 88.37627f), -88.37626f) * 1.442695f) * 0.6931472f))
                                + 8.333452e-03f * (fmaxf(fminf(data[index], 88.37627f), -88.37626f) - (floorf(fmaxf(fminf(data[index], 88.37627f), -88.37626f) * 1.442695f) * 0.6931472f))
                                + 4.166580e-02f * (fmaxf(fminf(data[index], 88.37627f), -88.37626f) - (floorf(fmaxf(fminf(data[index], 88.37627f), -88.37626f) * 1.442695f) * 0.6931472f))
                                + 1.666667e-01f * (fmaxf(fminf(data[index], 88.37627f), -88.37626f) - (floorf(fmaxf(fminf(data[index], 88.37627f), -88.37626f) * 1.442695f) * 0.6931472f))
                                + 0.5f * (fmaxf(fminf(data[index], 88.37627f), -88.37626f) - (floorf(fmaxf(fminf(data[index], 88.37627f), -88.37626f) * 1.442695f) * 0.6931472f))
                            ) 
                            * (fmaxf(fminf(data[index], 88.37627f), -88.37626f) - (floorf(fmaxf(fminf(data[index], 88.37627f), -88.37626f) * 1.442695f) * 0.6931472f))
                            + (fmaxf(fminf(data[index], 88.37627f), -88.37626f) - (floorf(fmaxf(fminf(data[index], 88.37627f), -88.37626f) * 1.442695f) * 0.6931472f))
                            + 1.0f
                        ), data[index]);

                    T_fast_exp[index] = result;
                }
            }
        }
    }
}
