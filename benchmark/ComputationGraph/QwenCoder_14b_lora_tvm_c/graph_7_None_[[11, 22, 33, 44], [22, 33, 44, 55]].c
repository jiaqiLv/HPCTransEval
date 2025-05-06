void default_function_kernel(float* T_fast_exp, float* ph, float* ph_1) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 10; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            int index = (blockIdx_x * 1024) + threadIdx_x;
            if (index < 625) {
                // Kernel 1
                T_fast_exp[index] = ph[((((((((((blockIdx_x * 128) + (threadIdx_x >> 3)) / 125) * 79860) + (((((blockIdx_x * 6) + (threadIdx_x >> 2)) % 250) / 25) * 2420)) + (((((blockIdx_x * 12) + (threadIdx_x >> 1)) % 50) / 5) * 55)) + (((blockIdx_x * 4) + threadIdx_x) % 10)) + 933559)];

                // Kernel 3
                int v_ = ((int)(floorf(((max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
                T_fast_exp[index] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), T_fast_exp[index]);

                // Kernel 2
                T_fast_exp[index] *= T_fast_exp[index];

                // Kernel 4
                T_fast_exp[index] = ph_1[index];
            }
        }
    }
}