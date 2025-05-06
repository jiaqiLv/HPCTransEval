#include <math.h>
#include <omp.h>

void default_function_kernel(float* T_add, float* ph_0, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        T_add[i] = (__cosf(ph_0[i]) + ph_0[i]);
    }
}