void default_function_kernel(float* T_transpose_red, float* ph) {
    int num_blocks = 5; // Assuming the number of blocks is derived from the input shape
    int num_threads_per_block = 1024; // Assuming the number of threads per block is 1024

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        if (((i / num_threads_per_block) * 32 + (i % num_threads_per_block) / 32) < 45) {
            int idx = i;
            float value = T_transpose_red[idx];
            value = max(min(value, 88.37627f), -88.37626f);
            int v_ = ((int)(floorf((value * 1.442695f) + 5.0f)) + 1270) << 23;
            value = ((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (value - floorf((value * 1.442695f) + 5.0f) * 6.931472e-01f)) + 1.398200e-03f) * (value - floorf((value * 1.442695f) + 5.0f) * 6.931472e-01f)) + 8.333452e-03f) * (value - floorf((value * 1.442695f) + 5.0f) * 6.931472e-01f)) + 4.166580e-02f) * (value - floorf((value * 1.442695f) + 5.0f) * 6.931472e-01f)) + 1.666667e-01f) * (value - floorf((value * 1.442695f) + 5.0f) * 6.931472e-01f)) + 5.000000e-01f) * (value - floorf((value * 1.442695f) + 5.0f) * 6.931472e-01f)) + 1.000000e+00f));
            T_transpose_red[idx] = value;
        }
    }
}