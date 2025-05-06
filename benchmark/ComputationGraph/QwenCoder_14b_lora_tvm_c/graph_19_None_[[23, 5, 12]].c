void default_function_kernel(float* compute, float* ph) {
    #pragma omp parallel for
    for (int i = 0; i < 168; ++i) {
        compute[i] = ph[((((i / 21) * 60) + ((i % 21) / 7) * 12) + (i % 7)) + 61];
    }

    #pragma omp parallel for
    for (int i = 0; i < 168; ++i) {
        compute[i] = expf(compute[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < 168; ++i) {
        float value = compute[i];
        value = fmaxf(fminf(value, 8.837627e+01f), -8.837626e+01f);
        value = value * 1.442695e+00f + 5.000000e-01f;
        int v_ = (int)(floorf(value) + 1.270000e+02f) << 23;
        float result = (*(float *)&v_) * (
            1.987569e-04f * (value - floorf(value)) +
            1.398200e-03f * (value - floorf(value)) +
            8.333452e-03f * (value - floorf(value)) +
            4.166580e-02f * (value - floorf(value)) +
            1.666667e-01f * (value - floorf(value)) +
            5.000000e-01f * (value - floorf(value)) *
            (value - floorf(value)) +
            (value - floorf(value)) + 1.000000e+00f
        );
        compute[i] = fmaxf(result, compute[i]);
    }
}