void default_function_kernel(float* data, float* pool_max) {
    #pragma omp parallel for
    for (int idx = 0; idx < 64; ++idx) {
        pool_max[idx] = -FLT_MAX;
    }

    #pragma omp parallel for
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 17; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 4; ++l) {
                    for (int m = 0; m < 8; ++m) {
                        int idx = (i * 64) + (m * 2) + ((k << 5) | (j << 3) | (l << 1) | (m >> 2));
                        float current_value = data[(i >> 1) * 896 + ((i & 1) * 512) + ((k << 5) | (j << 3) | (l << 1) | (m >> 2)) - 145];
                        if (current_value > pool_max[(i * 64) + m]) {
                            pool_max[(i * 64) + m] = current_value;
                        }
                    }
                }
            }
        }
    }
}