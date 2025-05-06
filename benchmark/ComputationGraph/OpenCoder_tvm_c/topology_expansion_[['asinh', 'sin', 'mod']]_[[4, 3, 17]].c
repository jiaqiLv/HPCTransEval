#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* ph_0) {
    #pragma omp parallel for
    for (int i = 0; i < 12; i++) {
        compute[i] = asinhf(ph_0[i]);
    }
}