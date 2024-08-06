#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < 2; k++) {
                #pragma omp simd
                for (int l = 0; l < 3; l++) {
                    int idx = (((i * 2 + j) * 2 + k) * 11 + l);
                    if ((i * 3 + l) < 374) {
                        compute[i * 3 + l] = roundf(data[idx]);
                    }
                }
            }
        }
    }
}
