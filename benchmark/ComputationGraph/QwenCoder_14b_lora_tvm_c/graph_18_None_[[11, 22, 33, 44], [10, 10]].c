void default_function_kernel(float* T_cast, float* ph, float* ph_1) {
    // Kernel 8: Copy elements from ph to T_cast
    #pragma omp parallel for
    for (int i = 0; i < 10; ++i) {
        T_cast[i] = ph[i];
    }

    // Kernel 9: Element-wise multiplication and assignment
    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        T_cast[i] = T_cast[i] * T_cast[i];
    }

    // Kernel 10: Reduction sum
    float T_multiply_red[10];
    #pragma omp parallel for collapse(2) reduction(+:T_multiply_red[:10])
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            T_multiply_red[i] += T_cast[(i * 900) + (j * 90) + (i % 9)];
        }
    }

    // Kernel 12: Copy elements from T_strided_slice to T_cast
    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        T_cast[i] = T_cast[i];
    }

    // Kernel 2: Conditional assignment
    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        T_cast[i] = (1125 <= i) ? T_cast[i - 9000] : T_cast[i];
    }

    // Kernel 6: Division
    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        T_cast[i] = T_cast[i] / T_cast[i / 9];
    }

    // Kernel 1: Indexing and assignment
    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        T_cast[i] = ph[i + 16973];
    }

    // Kernel 7: Indexing and assignment
    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        T_cast[i] = T_cast[i];
    }

    // Kernel 5: Summation
    #pragma omp parallel for
    for (int i = 0; i < 125; ++i) {
        T_cast[i] = 0.0f;
        for (int j = 0; j < 9; ++j) {
            T_cast[i] += T_cast[(i * 9216) + (j * 9)];
        }
    }

    // Kernel: Indexing and assignment
    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        T_cast[i] = ph[i + 50414];
    }

    // Kernel 11: Complex computation
    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        T_cast[i] = (T_cast[i] * T_cast[i / 9]) * (1.0f / sqrtf((T_multiply_red[i / 9] * 0.01f) + 1e-5f));
    }

    // Kernel 3: Maximum reduction
    #pragma omp parallel for
    for (int i = 0; i < 125; ++i) {
        T_cast[i] = -3.402823e+38f;
        for (int j = 0; j < 9; ++j) {
            T_cast[i] = fmaxf(T_cast[i], T_cast[(i * 9216) + (j * 9)]);
        }
    }

    // Kernel 4: Exponential computation
    #pragma omp parallel for
    for (int i = 0; i < 1125; ++i) {
        T_cast[i] = expf(T_cast[i] - T_cast[i / 9]);
    }
}