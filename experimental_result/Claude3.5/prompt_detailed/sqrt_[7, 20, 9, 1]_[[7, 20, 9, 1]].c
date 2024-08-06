#include <stdio.h>
#include <math.h>
#include <omp.h>

#define BLOCK_SIZE 36
#define GRID_SIZE_X 7
#define GRID_SIZE_Y 20
#define GRID_SIZE_Z 9

void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for
    for (int x = 0; x < GRID_SIZE_X; x++) {
        for (int y = 0; y < GRID_SIZE_Y; y++) {
            for (int z = 0; z < GRID_SIZE_Z; z++) {
                int index = (x * GRID_SIZE_Y * GRID_SIZE_Z) + (y * GRID_SIZE_Z) + z;
                compute[index * BLOCK_SIZE + omp_get_thread_num()] = sqrt(data[index * BLOCK_SIZE + omp_get_thread_num()]);
            }
        }
    }
}
