void default_function_kernel(float* T_fast_exp, float* ph) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 625; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            int idx = (blockIdx_x * 1024) + threadIdx_x;

            // Kernel 1: Multiply by 0.1
            T_fast_exp[idx] = T_fast_exp[idx] * 1.000000e-01f;

            // Kernel 2: Clamp to positive values
            T_fast_exp[idx] = (0.000000e+00f < T_fast_exp[idx]) ? T_fast_exp[idx] : (T_fast_exp[idx] * 5.000000e-01f);

            // Kernel 3: Resize and interpolate
            int x = ((blockIdx_x * 256) + (threadIdx_x >> 2)) / 625;
            int y = ((blockIdx_x * 512) + (threadIdx_x >> 1)) % 1250 / 25;
            int x_floor = floorf(((float)x + 5.000000e-01f) * 6.400000e-01f - 5.000000e-01f);
            int y_floor = floorf(((float)y + 5.000000e-01f) * 6.400000e-01f - 5.000000e-01f);
            int x_ceil = x_floor + 1;
            int y_ceil = y_floor + 1;
            x_floor = max(min(x_floor, 31), 0);
            y_floor = max(min(y_floor, 31), 0);
            x_ceil = max(min(x_ceil, 31), 0);
            y_ceil = max(min(y_ceil, 31), 0);

            float wx = (((float)x + 5.000000e-01f) * 6.400000e-01f - 5.000000e-01f) - (float)x_floor;
            float wy = (((float)y + 5.000000e-01f) * 6.400000e-01f - 5.000000e-01f) - (float)y_floor;

            T_fast_exp[idx] = (ph[(x_floor * 32) + y_floor] * (1.000000e+00f - wx) * (1.000000e+00f - wy)) +
                              (ph[(x_ceil * 32) + y_floor] * wx * (1.000000e+00f - wy)) +
                              (ph[(x_floor * 32) + y_ceil] * (1.000000e+00f - wx) * wy) +
                              (ph[(x_ceil * 32) + y_ceil] * wx * wy);

            // Kernel 4: Fast exponential approximation
            float v_ = floorf(((max(min(T_fast_exp[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f;
            int exp_bits = (int)(v_ << 23);
            float frac = T_fast_exp[idx] - (v_ * 6.931472e-01f);
            float poly = 1.987569e-04f * frac +
                         1.398200e-03f * frac * frac +
                         8.333452e-03f * frac * frac * frac +
                         4.166580e-02f * frac * frac * frac * frac +
                         1.666667e-01f * frac * frac * frac * frac * frac +
                         5.000000e-01f * frac * frac * frac * frac * frac * frac;
            T_fast_exp[idx] = (*(float*)&exp_bits) * poly;
        }
    }
}