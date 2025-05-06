#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* ph_0) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    #pragma omp parallel for collapse(2)
    for (blockIdx_x = 0; blockIdx_x < 3; blockIdx_x++) {
        for (threadIdx_x = 0; threadIdx_x < 16; threadIdx_x++) {
            compute[(blockIdx_x * 16) + threadIdx_x] = atanf(ph_0[(blockIdx_x * 16) + threadIdx_x]);