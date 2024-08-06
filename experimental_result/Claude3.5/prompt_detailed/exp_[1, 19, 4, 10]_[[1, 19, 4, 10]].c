#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for
    for (int blockIdx_x = 0; blockIdx_x < 1; blockIdx_x++) {
        for (int blockIdx_y = 0; blockIdx_y < 19; blockIdx_y++) {
            for (int blockIdx_z = 0; blockIdx_z < 4; blockIdx_z++) {
                for (int threadIdx_x = 0; threadIdx_x < 10; threadIdx_x++) {
                    int index = ((blockIdx_x * 19 * 4 * 10) + (blockIdx_y * 4 * 10) + (blockIdx_z * 10) + threadIdx_x);
                    compute[index] = expf(data[index]);
                }
            }
        }
    }
}
