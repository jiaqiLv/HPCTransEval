void default_function_kernel(float* T_softmax_norm, float* data) {
    const int num_elements = 189 * 32;
    const int num_threads = 32;

    // Initialize T_softmax_maxelem
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_maxelem[i] = -3.402823e+38f;
    }

    // Find the maximum element for each block
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        int blockIdx = i / 32;
        int threadIdx = i % 32;
        if (((blockIdx * 2) + (threadIdx >> 4)) < 189) {
            for (int k = 0; k < 3; ++k) {
                T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], data[(blockIdx * 96) + (threadIdx * 3) + k]);
            }
        }
    }

    // Calculate T_softmax_expsum
    const int num_expsum_elements = 567;
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_expsum_elements; ++i) {
        T_softmax_expsum[i] = 0.0f;
        for (int k = 0; k < 3; ++k) {
            int v_ = ((int)(floorf(((fmaxf(fminf(data[(i * 3) + k] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
            T_softmax_expsum[i] += fmaxf(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (fmaxf(fminf(data[(i * 3) + k] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(data[(i * 3) + k] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (fmaxf(fminf(data[(i * 3) + k] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(data[(i * 3) + k] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (fmaxf(fminf(data[(i * 3) + k] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(data[(i * 3) + k] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (fmaxf(fminf(data[(i * 3) + k] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(data[(i * 3) + k] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (fmaxf(fminf(data[(i * 3) + k] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(data[(i * 3) + k] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (fmaxf(fminf(data[(i * 3) + k] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(data[(i * 3) + k] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (fmaxf(fminf(data[(i * 3) + k] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(data[(i * 3) + k] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (fmaxf(fminf(data[(i * 3) + k] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(data[(i * 3) + k] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), (data[(i * 3) + k] - T_softmax_maxelem[i / 3])));
        }
    }

    // Normalize the softmax values
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        int blockIdx = i / 32;
        int threadIdx = i % 32;
        if (((blockIdx * 2) + (threadIdx >> 4)) < 189) {
            int v_ = ((int)(floorf(((fmaxf(fminf(data[i] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
            T_softmax_norm[i] = fmaxf(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (fmaxf(fminf(data[i] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(data[i] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (fmaxf(fminf(data[i] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(data[i] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (fmaxf(fminf(data[i] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(data[i] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (fmaxf(fminf(data[i] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(data[i] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (fmaxf(fminf(data[i] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(data[i] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (fmaxf(fminf(data[i] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(data[i] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (fmaxf(fminf(data[i] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(data[i] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (fmaxf(fminf(data[i] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmaxf(fminf(data[i] - T_softmax_maxelem[i / 3], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), (data[i] - T_softmax_maxelem[i / 3])) / T_softmax_expsum[i / 3];
        }
    }
}