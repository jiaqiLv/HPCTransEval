void default_function_kernel(float* T_fast_exp, float* ph) {
    const int size = 3795;
    const int size2 = 1265;
    const int size3 = 12;

    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        T_reverse_sequence[i] = ph[((((((((i / 256) * 4) + (i % 256)) / 15) * 60) + ((i % 256) % 12)) + 48) - (((((i % 256) / 4) + (i / 256)) % 15) / 3) * 12)];
    }

    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        T_expand_dims[i] = T_reverse_sequence[((((i / 256) * 60) + (i % 256)) % 60)];
    }

    #pragma omp parallel for
    for (int i = 0; i < size2; i++) {
        T_expand_dims[i] = -3.402823e+38f;
        for (int k = 0; k < size3; k++) {
            T_expand_dims[i] = max(T_expand_dims[i], T_reverse_sequence[((i * 12) + k)]);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < size2; i++) {
        compute[i] = 0.000000e+00f;
        for (int k = 0; k < size3; k++) {
            compute[i] += expf(T_reverse_sequence[((i * 12) + k)] - T_expand_dims[i]);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        T_reverse_sequence[i] = T_expand_dims[(i / 3)];
        T_reverse_sequence[i] -= logf(compute[(i / 3)]);
        T_reverse_sequence[i] -= T_reverse_sequence[i];
    }

    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        int v_ = ((int)(floorf(((max(min(T_reverse_sequence[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
        T_fast_exp[i] = max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min(T_reverse_sequence[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reverse_sequence[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(T_reverse_sequence[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reverse_sequence[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(T_reverse_sequence[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reverse_sequence[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(T_reverse_sequence[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reverse_sequence[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(T_reverse_sequence[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reverse_sequence[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (max(min(T_reverse_sequence[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reverse_sequence[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (max(min(T_reverse_sequence[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reverse_sequence[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(T_reverse_sequence[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_reverse_sequence[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), T_reverse_sequence[i]);
    }
}