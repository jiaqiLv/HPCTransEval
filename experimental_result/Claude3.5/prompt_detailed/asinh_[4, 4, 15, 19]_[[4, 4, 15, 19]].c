#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for
    for (int blockIdx_x = 0; blockIdx_x < 4; blockIdx_x++) {
        for (int blockIdx_y = 0; blockIdx_y < 4; blockIdx_y++) {
            for (int blockIdx_z = 0; blockIdx_z < 15; blockIdx_z++) {
                for (int threadIdx_x = 0; threadIdx_x < 19; threadIdx_x++) {
                    int index = ((blockIdx_x * 4 * 15 * 19) + (blockIdx_y * 15 * 19) + (blockIdx_z * 19) + threadIdx_x);
                    compute[index] = asinhf(data[index]);
                }
            }
        }
    }
}
