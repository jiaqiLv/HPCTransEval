void default_function_kernel(float* T_fast_exp, float* ph) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 15; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            int index = blockIdx_x * 8 + (threadIdx_x >> 7);
            if (index < 15) {
                int idx = (((((blockIdx_x * 16) + (threadIdx_x >> 6)) / 3) * 192) +
                           (((((blockIdx_x * 8) + (threadIdx_x >> 3)) % 24) / 3) * 24) +
                           ((((blockIdx_x * 4) + (threadIdx_x >> 2)) % 6) * 4) +
                           (threadIdx_x & 3));

                // Kernel 1: Copy from ph to T_transpose
                T_fast_exp[idx] = ph[idx];

                // Kernel 2: Compute log2 and store in T_transpose
                T_fast_exp[idx] = log2f(T_fast_exp[idx]);

                // Kernel 3: Copy from T_transpose to T_strided_slice
                T_fast_exp[((blockIdx_x * 1024) + threadIdx_x)] = T_fast_exp[idx];

                // Kernel 4: Fast exp computation
                float x = T_fast_exp[((blockIdx_x * 1024) + threadIdx_x)];
                x = fmaxf(fminf(x, 8.837627e+01f), -8.837626e+01f);
                int v = (int)(floorf(x * 1.442695e+00f + 5.000000e-01f) + 1.270000e+02f) << 23;
                float y = x - floorf(x * 1.442695e+00f + 5.000000e-01f);
                T_fast_exp[((blockIdx_x * 1024) + threadIdx_x)] = fmaxf(
                    (*(float*)&v) * (
                        1.987569e-04f * y +
                        1.398200e-03f * y * y +
                        8.333452e-03f * y * y * y +
                        4.166580e-02f * y * y * y * y +
                        1.666667e-01f * y * y * y * y * y +
                        5.000000e-01f * y * y * y * y * y * y +
                        y * y * y * y * y * y * y
                    ),
                    T_fast_exp[((blockIdx_x * 1024) + threadIdx_x)]
                );

                // Kernel 5: Compute cos and store in T_transpose
                T_fast_exp[idx] = cosf(T_fast_exp[idx]);
            }
        }
    }
}