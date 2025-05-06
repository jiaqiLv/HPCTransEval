void default_function_kernel(float* T_transpose, float* ph) {
    #pragma omp parallel for
    for (int i = 0; i < 23; ++i) {
        float v_ = ((int)(floorf(((max(min(ph[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
        ph[i] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(ph[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(ph[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(ph[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(ph[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(ph[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (max(min(ph[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (max(min(ph[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(ph[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(ph[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), ph[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < 23; ++i) {
        T_transpose[i] = ph[(((((i / 45) * 45) + (i % 9)) + 36) - (((i % 45) / 9) * 9))];
    }

    #pragma omp parallel for
    for (int i = 0; i < 23; ++i) {
        ph[i] = T_transpose[((((i % 17) * 45) + (i / 17))];
    }
}