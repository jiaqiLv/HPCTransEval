#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

extern "C" void default_function_kernel(float* __restrict__ A, float* __restrict__ W, float* __restrict__ group_conv2d_nchw, int num_groups, int input_height, int input_width, int output_height, int output_width) {
    int num_blocks = num_groups * output_height * output_width;
    #pragma omp parallel for
    for (int block_idx = 0; block_idx < num_blocks; ++block_idx) {
        int block_z = block_idx / (output_height * output_width);
        int block_y = (block_idx % (output_height * output_width)) / output_width;
        int block_x = (block_idx % (output_height * output_width)) % output_width;

        float group_conv2d_nchw_local[1] = {0.000000e+00f};
        __shared__ float pad_temp_shared[1];
        __shared__ float W_shared[1];

        for (int rc_outer = 0; rc_outer < 8; ++rc_outer) {
            for (int ry_outer = 0; ry_outer < 3; ++ry_outer) {
                for (int rx_outer = 0; rx_outer < 3; ++rx_outer) {
                    int pad_temp_index = (((((((block_z * input_height + block_y) * input_width + rx_outer) * input_width + ry_outer) * input_width + block_x) % input_width) % input_height) % input_width;
                    int W_index = (((rc_outer * 3) + ry_outer) * 3 + rx_outer) % 72;
                    pad_temp_shared[0] = A[pad_temp_index];
                    W_shared[0] = W[W_index];
                    group_conv2d_nchw_local[0] += (pad_temp_shared[0] * W_shared[0]);
                }
            }
        }
        group_conv2d_nchw[block_idx] = group_conv2d_nchw_local[0];
    }
}