void default_function_kernel(float* T_fast_exp, float* ph, float* ph_1) {
    int num_blocks = 625; // Assuming the number of blocks is fixed based on the CUDA kernel code
    int threads_per_block = 1024;

    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * threads_per_block + t;
            if (index < 625) {
                T_fast_exp[index] = ph[((((((((((b * 128) + (t >> 3)) / 125) * 79860) + (((((((b * 6) + (t >> 2)) % 250) / 25) * 2420)) + (((((((b * 12) + (t >> 1)) % 50) / 5) * 55)) + ((((b * 4) + t) % 10)) + 933559)))]);
            }
        }
    }

    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * threads_per_block + t;
            if (index < 625) {
                int v_ = ((int)(floorf(((fmaxf(fminf(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
                T_fast_exp[index] = (float)((((*(unsigned int *)(&(v_))) * ((((((((((((((1.987569e-04f * (fmaxf(fminf(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (fmaxf(fminf(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (fmaxf(fminf(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (fmaxf(fminf(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (fmaxf(fminf(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (fmaxf(fminf(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (fmaxf(fminf(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (fmaxf(fminf(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(T_fast_exp[index], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), T_fast_exp[index]);
            }
        }
    }

    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * threads_per_block + t;
            if (index < 625) {
                T_fast_exp[index] = T_fast_exp[index] * T_strided_slice_1[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))];
            }
        }
    }
}