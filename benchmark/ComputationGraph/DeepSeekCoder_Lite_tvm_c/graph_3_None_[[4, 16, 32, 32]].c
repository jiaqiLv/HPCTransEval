void default_function_kernel(float* __restrict__ T_fast_exp, float* __restrict__ ph, float* __restrict__ resize, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int idx = b * 1024 + t;
            if (idx < 625) {
                int v = (int)(floorf(max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f) + 1.270000e+02f;
                v <<= 23;
                T_fast_exp[idx] = max(((*(float *)(&(v))) * ((((((((((((((1.987569e-04f * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))) + (max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) - (floorf(max(min(resize[idx], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f))) + 1.000000e+00f)), resize[idx]);
            }
        }
    }
}