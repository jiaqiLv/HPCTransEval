#include <stdio.h>
#include <omp.h>

void default_function_kernel(float* T_sign, float* data) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 13; k++) {
                for (int l = 0; l < 3; l++) {
                    #pragma omp simd
                    for (int m = 0; m < 16; m++) {
                        int blockIdx_x = i * 78 + j * 39 + k * 3 + l * 1 + m;
                        float val = data[blockIdx_x];
                        T_sign[blockIdx_x] = (val > 0.0f) ? 1.0f : ((val < 0.0f) ? -1.0f : 0.0f);
                    }
                }
            }
        }
    }
}

// End-of-Code