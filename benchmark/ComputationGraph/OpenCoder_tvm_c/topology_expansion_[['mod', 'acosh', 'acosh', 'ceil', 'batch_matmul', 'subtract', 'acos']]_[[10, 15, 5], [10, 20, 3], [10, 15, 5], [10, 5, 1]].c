#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* ph_0) {
    #pragma omp parallel for
    for (int i = 0; i < 10; i++) {
        compute[i] = ph_0[i]);
    }
}