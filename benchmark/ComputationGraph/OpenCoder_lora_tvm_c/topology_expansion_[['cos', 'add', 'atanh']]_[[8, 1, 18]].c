#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* ph_0) {
    #pragma omp parallel for
    for (int i = 0; i < 8; ++i) {
        compute[i] = atanf((ph_0[i] + cosf(ph_0[i])));
    }
}