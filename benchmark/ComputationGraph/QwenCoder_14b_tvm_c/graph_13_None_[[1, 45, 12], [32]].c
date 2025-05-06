void default_function_kernel(float* T_fast_erf, float* ph, float* ph_1) {
    int size = 640; // Assuming the size based on the threadIdx.x usage in the CUDA kernels

    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        // Kernel 1: T_broadcast_to[i] = (0.0 < T_broadcast_to[i]) ? T_broadcast_to[i] : (T_broadcast_to[i] * ph[i % 160 / 5]);
        T_fast_erf[i] = (0.0 < T_fast_erf[i]) ? T_fast_erf[i] : (T_fast_erf[i] * ph[i % 160 / 5]);

        // Kernel 2: T_fast_erf[i] = complex erf computation
        float x = T_fast_erf[i];
        x = fminf(fmaxf(x, -4.0f), 4.0f);
        float t = x * x;
        float p = -2.726142e-10f + 2.770681e-08f * t;
        t *= t;
        p += -2.101024e-06f + -5.692506e-05f * t;
        t *= t;
        p += -7.349906e-04f + -2.954600e-03f * t;
        t *= t;
        p += -1.609603e-02f + -1.456607e-05f * t;
        t *= t;
        p += -2.133740e-04f + -1.682827e-03f * t;
        t *= t;
        p += -7.373329e-03f + -1.426474e-02f * t;
        T_fast_erf[i] = p;

        // Kernel 3: T_broadcast_to[i] = ph[(i % 160 / 5) * 12 + (i % 5) + 14];
        T_fast_erf[i] = ph[(i % 160 / 5) * 12 + (i % 5) + 14];
    }
}