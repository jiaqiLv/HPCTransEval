void default_function_kernel(float* T_transpose, float* ph) {
    int num_threads = omp_get_max_threads();
    #pragma omp parallel for
    for (int i = 0; i < 17 * 5 * 23; i++) {
        int idx = i;
        int z = idx / (5 * 23);
        idx = idx % (5 * 23);
        int y = idx / 23;
        int x = idx % 23;

        float value = ph[(z * 12 * 9 + y * 9 + x) + 61];
        value = max(min(value, 8.837627e+01f), -8.837626e+01f);
        value = floorf(value * 1.442695e+00f + 5.000000e-01f);
        value = 1.987569e-04f * value + 1.398200e-03f;
        value = value * 6.931472e-01f + 8.333452e-03f;
        value = value * 6.931472e-01f + 4.166580e-02f;
        value = value * 6.931472e-01f + 1.666667e-01f;
        value = value * 6.931472e-01f + 5.000000e-01f;
        value = value * 6.931472e-01f + 1.000000e+00f;
        value = max(value, T_transpose[i]);
        T_transpose[i] = value;
    }
}