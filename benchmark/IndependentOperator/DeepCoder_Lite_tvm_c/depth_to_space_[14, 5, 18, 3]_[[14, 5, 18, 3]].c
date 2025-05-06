#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

extern "C" void default_function_kernel(float* data, float* depth_to_space, int batch_size, int height, int width, int channels) {
    int num_blocks = batch_size * height * width;
    int num_threads = channels;

    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        int block_idx = i / (height * width);
        int spatial_idx = i % (height * width);
        int row = spatial_idx / width;
        int col = spatial_idx % width;
        int channel = (block_idx / (height * width)) * channels + (row % 2) * (height / 2) * channels + (col % 2) * (width / 2) * channels + (row / 2) * channels + (col / 2);
        depth_to_space[i] = data[((block_idx * height * width) + row * width + col)];
    }
}