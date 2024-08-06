#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for
    for (int blockIdx_x = 0; blockIdx_x < 17; blockIdx_x++) {
        for (int blockIdx_y = 0; blockIdx_y < 12; blockIdx_y++) {
            for (int blockIdx_z = 0; blockIdx_z < 7; blockIdx_z++) {
                for (int threadIdx_x = 0; threadIdx_x < 9; threadIdx_x++) {
                    int index = ((blockIdx_x * 12 * 7 * 9) + (blockIdx_y * 7 * 9) + (blockIdx_z * 9) + threadIdx_x);
                    compute[index] = atanf(data[index]);
                }
            }
        }
    }
}
