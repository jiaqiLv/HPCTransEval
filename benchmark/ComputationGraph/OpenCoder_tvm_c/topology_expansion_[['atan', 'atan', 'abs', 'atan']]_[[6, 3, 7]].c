#include <math.h>
#include <omp.h>

void default_function_kernel_1(float* compute, float* ph_0) {
    #pragma omp parallel for
    for (int i = 0; i < 32; i++) {
        compute[i] = fabsf(atanf(ph_0[i]));