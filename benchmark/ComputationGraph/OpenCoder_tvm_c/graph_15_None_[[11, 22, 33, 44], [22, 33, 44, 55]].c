void default_function_kernel(float* compute, float* ph, float* ph_1) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 22; j++) {
            compute[i * 22 + j] = ph[((((i * 128 + j / 125) * 31944 + (i * 6 + j % 250 / 25) * 1452 + (i * 12 + j % 50 / 5) * 44 + (i * 4 + j % 10)) + 16973)];
        }
    }
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 22; j++) {
            int v_ = (int)(floorf(((max(min(compute[i * 22 + j], 88.37f), -88.37f) * 1.442695f) + 0.5f)) + 1.27e+02f) << 23;
            compute[i * 22 + j] = max(((*(float *)(&(v_))) * (((((((((1.987569e-04f * (max(min(compute[i * 22 + j], 88.37f), -88.37f) - floorf(((max(min(compute[i * 22 + j], 88.37f), -88.37f) * 1.442695f) + 0.5f)) * 0.6931472f)) + 1.398200e-03f) * (max(min(compute[i * 22 + j], 88.37f), -88.37f) - floorf(((max(min(compute[i * 22 + j], 88.37f), -88.37f) * 1.442695f) + 0.5f)) * 0.6931472f)) + 8.333452e-03f) * (max(min(compute[i * 22 + j], 88.37f), -88.37f) - floorf(((max(min(compute[i * 22 + j], 88.37f), -88.37f) * 1.442695f) + 0.5f)) * 0.6931472f)) + 4.166580e-02f) * (max(min(compute[i * 22 + j], 88.37f), -88.37f) - floorf(((max(min(compute[i * 22 + j], 88.37f), -88.37f) * 1.442695f) + 0.5f)) * 0.6931472f)) + 0.16666666f) * (max(min(compute[i * 22 + j], 88.37f), -88.37f) - floorf(((max(min(compute[i * 22 + j], 88.37f), -88.37f) * 1.442695f) + 0.5f)) * 0.6931472f)) + 0.5f) * (max(min(compute[i * 22 + j], 88.37f), -88.37f) - floorf(((max(min(compute[i * 22 + j], 88.37f), -88.37f) * 1.442695f) + 0.5f)) * 0.6931472f)) * (max(min(compute[i * 22 + j], 88.37f), -88.37f) - floorf(((max(min(compute[i * 22 + j], 88.37f), -88.37f) * 1.442695f) + 0.5f)) * 0.6931472f)) + (max(min(compute[i * 22 + j], 88.37f), -88.37f) - floorf(((max(min(compute[i * 22 + j], 88.37f), -88.37f) * 1.442695f) + 0.5f)) * 0.6931472f)) + 1.0f));
        }
    }
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 22; j++) {
            compute[i * 22 + j] = ph[((((i * 128 + j / 125) * 79860 + (i * 6 + j % 250 / 25) * 2420 + (i * 12 + j % 50 / 5) * 55 + (i * 4 + j % 10)) + 933559)];
        }
    }
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 22; j++) {
            compute[i * 22 + j] = compute[i * 22 + j] * ph_1[i * 22 + j];
        }
    }
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 22; j++) {
            compute[i * 22 + j] = expf(compute[i * 22 + j]);
        }
    }
}