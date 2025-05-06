void default_function_kernel(float* T_softmax_norm, float* ph, float* ph_1) {
    const int num_elements = 3105 * 1024;
    const int num_threads = 1024;

    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_norm[i] = ph[i];
    }

    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_norm[i] /= ph_1[i];
    }

    float T_softmax_maxelem[540];
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 540; ++i) {
        T_softmax_maxelem[i] = 0.0f;
        for (int k = 0; k < 23; ++k) {
            T_softmax_maxelem[i] += T_softmax_norm[i * 23 + k];
        }
    }

    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_norm[i] -= T_softmax_maxelem[i / 23];
    }

    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        float x = T_softmax_norm[i];
        if (x > 8.837627e+01f) {
            x = 8.837627e+01f;
        } else if (x < -8.837626e+01f) {
            x = -8.837626e+01f;
        }
        int v_ = (int)(floorf(x * 1.442695e+00f + 5.000000e-01f) + 1.270000e+02f) << 23;
        float exp_x = (*(float *)&v_) * (
            1.987569e-04f * (x - floorf(x * 1.442695e+00f + 5.000000e-01f) * 6.931472e-01f) +
            1.398200e-03f * (x - floorf(x * 1.442695e+00f + 5.000000e-01f) * 6.931472e-01f) +
            8.333452e-03f * (x - floorf(x * 1.442695e+00f + 5.000000e-01f) * 6.931472e-01f) +
            4.166580e-02f * (x - floorf(x * 1.442695e+00f + 5.000000e-01f) * 6.931472e-01f) +
            1.666667e-01f * (x - floorf(x * 1.442695e+00f + 5.000000e-01f) * 6.931472e-01f) +
            5.000000e-01f * (x - floorf(x * 1.442695e+00f + 5.000000e-01f) * 6.931472e-01f) *
            (x - floorf(x * 1.442695e+00f + 5.000000e-01f) * 6.931472e-01f) +
            (x - floorf(x * 1.442695e+00f + 5.000000e-01f) * 6.931472e-01f) + 1.000000e+00f
        );
        T_softmax_norm[i] = fmaxf(exp_x, T_softmax_norm[i]);
    }

    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 540; ++i) {
        T_softmax_maxelem[i] = -3.402823e+38f;
        for (int k = 0; k < 23; ++k) {
            T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], T_softmax_norm[i * 23 + k]);
        }
    }

    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_norm[i] /= T_softmax_maxelem[i / 23];
    }
}