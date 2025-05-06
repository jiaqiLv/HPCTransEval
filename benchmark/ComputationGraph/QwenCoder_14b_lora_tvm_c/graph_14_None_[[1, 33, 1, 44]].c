void default_function_kernel(float* T_softmax_norm, float* ph) {
    const int size = 11979 * 1024;

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        T_softmax_norm[i] = ph[i % 1452];
    }

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        T_softmax_norm[i] = sqrtf(T_softmax_norm[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        T_softmax_norm[i] = T_softmax_norm[i] - T_softmax_norm[((((i / 33) % 1089) / 33) * 528 + (((i / 12) % 132) / 11) * 44 + (i % 44))];
    }

    #pragma omp parallel for
    for (int i = 0; i < 1089 * 1024; ++i) {
        T_softmax_norm[i] = 0.0f;
        for (int k = 0; k < 11; ++k) {
            T_softmax_norm[i] += T_softmax_norm[(k * 17424) + i];
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        T_softmax_norm[i] = T_softmax_norm[((i / 33) * 44) + (i % 44)];
    }

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        int v = ((int)(floorf(((max(min(T_softmax_norm[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
        float exp_value = (*(float *)(&(v))) * ((((((((((((((1.987569e-04f * (max(min(T_softmax_norm[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_softmax_norm[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(T_softmax_norm[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_softmax_norm[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(T_softmax_norm[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_softmax_norm[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(T_softmax_norm[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_softmax_norm[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(T_softmax_norm[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_softmax_norm[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (max(min(T_softmax_norm[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_softmax_norm[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (max(min(T_softmax_norm[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_softmax_norm[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(T_softmax_norm[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_softmax_norm[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f));
        T_softmax_norm[i] = max(exp_value, T_softmax_norm[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        T_softmax_norm[i] = T_softmax_norm[i] / T_softmax_norm[((((i / 33) % 1089) / 33) * 528 + (((i / 12) % 132) / 11) * 44 + (i % 44))];
    }
}