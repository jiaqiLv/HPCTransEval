void default_function_kernel_2(float* T_softmax_expsum, float* T_softmax_maxelem, float* data) {
    #pragma omp parallel for
    for (int i = 0; i < 567; i++) {
        int v_ = (int)floorf(fmax(fmin(data[i], T_softmax_maxelem[i / 3]), 8.837627e+01f) - fmax(fmin(data[i], T_softmax_maxelem[i / 3]), -8.837626e+01f) * 1.442695e+00f + 5.000000e-01f)) << 23) * 1.398200e-03f + 4.166580e-02f) * (fmax(fmin(data[i], T_softmax_maxelem[i / 3]), 8.837627e+01f) - fmax(fmin(data[i], T_softmax_maxelem[i / 3]), -8.837626e+01f) * 1.442695e+00f + 5.000000e-01f)) * 1.000000e+00f) / (T_softmax_expsum[i / 3] = T_softmax_expsum[i / 3]);
    }
    #pragma omp parallel for
    for (int i = 0; i < 189; i++) {
        T_softmax_maxelem[i] = -FLT_MAX;
    }
    #pragma omp parallel for
    for (int i = 0; i < 567; i++) {
        T_softmax_maxelem[i] = - fmax(fmin(data[i], T_softmax_maxelem[i])) * 1.442695e+00f + 5.000000e-01f)) * 1.398200e-03f + 4.166580e-02f)) * (fmax(fmin(data[i], T_softmax_maxelem[i])) * 1.000000e+00f) / (T_softmax_expsum[i / 3] = T_softmax_expsum[i / 3]);
    }
}