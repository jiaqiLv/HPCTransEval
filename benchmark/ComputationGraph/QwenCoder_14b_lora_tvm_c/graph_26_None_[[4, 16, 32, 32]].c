void default_function_kernel(float* T_fast_exp, float* ph) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 625; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            int idx = (blockIdx_x * 1024) + threadIdx_x;

            // default_function_kernel_1
            ph[idx] = asinf(ph[idx]);

            // default_function_kernel_2
            ph[idx] = cosf(ph[idx]);

            // default_function_kernel_3
            ph[idx] = 1.0f / (1.0f + expf(-ph[idx]));

            // default_function_kernel
            int v_ = ((int)(floorf(((max(min(ph[idx], 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) + 127) << 23;
            T_fast_exp[idx] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(ph[idx], 8.837627f), -8.837626f) - (floorf(((max(min(ph[idx], 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) + 1.398200e-03f) * (max(min(ph[idx], 8.837627f), -8.837626f) - (floorf(((max(min(ph[idx], 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) + 8.333452e-03f) * (max(min(ph[idx], 8.837627f), -8.837626f) - (floorf(((max(min(ph[idx], 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) + 4.166580e-02f) * (max(min(ph[idx], 8.837627f), -8.837626f) - (floorf(((max(min(ph[idx], 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) + 1.666667e-01f) * (max(min(ph[idx], 8.837627f), -8.837626f) - (floorf(((max(min(ph[idx], 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) + 5.000000e-01f) * (max(min(ph[idx], 8.837627f), -8.837626f) - (floorf(((max(min(ph[idx], 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) * (max(min(ph[idx], 8.837627f), -8.837626f) - (floorf(((max(min(ph[idx], 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) + (max(min(ph[idx], 8.837627f), -8.837626f) - (floorf(((max(min(ph[idx], 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) + 1.000000e+00f)), ph[idx]);

            // default_function_kernel_4
            int blockIdx_x_ = blockIdx_x / 625;
            int threadIdx_x_ = threadIdx_x >> 2;
            int idx_ = ((blockIdx_x_ * 256) + threadIdx_x_) * 1024;
            int x = max(min((int)floorf((((((float)(((((blockIdx_x * 512) + (threadIdx_x >> 1)) % 1250) / 25)) + 0.5f) * 0.64f) - 0.5f))), 31), 0);
            int y = max(min((int)floorf((((((float)(((((blockIdx_x * 24) + threadIdx_x) % 50)) + 0.5f) * 0.64f) - 0.5f))), 31), 0);
            int x_ = max(min(x + 1, 31), 0);
            int y_ = max(min(y + 1, 31), 0);
            ph[idx] = (ph[idx_] + (ph[idx_ + x] * (1.0f - (((((float)(((((blockIdx_x * 24) + threadIdx_x) % 50)) + 0.5f) * 0.64f) - 0.5f)) - (float)((int)floorf((((((float)(((((blockIdx_x * 24) + threadIdx_x) % 50)) + 0.5f) * 0.64f) - 0.5f))))))) + (ph[idx_ + y] * (((((float)(((((blockIdx_x * 24) + threadIdx_x) % 50)) + 0.5f) * 0.64f) - 0.5f)) - (float)((int)floorf((((((float)(((((blockIdx_x * 24) + threadIdx_x) % 50)) + 0.5f) * 0.64f) - 0.5f))))))) + (ph[idx_ + x_] * (1.0f - (((((float)(((((blockIdx_x * 24) + threadIdx_x) % 50)) + 0.5f) * 0.64f) - 0.5f)) - (float)((int)floorf((((((float)(((((blockIdx_x * 24) + threadIdx_x) % 50)) + 0.5f) * 0.64f) - 0.5f))))))) + (ph[idx_ + y_] * (((((float)(((((blockIdx_x * 24) + threadIdx_x) % 50)) + 0.5f) * 0.64f) - 0.5f)) - (float)((int)floorf((((((float)(((((blockIdx_x * 24) + threadIdx_x) % 50)) + 0.5f) * 0.64f) - 0.5f))))))) + (ph[idx_ + x + y] * (((((float)(((((blockIdx_x * 24) + threadIdx_x) % 50)) + 0.5f) * 0.64f) - 0.5f)) - (float)((int)floorf((((((float)(((((blockIdx_x * 24) + threadIdx_x) % 50)) + 0.5f) * 0.64f) - 0.5f))))))) + (ph[idx_ + x_ + y] * (((((float)(((((blockIdx_x * 24) + threadIdx_x) % 50)) + 0.5f) * 0.64f) - 0.5f)) - (float)((int)floorf((((((float)(((((blockIdx_x * 24) + threadIdx_x) % 50)) + 0.5f) * 0.64f) - 0.5f))))))) + (ph[idx_ + x + y_] * (((((float)(((((blockIdx_x * 24) + threadIdx_x) % 50)) + 0.5f) * 0.64f) - 0.5f)) - (float)((int)floorf((((((float)(((((blockIdx_x * 24) + threadIdx_x) % 50)) + 0.5f) * 0.64f) - 0.5f))))))) + (ph[idx_ + x_ + y_] * (((((float)(((((blockIdx_x * 24) + threadIdx_x) % 50)) + 0.5f) * 0.64f) - 0.5f)) - (float)((int)floorf((((((float)(((((blockIdx_x * 24) + threadIdx_x) % 50)) + 0.5f) * 0.64f) - 0.5f)))))));
        }
    }
}