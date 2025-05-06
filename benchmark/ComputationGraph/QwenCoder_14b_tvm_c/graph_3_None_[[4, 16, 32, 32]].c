void default_function_kernel(float* T_fast_exp, float* ph) {
    const int num_threads = 1024;
    const int num_blocks = 625;

    #pragma omp parallel for collapse(2) num_threads(num_threads)
    for (int blockIdx_x = 0; blockIdx_x < num_blocks; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < num_threads; ++threadIdx_x) {
            int idx = (blockIdx_x * num_threads) + threadIdx_x;

            if (idx < 625 * num_threads) {
                // Kernel 1: default_function_kernel_1
                T_fast_exp[idx] *= 0.1f;

                // Kernel 2: default_function_kernel_2
                T_fast_exp[idx] = (0.0f < T_fast_exp[idx]) ? T_fast_exp[idx] : (T_fast_exp[idx] * 0.5f);

                // Kernel 3: default_function_kernel_3
                float value = ph[idx];
                value = fmaxf(fminf(value, 88.37627f), -88.37626f);
                value = (value * 1.442695f) + 0.5f;
                int v_ = ((int)floorf(value) + 127) << 23;
                T_fast_exp[idx] = fmaxf((*(float*)&v_) * (
                    1.987569e-4f * (value - floorf(value)) +
                    1.398200e-3f * (value - floorf(value)) +
                    8.333452e-3f * (value - floorf(value)) +
                    4.166580e-2f * (value - floorf(value)) +
                    1.666667e-1f * (value - floorf(value)) +
                    5.000000e-1f * (value - floorf(value)) +
                    (value - floorf(value))
                ), T_fast_exp[idx]);

                // Kernel 4: default_function_kernel
                float x = (float)(((blockIdx_x * 256) + (threadIdx_x >> 2)) / 625);
                float y = (float)(((blockIdx_x * 512) + (threadIdx_x >> 1)) % 1250) / 25;
                int ix = (int)floorf(y + 0.5f);
                int iy = (int)floorf(x + 0.5f);
                ix = fmaxf(fmin(ix, 31), 0);
                iy = fmaxf(fmin(iy, 31), 0);
                float fx = y + 0.5f - ix;
                float fy = x + 0.5f - iy;
                T_fast_exp[idx] = ph[(iy * 32 + ix) * 1024 + (iy * 32 + ix)] * (1.0f - fx) * (1.0f - fy) +
                                  ph[(iy * 32 + ix + 1) * 1024 + (iy * 32 + ix)] * fx * (1.0f - fy) +
                                  ph[(iy * 32 + ix) * 1024 + (iy * 32 + ix + 1)] * (1.0f - fx) * fy +
                                  ph[(iy * 32 + ix + 1) * 1024 + (iy * 32 + ix + 1)] * fx * fy;
            }
        }
    }
}