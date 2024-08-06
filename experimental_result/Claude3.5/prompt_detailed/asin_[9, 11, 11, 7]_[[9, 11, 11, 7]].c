#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for
    for (int blockIdx_x = 0; blockIdx_x < 9; blockIdx_x++) {
        for (int blockIdx_y = 0; blockIdx_y < 11; blockIdx_y++) {
            for (int blockIdx_z = 0; blockIdx_z < 11; blockIdx_z++) {
                for (int threadIdx_x = 0; threadIdx_x < 7; threadIdx_x++) {
                    int index = ((blockIdx_x * 11 * 11 * 7) + (blockIdx_y * 11 * 7) + (blockIdx_z * 7) + threadIdx_x);
                    if ((blockIdx_x * 32 + threadIdx_x) < 7623) {
                        compute[index] = asinf(data[index]);
                    }
                }
            }
        }
    }
}
