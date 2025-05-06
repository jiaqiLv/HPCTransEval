#include <omp.h>
#include <stdio.h>

void default_function_kernel(float* __restrict__ A, float* __restrict__ W, float* __restrict__ group_conv2d_nchw, int batch_size, int input_channels, int input_height, int input_width, int output_channels, int kernel_size) {
    int output_height = input_height - kernel_size + 1;
    int output_width = input_width - kernel_size + 1;
    int output_size = batch_size * output_channels * output_height * output_width;

    #pragma omp parallel for
    for (int b = 0; b < batch_size; ++b) {
        for (int oc = 0; oc < output_channels; ++oc) {
            for (int oh = 0; oh < output_height; ++oh) {
                for (int ow = 0; ow < output_width; ++ow) {
                    int output_index = b * output_channels * output_height * output_width + oc * output_height * output_width + oh * output_width + ow;
                    group_conv2d_nchw[output_index] = 0.0f;
                    for (int rc = 0; rc < input_channels; ++rc) {
                        for (int kx = 0; kx < kernel_size; ++kx) {
                            for (int ky = 0; ky < kernel_size; ++ky) {
                                int input_x = ow + kx;
                                int input_y = oh + ky;
                                int input_index = b * input_channels * input_height * input_width + rc * input_height * input_width + input_y * input_width + input_x;
                                int weight_index = oc * input_channels * kernel_size * kernel_size + rc * kernel_size * kernel_size + ky * kernel_size + kx;
                                group_conv2d_nchw[output_index] += A[input_index] * W[weight_index];
                            }
                        }
                    }
                }
            }
        }
    }
}