void default_function_kernel(float* T_fast_erf, float* ph, float* ph_1) {
    #pragma omp parallel for
    for (int i = 0; i < 640; ++i) {
        T_fast_erf[i] = 0.0f;
        if (T_fast_erf[i] < 0.0f) {
            T_fast_erf[i] *= ph[(i % 160) / 5];
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 640; ++i) {
        float x = T_fast_erf[i];
        x = fminf(fmaxf(x, -4.0f), 4.0f);
        float p = 0.2316419;
        float t = 1.0f / (1.0f + p * x);
        float y = 1.0f - 1.0f / sqrtf(1.0f + p * x) * (1.0f + p * t * (1.0f + p * t * (1.0f + p * t * (1.0f + p * t))));
        T_fast_erf[i] = x >= 0.0f ? y : -y;
    }

    #pragma omp parallel for
    for (int i = 0; i < 640; ++i) {
        T_fast_erf[i] = ph_1[((((i % 160) / 5) * 12) + (i % 5)) + 14];
    }
}