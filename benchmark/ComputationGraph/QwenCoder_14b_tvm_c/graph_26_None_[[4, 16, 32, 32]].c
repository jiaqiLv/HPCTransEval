void default_function_kernel(float* T_fast_exp, float* ph) {
    const int num_threads = 1024;
    const int num_blocks = 625;

    #pragma omp parallel for collapse(2) num_threads(num_threads)
    for (int blockIdx = 0; blockIdx < num_blocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < num_threads; ++threadIdx) {
            int idx = (blockIdx * num_threads) + threadIdx;

            if (idx < 625 * num_threads) {
                // Kernel 1: asinf
                float value = ph[idx];
                value = asinf(value);
                ph[idx] = value;

                // Kernel 2: cosf
                value = ph[idx];
                value = cosf(value);
                ph[idx] = value;

                // Kernel 3: expf
                value = ph[idx];
                value = 1.0f / (1.0f + expf(-value));
                ph[idx] = value;

                // Kernel 4: resize calculation
                int x = (blockIdx * 256 + (threadIdx >> 2)) / 625;
                int y = (blockIdx * 512 + (threadIdx >> 1)) % 1250 / 25;
                int x_floor = floorf(((float)x + 0.5f) * 0.64f - 0.5f);
                int y_floor = floorf(((float)y + 0.5f) * 0.64f - 0.5f);
                x_floor = max(min(x_floor, 31), 0);
                y_floor = max(min(y_floor, 31), 0);

                float weight_x = ((float)x + 0.5f) * 0.64f - 0.5f - (float)x_floor;
                float weight_y = ((float)y + 0.5f) * 0.64f - 0.5f - (float)y_floor;

                float resized_value = (1.0f - weight_x) * (1.0f - weight_y) * ph[(x_floor * 32) + y_floor] +
                                      weight_x * (1.0f - weight_y) * ph[(x_floor * 32) + y_floor + 1] +
                                      (1.0f - weight_x) * weight_y * ph[((x_floor + 1) * 32) + y_floor] +
                                      weight_x * weight_y * ph[((x_floor + 1) * 32) + y_floor + 1];

                ph[idx] = resized_value;

                // Kernel 5: fast exp calculation
                value = ph[idx];
                value = max(min(value, 88.37627f), -88.37626f) * 1.442695f + 0.5f;
                int v_ = (int)(floorf(value) + 127.0f) << 23;
                float fast_exp_value = (*(float*)&v_) * (
                    1.987569e-4f * (value - floorf(value)) +
                    1.398200e-3f * (value - floorf(value)) +
                    8.333452e-3f * (value - floorf(value)) +
                    4.166580e-2f * (value - floorf(value)) +
                    1.666667e-1f * (value - floorf(value)) +
                    5.000000e-1f * (value - floorf(value)) +
                    (value - floorf(value))
                );
                T_fast_exp[idx] = max(fast_exp_value, ph[idx]);
            }
        }
    }
}