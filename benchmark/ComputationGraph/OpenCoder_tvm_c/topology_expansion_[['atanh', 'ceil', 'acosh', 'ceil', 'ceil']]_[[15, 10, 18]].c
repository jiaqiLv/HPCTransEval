#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* ph_0) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    #pragma omp parallel for collapse(2)
    for (blockIdx_x = 0; blockIdx_x < 15; blockIdx_x++) {
        for (threadIdx_x = 0; threadIdx_x < 10; threadIdx_x++) {
            compute[(blockIdx_x * 10 + threadIdx_x)] = atanhf(ph_0[(blockIdx_x * 10 + threadIdx_x)]);
        }
    }
}