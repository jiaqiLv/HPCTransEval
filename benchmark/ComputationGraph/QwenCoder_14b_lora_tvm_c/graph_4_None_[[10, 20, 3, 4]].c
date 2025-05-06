void default_function_kernel(float* T_transpose_red, float* ph) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 15; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; ++threadIdx_x) {
            int idx = (blockIdx_x * 1024) + threadIdx_x;
            if (idx < 45 * 32) {
                // Kernel 1
                T_reshape[idx] = ph[(((((((((blockIdx_x * 64) + (threadIdx_x >> 4)) / 15) * 240) + (((((((blockIdx_x * 16) + (threadIdx_x >> 2)) % 60) / 3) * 12)) + (((((threadIdx_x >> 2) + blockIdx_x) % 3) * 4)) + (threadIdx_x & 3))];

                // Kernel 2
                T_reshape[idx] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(T_reshape[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reshape[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(T_reshape[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reshape[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(T_reshape[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reshape[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(T_reshape[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reshape[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(T_reshape[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reshape[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (max(min(T_reshape[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reshape[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (max(min(T_reshape[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reshape[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(T_reshape[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reshape[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), T_reshape[idx]);

                // Kernel 3
                T_reshape[idx] = T_reshape_1[((((((((((blockIdx_x * 40) + (threadIdx_x >> 2)) % 72) / 3) * 60) + (((((blockIdx_x * 32) + (threadIdx_x >> 5)) / 9) * 12)) + (((((blockIdx_x * 4) + threadIdx_x) % 6) * 2)) + (((((blockIdx_x * 2) + (threadIdx_x >> 1)) % 6) / 3)))];

                // Kernel 4
                T_transpose_red[threadIdx_x] = 0.000000e+00f;
                for (int k1 = 0; k1 < 24; ++k1) {
                    T_transpose_red[threadIdx_x] = (T_transpose_red[threadIdx_x] + T_reshape[((((threadIdx_x / 12) * 288) + (k1 * 12)) + (threadIdx_x % 12))]);
                }

                // Kernel 5
                T_reshape[idx] = T_reshape_1[((((((((blockIdx_x * 256) + (threadIdx_x >> 2)) / 15) * 60) + ((((((blockIdx_x * 2) + (threadIdx_x >> 1)) % 30) * 2)) + (threadIdx_x & 1)))];
            }
        }
    }
}