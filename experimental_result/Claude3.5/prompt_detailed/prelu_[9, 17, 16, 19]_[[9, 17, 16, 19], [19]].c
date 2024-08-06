#include <stdio.h>
#include <omp.h>

void default_function_kernel(float* Scale, float* compute, float* data) {
    #pragma omp parallel for
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 17; j++) {
            for (int k = 0; k < 16; k++) {
                #pragma omp simd
                for (int l = 0; l < 19; l++) {
                    int idx = ((((i * 17 + j) * 16 + k) * 19) + l);
                    compute[idx] = (0.0f < data[idx]) ? data[idx] : (data[idx] * Scale[l % 19]);
                }
            }
        }
    }
}
