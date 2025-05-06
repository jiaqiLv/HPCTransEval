#include <omp.h>
#include <stdio.h>

extern "C" void default_function_kernel(float* data, float* space_to_depth, int batch_size, int channels, int height, int width) {
    int output_height = height / 3;
    int output_width = width / 3;
    int output_channels = channels * 4;

    #pragma omp parallel for
    for (int b = 0; b < batch_size; ++b) {
        for (int h = 0; h < output_height; ++h) {
            for (int w = 0; w < output_width; ++w) {
                for (int c = 0; c < output_channels; ++c) {
                    int input_index = (((b * height + h) * width + w * 3 + c % 3) * 3 + c / 3) * 3 + (c % 3) / 3;
                    int output_index = ((b * output_height + h) * output_width + w) * output_channels + c;
                    space_to_depth[output_index] = data[input_index];
                }
            }
        }
    }
}