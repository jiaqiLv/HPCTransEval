#include <math.h>
#include <omp.h>

void default_function_kernel(float* T_subtract, float* ph_0, float* ph_3, int num_blocks, int num_threads) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    #pragma omp parallel for collapse(2) private(blockIdx_x, threadIdx_x)
    for (blockIdx_x = 0; blockIdx_x < num_blocks; blockIdx_x++) {
        for (threadIdx_x = 0; threadIdx_x < num_threads; threadIdx_x++) {
            if (((blockIdx_x * 2) + (threadIdx_x >> 3)) < 9) {
                T_subtract[(blockIdx_x * 16) + threadIdx_x] = (ph_0[(blockIdx_x * 16) + threadIdx_x] - ph_3[(blockIdx_x * 16) + threadIdx_x]);
            }
        }
    }
}