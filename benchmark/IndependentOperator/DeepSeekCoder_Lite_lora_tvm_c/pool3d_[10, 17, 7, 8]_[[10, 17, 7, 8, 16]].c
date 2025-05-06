void default_function_kernel(float* data, float* pool_max) {
    #pragma omp parallel for
    for (int i = 0; i < 128; ++i) {
        pool_max[i] = -FLT_MAX;
    }

    #pragma omp parallel for
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 17; ++j) {
            for (int k = 0; k < 4; ++k) {
                for (int l = 0; l < 8; ++l) {
                    int idx = (i * 128) + (j * 8) + (k * 2) + l;
                    for (int m = 0; m < 3; ++m) {
                        for (int n = 0; n < 3; ++n) {
                            for (int o = 0; o < 3; ++o) {
                                int x = i + m - 1;
                                int y = j + n - 1;
                                int z = k + o - 1;
                                if (x >= 0 && x < 10 && y >= 0 && y < 17 && z >= 0 && z < 8) {
                                    int idx_data = ((x * 512) + (y * 32) + (z * 2) + l) * 2;
                                    pool_max[idx] = fmaxf(pool_max[idx], data[idx_data]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}