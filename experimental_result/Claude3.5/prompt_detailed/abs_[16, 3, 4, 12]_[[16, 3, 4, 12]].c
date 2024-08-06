#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for
    for (int blockIdx_x = 0; blockIdx_x < 16; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 64; threadIdx_x++) {
            compute[(blockIdx_x * 64) + threadIdx_x] = fabsf(data[(blockIdx_x * 64) + threadIdx_x]);
        }
    }
}
