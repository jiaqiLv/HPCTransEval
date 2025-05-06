void default_function_kernel(float* T_fast_exp, float* ph) {
    const int num_elements = 3795;
    const int num_threads = 1024;

    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        int idx = i * 4;
        T_fast_exp[i] = T_fast_exp[i] - T_fast_exp[idx / 3] - logf(ph[idx / 3]);
    }

    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 345; ++i) {
        int idx = i * 4;
        T_fast_exp[i] = ph[((((i / 15) * 60) + (idx % 12)) + 48) - (((i % 15) / 3) * 12)];
    }

    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        T_fast_exp[i] = T_fast_exp[i % 1380];
    }

    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 345; ++i) {
        int idx = i * 4;
        T_fast_exp[i] = T_fast_exp[((((i / 15) * 60) + (idx % 60))];
    }

    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_elements; ++i) {
        float x = fmaxf(fminf(T_fast_exp[i], 8.837627e+01f), -8.837626e+01f);
        int v = (int)(floorf(x * 1.442695e+00f + 5.000000e-01f) + 1.270000e+02f) << 23;
        float y = x - floorf(x * 1.442695e+00f + 5.000000e-01f) * 6.931472e-01f;
        T_fast_exp[i] = fmaxf((*(float *)&v) * (
            1.987569e-04f * y +
            1.398200e-03f * y * y +
            8.333452e-03f * y * y * y +
            4.166580e-02f * y * y * y * y +
            1.666667e-01f * y * y * y * y * y +
            5.000000e-01f * y * y * y * y * y * y +
            y * y * y * y * y * y * y
        ), T_fast_exp[i]);
    }

    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 1265; ++i) {
        T_fast_exp[i] = 0.000000e+00f;
        for (int k = 0; k < 12; ++k) {
            T_fast_exp[i] += expf(T_fast_exp[((i * 12288) + (i * 12)) + k] - T_fast_exp[i]);
        }
    }

    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < 1265; ++i) {
        T_fast_exp[i] = -3.402823e+38f;
        for (int k = 0; k < 12; ++k) {
            T_fast_exp[i] = fmaxf(T_fast_exp[i], T_fast_exp[((i * 12288) + (i * 12)) + k]);
        }
    }
}