void default_function_kernel(float* T_fast_exp, float* data, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        float x = fmin(fmax(data[i], 8.837627e+01f), -8.837626e+01f);
        float y = x * 1.442695e+00f + 5.000000e-01f;
        int v_ = ((int)(floorf(y) + 1.270000e+02f)) << 23;
        float z = y - floorf(y);
        float exp_poly = 1.987569e-04f * z +
                         1.398200e-03f * z * z +
                         8.333452e-03f * z * z * z +
                         4.166580e-02f * z * z * z * z +
                         1.666667e-01f * z * z * z * z * z +
                         5.000000e-01f * z * z * z * z * z * z +
                         z * z * z * z * z * z * z;
        T_fast_exp[i] = fmax((*(float *)&v_) * exp_poly, data[i]);
    }
}