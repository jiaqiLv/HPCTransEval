void default_function_kernel(float* data, float* kernel, float* output_unpack) {
    const int num_batches = 2;
    const int num_out_channels = 64;
    const int num_in_channels = 32;
    const int kernel_size = 3;
    const int input_height = 256;
    const int input_width = 256;
    const int output_height = 254;
    const int output_width = 254;

    #pragma omp parallel for collapse(4)
    for (int b = 0; b < num_batches; ++b) {
        for (int oc = 0; oc < num_out_channels; ++oc) {
            for (int oh = 0; oh < output_height; ++oh) {
                for (int ow = 0; ow < output_width; ++ow) {
                    float sum = 0.0f;
                    for (int ic = 0; ic < num_in_channels; ++ic) {
                        for (int kh = 0; kh < kernel_size; ++kh) {
                            for (int kw = 0; kw < kernel_size; ++kw) {
                                int data_idx = ((b * num_in_channels * input_height * input_width) +
                                                (ic * input_height * input_width) +
                                                ((oh + kh) * input_width) +
                                                (ow + kw));
                                int kernel_idx = ((oc * num_in_channels * kernel_size * kernel_size) +
                                                  (ic * kernel_size * kernel_size) +
                                                  (kh * kernel_size) +
                                                  kw);
                                sum += data[data_idx] * kernel[kernel_idx];
                            }
                        }
                    }
                    int output_idx = ((b * num_out_channels * output_height * output_width) +
                                      (oc * output_height * output_width) +
                                      (oh * output_width) +
                                      ow);
                    output_unpack[output_idx] = sum;
                }
            }
        }
    }
}