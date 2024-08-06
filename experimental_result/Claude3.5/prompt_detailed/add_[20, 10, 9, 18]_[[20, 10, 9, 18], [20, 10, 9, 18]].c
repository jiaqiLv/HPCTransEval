#include <stdio.h>
#include <omp.h>

void default_function_kernel(float* T_add, float* data, float* data_1) {
    #pragma omp parallel for
    for (int blockIdx_x = 0; blockIdx_x < 20; blockIdx_x++) {
        for (int blockIdx_y = 0; blockIdx_y < 10; blockIdx_y++) {
            for (int blockIdx_z = 0; blockIdx_z < 9; blockIdx_z++) {
                for (int threadIdx_x = 0; threadIdx_x < 18; threadIdx_x++) {
                    int index = ((blockIdx_x * 10 * 9 * 18) + (blockIdx_y * 9 * 18) + (blockIdx_z * 18) + threadIdx_x);
                    T_add[index] = data[index] + data_1[index];
                }
            }
        }
    }
}
