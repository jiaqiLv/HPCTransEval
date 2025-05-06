void default_function_kernel(float* T_softmax_norm, float* ph, float* ph_1) {
    const int num_elements = 3105 * 1024;
    const int num_threads = 1024;

    // Step 1: Copy and transform data from ph to T_transpose
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_norm[i] = ph[((((((i / 1024) * 12) + (i % 1024)) % 23) * 540) + (((i / 1024) % 1035) / 23) * 12) + (i / 1024) / 1035];
    }

    // Step 2: Normalize T_transpose by ph
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_norm[i] /= ph[i];
    }

    // Step 3: Compute the maximum element in each row of T_transpose
    float T_softmax_maxelem[540];
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 540; ++i) {
        T_softmax_maxelem[i] = 0.0f;
        for (int k = 0; k < 23; ++k) {
            T_softmax_maxelem[i] += T_softmax_norm[(i * 23) + k];
        }
    }

    // Step 4: Subtract the maximum element from each row of T_transpose
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_norm[i] -= T_softmax_maxelem[i / 23];
    }

    // Step 5: Apply the exponential function to each element of T_transpose
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        float x = fmax(fmin(T_softmax_norm[i], 8.837627e+01f), -8.837626e+01f);
        float y = x * 1.442695e+00f + 5.000000e-01f;
        int v = (int)(floorf(y) + 1.270000e+02f) << 23;
        float exp_value = (*(float*)&v) * (
            1.987569e-04f * (x - floorf(y) * 6.931472e-01f) +
            1.398200e-03f * (x - floorf(y) * 6.931472e-01f) +
            8.333452e-03f * (x - floorf(y) * 6.931472e-01f) +
            4.166580e-02f * (x - floorf(y) * 6.931472e-01f) +
            1.666667e-01f * (x - floorf(y) * 6.931472e-01f) +
            5.000000e-01f * (x - floorf(y) * 6.931472e-01f) +
            (x - floorf(y) * 6.931472e-01f)
        ) + (x - floorf(y) * 6.931472e-01f) + 1.000000e+00f;
        T_softmax_norm[i] = fmax(exp_value, T_softmax_norm[i]);
    }

    // Step 6: Compute the maximum element in each row of T_transpose again
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 540; ++i) {
        T_softmax_maxelem[i] = -3.402823e+38f;
        for (int k = 0; k < 23; ++k) {
            T_softmax_maxelem[i] = fmax(T_softmax_maxelem[i], T_softmax_norm[(i * 23) + k]);
        }
    }

    // Step 7: Normalize T_transpose by the maximum element
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_norm[i] /= T_softmax_maxelem[i / 23];
    }
}