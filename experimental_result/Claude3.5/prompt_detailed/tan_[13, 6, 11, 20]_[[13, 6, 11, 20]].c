#include <stdio.h>
#include <math.h>
#include <omp.h>

#define BLOCK_SIZE 55
#define GRID_SIZE_X 13
#define GRID_SIZE_Y 6
#define GRID_SIZE_Z 11
#define GRID_SIZE_W 20

void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for
    for (int x = 0; x < GRID_SIZE_X; x++) {
        for (int y = 0; y < GRID_SIZE_Y; y++) {
            for (int z = 0; z < GRID_SIZE_Z; z++) {
                for (int w = 0; w < GRID_SIZE_W; w++) {
                    int index = (x * GRID_SIZE_Y * GRID_SIZE_Z * GRID_SIZE_W) + (y * GRID_SIZE_Z * GRID_SIZE_W) + (z * GRID_SIZE_W) + w;
                    compute[index * BLOCK_SIZE + omp_get_thread_num()] = tan(data[index * BLOCK_SIZE + omp_get_thread_num()]);
                }
            }
        }
    }
}
