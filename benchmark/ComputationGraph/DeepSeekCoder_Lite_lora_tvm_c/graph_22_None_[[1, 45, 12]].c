void default_function_kernel(float* T_strided_slice, float* ph) {
    float T_broadcast_to[75];
    float T_transpose[25];

    // Launch the kernels
    #pragma omp parallel for
    for (int i = 0; i < 75; i++) {
        T_broadcast_to[i] = T_transpose[i / 3];
    }

    #pragma omp parallel for
    for (int i = 0; i < 75; i++) {
        T_broadcast_to[i] = floorf(T_broadcast_to[i] * 3.333333e-01f);
    }

    #pragma omp parallel for
    for (int i = 0; i < 25; i++) {
        T_strided_slice[i] = T_broadcast_to[i];
    }

    #pragma omp parallel for
    for (int i = 0; i < 75; i++) {
        T_broadcast_to[i] = fmaxf(fminf(T_broadcast_to[i], 4.000000e+00f), -4.000000e+00f);
        T_broadcast_to[i] = T_broadcast_to[i] * ((T_broadcast_to[i] * (T_broadcast_to[i] * (T_broadcast_to[i] * (T_broadcast_to[i] * (T_broadcast_to[i] * (T_broadcast_to[i] * (T_broadcast_to[i] * (T_broadcast_to[i] * -2.726142e-10f) + 2.770681e-08f)) + -2.101024e-06f) + -5.692506e-05f) + -7.349906e-04f) + -2.954600e-03f) + -1.609603e-02f)) / ((T_broadcast_to[i] * T_broadcast_to[i]) * ((T_broadcast_to[i] * (T_broadcast_to[i] * (T_broadcast_to[i] * (T_broadcast_to[i] * (T_broadcast_to[i] * (T_broadcast_to[i] * (T_broadcast_to[i] * (T_broadcast_to[i] * -1.456607e-05f) + -2.133740e-04f)) + -1.682827e-03f)) + -7.373329e-03f)) + -1.426474e-02f)));
    }
}