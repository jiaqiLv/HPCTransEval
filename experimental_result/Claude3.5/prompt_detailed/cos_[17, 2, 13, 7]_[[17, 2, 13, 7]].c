#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for
    for (int blockIdx_x = 0; blockIdx_x < 17; blockIdx_x++) {
        for (int blockIdx_y = 0; blockIdx_y < 2; blockIdx_y++) {
            for (int blockIdx_z = 0; blockIdx_z < 13; blockIdx_z++) {
                for (int threadIdx_x = 0; threadIdx_x < 7; threadIdx_x++) {
                    int index = ((blockIdx_x * 2 * 13 * 7) + (blockIdx_y * 13 * 7) + (blockIdx_z * 7) + threadIdx_x);
                    compute[index] = cosf(data[index]);
                }
            }
        }
    }
}
