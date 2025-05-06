#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* ph_0) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; j < 15; i++) {
        for (int j = 0; j < 18; j++) {
            compute[i * 18 + j] = ph_0[i * 18 + j]);
        }
    }
    }
}