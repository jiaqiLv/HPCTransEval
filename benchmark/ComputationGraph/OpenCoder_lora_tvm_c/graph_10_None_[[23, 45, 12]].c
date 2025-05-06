void default_function_kernel(float* T_transpose, float* ph) {
    int i;
    #pragma omp parallel for
    for (i = 0; i < 1035; i++) {
        T_transpose[i] = ph[(i / 3) * 12 + (i % 12)];
    }
    #pragma omp parallel for
    for (i = 0; i < 1035; i++) {
        T_transpose[i] = T_transpose[i] * T_transpose[i] * T_transpose[i] * T_transpose[i] * T_transpose[i] * T_transpose[i] * T_transpose[i] * T_transpose[i] * T_transpose[i] * T_transpose[i] * T_transpose[i] * T_transpose[i];
    }
    #pragma omp parallel for
    for (i = 0; i < 1035; i++) {
        T_transpose[i] = T_transpose[i] * 2.760768e-16f + 2.000188e-13f;
    }
    #pragma omp parallel for
    for (i = 0; i < 1035; i++) {
        T_transpose[i] = T_transpose[i] + 2.000188e-13f;
    }
    #pragma omp parallel for
    for (i = 0; i < 1035; i++) {
        T_transpose[i] = T_transpose[i] + 5.122297e-08f;
    }
    #pragma omp parallel for
    for (i = 0; i < 1035; i++) {
        T_transpose[i] = T_transpose[i] + 1.485722e-05f;
    }
    #pragma omp parallel for
    for (i = 0; i < 1035; i++) {
        T_transpose[i] = T_transpose[i] + 6.372619e-04f;
    }
    #pragma omp parallel for
    for (i = 0; i < 1035; i++) {
        T_transpose[i] = T_transpose[i] + 4.893525e-03f;
    }
    #pragma omp parallel for
    for (i = 0; i < 1035; i++) {
        T_transpose[i] = T_transpose[i] / (T_transpose[i] * T_transpose[i] * T_transpose[i] * 1.198258e-06f + 1.185347e-04f);
    }
    #pragma omp parallel for
    for (i = 0; i < 1035; i++) {
        T_transpose[i] = fminf(9.0f, T_transpose[i]);
    }
    #pragma omp parallel for
    for (i = 0; i < 1035; i++) {
        T_transpose[i] = fmaxf(-9.0f, T_transpose[i]);
    }
}