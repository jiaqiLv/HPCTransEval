void default_function_kernel(float* compute, float* ph, float* ph_1) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 10; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; ++threadIdx_x) {
            int idx = (blockIdx_x * 1024) + threadIdx_x;
            if (idx < 625 * 16) {
                // Kernel 1
                compute[idx] = ph[((((((((blockIdx_x * 128) + (threadIdx_x >> 3)) / 125) * 31944) + (((((blockIdx_x * 6) + (threadIdx_x >> 2)) % 250) / 25) * 1452)) + (((((blockIdx_x * 12) + (threadIdx_x >> 1)) % 50) / 5) * 44)) + (((blockIdx_x * 4) + threadIdx_x) % 10)) + 16973];

                // Kernel 2
                compute[idx] *= ph_1[((((((((blockIdx_x * 128) + (threadIdx_x >> 3)) / 125) * 79860) + (((((blockIdx_x * 6) + (threadIdx_x >> 2)) % 250) / 25) * 2420)) + (((((blockIdx_x * 12) + (threadIdx_x >> 1)) % 50) / 5) * 55)) + (((blockIdx_x * 4) + threadIdx_x) % 10)) + 933559];

                // Kernel 3
                float v_ = ((int)(floorf(((max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
                compute[idx] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(compute[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), compute[idx]);

                // Kernel 4
                compute[idx] = expf(compute[idx]);
            }
        }
    }
}