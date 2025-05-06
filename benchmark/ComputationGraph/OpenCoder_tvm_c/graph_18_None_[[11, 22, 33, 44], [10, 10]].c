void default_function_kernel(float* T_cast, float* ph, float* ph_1) {
    // Kernel 1
    for (int i = 0; i < 1125; ++i) {
        T_cast[i] = ph[i];
    }

    // Kernel 2
    for (int i = 0; i < 1125; ++i) {
        T_cast[i] = (i < 1125) ? T_cast[i] : ph_1[i];
    }

    // Kernel 3
    for (int i = 0; i < 125; ++i) {
        T_cast[i] = -FLT_MAX;
    }
    for (int i = 0; i < 125; ++i) {
        for (int k = 0; k < 9; ++k) {
            T_cast[i] = max(T_cast[i], T_cast[i * 9 + k]);
        }
    }

    // Kernel 4
    for (int i = 0; i < 1125; ++i) {
        T_cast[i] = exp(T_cast[i] - T_cast[i / 9]);
    }

    // Kernel 5
    for (int i = 0; i < 125; ++i) {
        T_cast[i] = 0.0f;
    }
    for (int i = 0; i < 125; ++i) {
        for (int k = 0; k < 9; ++k) {
            T_cast[i] += T_cast[i * 9 + k];
        }
    }

    // Kernel 6
    for (int i = 0; i < 1125; ++i) {
        T_cast[i] /= T_cast[i / 9];
    }

    // Kernel 7
    for (int i = 0; i < 1125; ++i) {
        T_cast[i] = T_cast[i / 9];
    }

    // Kernel 8
    for (int i = 0; i < 1125; ++i) {
        T_cast[i] = ph[i];
    }

    // Kernel 9
    for (int i = 0; i < 1125; ++i) {
        T_cast[i] = 0.0f;
    }
    for (int i = 0; i < 1125; ++i) {
        for (int k1 = 0; k1 < 10; ++k1) {
            for (int k2 = 0; k2 < 10; ++k2) {
                T_cast[i] += T_cast[i / 9] * T_cast[i / 9];
            }
        }
    }

    // Kernel 10
    for (int i = 0; i < 125; ++i) {
        T_cast[i] = 0.0f;
    }
    for (int i = 0; i < 125; ++i) {
        for (int k1 = 0; k1 < 10; ++k1) {
            for (int k2 = 0; k2 < 10; ++k2) {
                T_cast[i] += T_cast[i / 9] * T_cast[i / 9];
            }
        }
    }

    // Kernel 11
    for (int i = 0; i < 1125; ++i) {
        T_cast[i] = T_cast[i] * T_cast[i] * (1.0f / sqrt(T_cast[i] * 0.01f + 0.00001f));
    }

    // Kernel 12
    for (int i = 0; i < 1125; ++i) {
        T_cast[i] = ph[i];
    }
}