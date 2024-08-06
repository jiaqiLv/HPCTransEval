#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define BLOCK_SIZE 15
#define GRID_SIZE_X 18
#define GRID_SIZE_Y 11
#define GRID_SIZE_Z 10

void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for collapse(3)
    for (int i = 0; i < GRID_SIZE_X; i++) {
        for (int j = 0; j < GRID_SIZE_Y; j++) {
            for (int k = 0; k < GRID_SIZE_Z; k++) {
                for (int l = 0; l < BLOCK_SIZE; l++) {
                    int idx = ((((i * GRID_SIZE_Y + j) * GRID_SIZE_Z + k) * BLOCK_SIZE + l));
                    compute[idx] = floorf(data[idx]);
                }
            }
        }
    }
}

int main() {
    float* compute = (float*)malloc(sizeof(float) * 3 * 18 * 11 * 10);
    float* data = (float*)malloc(sizeof(float) * 3 * 18 * 11 * 10);

    // Fill data with values

    default_function_kernel(compute, data);

    // Print or use compute

    free(compute);
    free(data);

    return 0;
}
