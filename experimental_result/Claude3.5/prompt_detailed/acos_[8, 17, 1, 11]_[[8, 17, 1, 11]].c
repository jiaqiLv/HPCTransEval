#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for
    for (int blockIdx_x = 0; blockIdx_x < 8; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 17; threadIdx_x++) {
            compute[(blockIdx_x * 17) + threadIdx_x] = acosf(data[(blockIdx_x * 17) + threadIdx_x]);
        }
    }
}
