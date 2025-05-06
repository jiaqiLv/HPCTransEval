void default_function_kernel(float* T_softmax_norm, float* ph, float* ph_1) {
    int i, j, k;
    float T_transpose[1024];
    float T_softmax_maxelem[23];

    // Kernel 1
    for (i = 0; i < 3105; i++) {
        T_transpose[i] = ph[((((i / 1024) * 12) + (i % 12)) % 23) * 540 + (((((i / 1024) * 12) + (i % 12)) % 1035) / 23) * 12 + ((i / 1024) * 12 + (i % 12)) / 1035)];
    }

    // Kernel 2
    for (i = 0; i < 23; i++) {
        T_softmax_maxelem[i] = 0.0f;
        for (j = 0; j < 23; j++) {
            T_softmax_maxelem[i] += T_transpose[((i * 23) + j)];
        }
    }

    // Kernel 3
    for (i = 0; i < 3105; i++) {
        T_transpose[i] -= T_softmax_maxelem[(i / 23)];
    }

    // Kernel 4
    for (i = 0; i < 3105; i++) {
        int v_ = (int)(floorf(((max(min(T_transpose[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f) << 23;
        T_transpose[i] = max(((*(float *)(&(v_))) * (((((((((1.987569e-04f * (max(min(T_transpose[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_transpose[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (max(min(T_transpose[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_transpose[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (max(min(T_transpose[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_transpose[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (max(min(T_transpose[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_transpose[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (max(min(T_transpose[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_transpose[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (max(min(T_transpose[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_transpose[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (max(min(T_transpose[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((max(min(T_transpose[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f));
    }

    // Kernel 5
    for (i = 0; i < 23; i++) {
        T_softmax_maxelem[i] = -3.402823e+38f;
        for (j = 0; j < 23; j++) {
            T_softmax_maxelem[i] = max(T_softmax_maxelem[i], T_transpose[((i * 23) + j)]);
        }
    }

    // Kernel 6
    for (i = 0; i < 3105; i++) {
        T_softmax_norm[i] = T_transpose[i] / T_softmax_maxelem[(i / 23)];
    }
}