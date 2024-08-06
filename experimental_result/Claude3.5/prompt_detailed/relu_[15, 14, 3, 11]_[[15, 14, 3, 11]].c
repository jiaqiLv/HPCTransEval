#include <stdio.h>
#include <omp.h>

void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 14; j++) {
            for (int k = 0; k < 3; k++) {
                #pragma omp simd
                for (int l = 0; l < 11; l++) {
                    int idx = ((((i * 14 + j) * 3 + k) * 11) + l);
                    compute[idx] = data[idx] > 0.0f ? data[idx] : 0.0f;
                }
            }
        }
    }
}
