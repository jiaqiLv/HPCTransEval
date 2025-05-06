#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* adaptive_pool_sum, float* data, int batch_size, int height, int width) {
    #pragma omp parallel for collapse(2)
    for (int n = 0; n < batch_size; ++n) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                int idx = n * height * width + i * width + j;
                adaptive_pool_sum[idx] = 0.0f;
                for (int k = 0; k < 8; ++k) {
                    for (int l = 0; l < 8; ++l) {
                        int x = (i * 2) + k;
                        int y = (j * 2) + l;
                        if (x < height && y < width) {
                            int data_idx = n * height * width + x * width + y;
                            adaptive_pool_sum[idx] += data[data_idx];
                        }
                    }
                }
            }
        }
    }
}