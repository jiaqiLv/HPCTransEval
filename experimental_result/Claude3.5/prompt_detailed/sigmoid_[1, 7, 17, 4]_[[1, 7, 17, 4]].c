#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 17; k++) {
                for (int l = 0; l < 4; l++) {
                    #pragma omp simd
                    for (int m = 0; m < 7; m++) {
                        int blockIdx_x = i * 119 + j * 17 + k * 4 + l * 1 + m;
                        compute[blockIdx_x] = 1.0f / (1.0f + expf(0.0f - data[blockIdx_x]));
                    }
                }
            }
        }
    }
}

// End-of-Code