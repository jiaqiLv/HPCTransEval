#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* data, float* space_to_depth, int batch_size, int channels, int height, int width) {
    int total_elements = batch_size * channels * height * width;
    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        int block_idx = i / (channels * height * width);
        int element_idx = i % (channels * height * width);
        int row = element_idx / width;
        int col = element_idx % width;
        int depth = element_idx / (height * width);
        int new_row = (row / 3) * 3 + (col / 3);
        int new_col = (row % 3) * 3 + (col % 3);
        int new_idx = (block_idx * channels * height * width) + (depth * height * width) + (new_row * width) + new_col;
        space_to_depth[new_idx] = data[i];
    }
}