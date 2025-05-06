void default_function_kernel(float* data, float* kernel, float* output_unpack) {
    #pragma omp parallel for
    for (int z = 0; z < 2; ++z) {
        for (int y = 0; y < 254; ++y) {
            for (int x = 0; x < 254; ++x) {
                int output_index = (z * 508) + (y * 254) + x;
                output_unpack[output_index] = 0.0f;
                output_unpack[output_index + 516128] = 0.0f;
                output_unpack[output_index + 1032256] = 0.0f;
                output_unpack[output_index + 1548384] = 0.0f;

                for (int c = 0; c < 64; ++c) {
                    for (int ry = 0; ry < 3; ++ry) {
                        for (int rx = 0; rx < 3; ++rx) {
                            int data_index = ((z * 2097152) + (c * 131072) + ((z / 2) * 65536) + (y * 512) + ((z % 2) * 256) + (x * 2) + ((ry * 4) + rx));
                            int kernel_index = ((z % 2) * 9216) + ((c * 1152) + ((x * 36) + (ry * 3) + rx));
                            float data_value = data[data_index];
                            float kernel_value = kernel[kernel_index];
                            output_unpack[output_index] += data_value * kernel_value;
                            output_unpack[output_index + 516128] += data_value * kernel[kernel_index + 144];
                            output_unpack[output_index + 1032256] += data_value * kernel[kernel_index + 288];
                            output_unpack[output_index + 1548384] += data_value * kernel[kernel_index + 432];
                        }
                    }
                }
            }
        }
    }
}