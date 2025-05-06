#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define BLOCK_SIZE 32

void default_function_kernel(float* compute, float* ph_0) {
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        compute[i] = asinhf(fmodf(ph_0[i], ceilf(ph_0[i])));
    }
}