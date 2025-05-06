#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* data, int num_elements) {
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        if (i < 7623) {
            compute[i] = asinf(data[i]);
        }
    }
}