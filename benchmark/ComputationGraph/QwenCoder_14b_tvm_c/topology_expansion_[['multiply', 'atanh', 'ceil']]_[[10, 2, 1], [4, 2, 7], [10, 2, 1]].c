void default_function_kernel(float* T_multiply, float* compute, float* compute_1, float* ph_0, float* ph_3) {
    int size1 = 90; // 10 blocks * 9 threads per block
    int size2 = 128; // 4 blocks * 32 threads per block

    #pragma omp parallel for
    for (int i = 0; i < size1; ++i) {
        compute[i] = atanf(ph_0[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < size2; ++i) {
        T_multiply[i] = ph_0[i] * ph_3[i];
    }

    #pragma omp parallel for
    for (int i = 0; i < size2; ++i) {
        compute_1[i] = ceilf(ph_0[i]);
    }
}