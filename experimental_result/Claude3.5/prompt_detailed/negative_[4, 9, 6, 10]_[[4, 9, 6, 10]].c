#include <stdio.h>
#include <omp.h>

void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 6; k++) {
                #pragma omp simd
                for (int l = 0; l < 10; l++) {
                    int idx = ((((i * 9 + j) * 6 + k) * 10) + l);
                    compute[idx] = data[idx] * -1.0f;
                }
            }
        }
    }
}
