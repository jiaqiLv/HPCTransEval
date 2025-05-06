void default_function_kernel(float* data, float* pool_max) {
    const float INITIAL_VALUE = -3.402823e+38f;
    #pragma omp parallel for
    for (int idx = 0; idx < 66; ++idx) {
        pool_max[idx] = INITIAL_VALUE;
    }

    #pragma omp parallel for
    for (int b = 0; b < 11; ++b) {
        for (int t = 0; t < 6; ++t) {
            int idx = b * 6 + t;
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int data_idx = ((b % 9) * 2 + i) * 12 + (t * 2 + j) * 2 - 13;
                    if (1 <= (b % 9) * 2 + i && 1 <= t * 2 + j) {
                        pool_max[idx] = fmaxf(pool_max[idx], data[data_idx]);
                    } else {
                        pool_max[idx] = fmaxf(pool_max[idx], INITIAL_VALUE);
                    }
                }
            }
        }
    }
}