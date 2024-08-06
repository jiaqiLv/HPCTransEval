#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* T_add, float* data, float* data_1) {
    #pragma omp parallel for
    for (int blockIdx_x = 0; blockIdx_x < 14; blockIdx_x++) {
        for (int blockIdx_y = 0; blockIdx_y < 4; blockIdx_y++) {
            for (int blockIdx_z = 0; blockIdx_z < 7; blockIdx_z++) {
                for (int threadIdx_x = 0; threadIdx_x < 16; threadIdx_x++) {
                    int index = ((blockIdx_x * 4 * 7 * 16) + (blockIdx_y * 7 * 16) + (blockIdx_z * 16) + threadIdx_x);
                    T_add[index] = sqrtf(data[index]) + cosf(data_1[index]);
                }
            }
        }
    }
}
