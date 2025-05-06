void default_function_kernel(float* T_transpose, float* ph) {
    const int num_threads = 765;
    const int size = 123; // Assuming size based on threadIdx.x usage

    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < size; ++i) {
        float v_ = ((int)(floorf(((fmax(fmin(T_transpose[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f)) << 23;
        T_transpose[i] = fmax(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (fmax(fmin(T_transpose[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmax(fmin(T_transpose[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (fmax(fmin(T_transpose[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmax(fmin(T_transpose[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (fmax(fmin(T_transpose[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmax(fmin(T_transpose[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (fmax(fmin(T_transpose[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmax(fmin(T_transpose[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (fmax(fmin(T_transpose[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmax(fmin(T_transpose[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (fmax(fmin(T_transpose[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmax(fmin(T_transpose[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (fmax(fmin(T_transpose[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmax(fmin(T_transpose[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (fmax(fmin(T_transpose[i], 8.837627e+01f), -8.837626e+01f) - (floorf(((fmax(fmin(T_transpose[i], 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f)), T_transpose[i]);
    }

    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < size; ++i) {
        T_transpose[i] = T_transpose[((((i % 17) * 45) + (i / 17))];
    }

    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < size; ++i) {
        T_transpose[i] = T_transpose[(((((((i / 45) * 45) + (i % 9)) + 36) - (((i % 45) / 9) * 9))];
    }

    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < size; ++i) {
        T_transpose[i] = ph[((((((i / 9) * 12) + (i % 9)) + 61)];
    }
}