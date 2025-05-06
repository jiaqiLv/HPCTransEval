#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* ph_0) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 11; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 8; threadIdx_x++) {
            int idx = (blockIdx_x * 8) + threadIdx_x;
            compute[idx] = atanf(ph_0[idx] / cosf(ph_0[idx]));
        }
    }
}