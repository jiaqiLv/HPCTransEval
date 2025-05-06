void default_function_kernel(float* T_transpose_red, float* ph) {
    const int num_threads = 1024;
    const int total_elements = 1024 * 45;

    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < total_elements; ++i) {
        int blockIdx_x = i / 1024;
        int threadIdx_x = i % 1024;

        if (((blockIdx_x * 32) + (threadIdx_x >> 5)) < 45) {
            int v_ = ((int)(floorf(((max(min(ph[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
            ph[i] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(ph[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(ph[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(ph[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(ph[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(ph[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (max(min(ph[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (max(min(ph[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(ph[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), ph[i]);
        }
    }

    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < total_elements; ++i) {
        int blockIdx_x = i / 1024;
        int threadIdx_x = i % 1024;

        if (((blockIdx_x * 32) + (threadIdx_x >> 5)) < 45) {
            T_transpose_red[i] = 0.000000e+00f;
            for (int k1 = 0; k1 < 24; ++k1) {
                T_transpose_red[i] += ph[((((((int)i / 12) * 288) + (k1 * 12)) + ((int)i % 12))];
            }
        }
    }
}