#include <stdio.h>
#include <omp.h>

void default_function_kernel(float* Scale, float* ScaleShift, float* Shift, float* data) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 16; k++) {
                for (int l = 0; l < 14; l++) {
                    #pragma omp simd
                    for (int m = 0; m < 7; m++) {
                        int blockIdx_x = i * 448 + j * 224 + k * 14 + l * 7 + m;
                        ScaleShift[blockIdx_x] = (data[blockIdx_x] * Scale[((i % 49) * 2 + (j >> 5) / 49) * 7 + (i + j) % 7]) +
                                                  Shift[((i % 49) * 2 + (j >> 5) / 49) * 7 + (i + j) % 7];
                    }
                }
            }
        }
    }
}

// End-of-Code