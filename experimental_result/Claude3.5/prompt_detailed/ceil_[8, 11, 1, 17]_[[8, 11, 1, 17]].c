#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for
    for (int blockIdx_x = 0; blockIdx_x < 8; blockIdx_x++) {
        for (int blockIdx_y = 0; blockIdx_y < 11; blockIdx_y++) {
            for (int blockIdx_z = 0; blockIdx_z < 1; blockIdx_z++) {
                for (int threadIdx_x = 0; threadIdx_x < 17; threadIdx_x++) {
                    int global_idx = (blockIdx_x * 11 * 17) + (blockIdx_y * 17) + threadIdx_x;
                    int check_idx = (blockIdx_x * 4) + (threadIdx_x >> 3);
                    if (check_idx < 187) {
                        compute[global_idx] = ceilf(data[global_idx]);
                    }
                }
            }
        }
    }
}