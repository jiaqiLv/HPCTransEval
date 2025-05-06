void default_function_kernel(float* compute, float* ph, float* ph_1) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 10; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; ++threadIdx_x) {
            int idx = (blockIdx_x * 1024) + threadIdx_x;
            if (idx < 6250) {
                // Kernel 1: Copy from ph to T_strided_slice
                float T_strided_slice[idx] = ph[((((((((blockIdx_x * 128) + (threadIdx_x >> 3)) / 125) * 31944) + (((((blockIdx_x * 6) + (threadIdx_x >> 2)) % 250) / 25) * 1452)) + (((((blockIdx_x * 12) + (threadIdx_x >> 1)) % 50) / 5) * 44)) + (((blockIdx_x * 4) + threadIdx_x) % 10)) + 16973];

                // Kernel 2: Copy from ph_1 to T_strided_slice_1
                float T_strided_slice_1[idx] = ph_1[((((((((blockIdx_x * 128) + (threadIdx_x >> 3)) / 125) * 79860) + (((((blockIdx_x * 6) + (threadIdx_x >> 2)) % 250) / 25) * 2420)) + (((((blockIdx_x * 12) + (threadIdx_x >> 1)) % 50) / 5) * 55)) + (((blockIdx_x * 4) + threadIdx_x) % 10)) + 933559];

                // Kernel 3: Element-wise multiplication
                T_strided_slice[idx] *= T_strided_slice_1[idx];

                // Kernel 4: Apply exponential function
                T_strided_slice[idx] = expf(T_strided_slice[idx]);

                // Kernel 5: Clamp and scale
                float v = floorf(((fmaxf(fminf(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f);
                v <<= 23;
                float result = fmaxf(((*(float *)&v) * (((((((((((1.987569e-04f * (fmaxf(fminf(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (fmaxf(fminf(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (fmaxf(fminf(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (fmaxf(fminf(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (fmaxf(fminf(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (fmaxf(fminf(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (fmaxf(fminf(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (fmaxf(fminf(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_strided_slice[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f))), T_strided_slice[idx]);

                // Store the result in compute array
                compute[idx] = result;
            }
        }
    }
}