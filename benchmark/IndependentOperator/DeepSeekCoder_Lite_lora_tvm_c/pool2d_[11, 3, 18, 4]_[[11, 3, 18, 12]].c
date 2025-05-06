void default_function_kernel(float* data, float* pool_max) {
    for (int i = 0; i < 198; ++i) {
        pool_max[i] = -3.402823e+38f;
    }

    #pragma omp parallel for
    for (int b = 0; b < 11; ++b) {
        for (int t = 0; t < 6; ++t) {
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 6; ++j) {
                    int index = b * 6 + t;
                    float current_value = -3.402823e+38f;
                    for (int di = 0; di < 3; ++di) {
                        for (int dj = 0; dj < 3; ++dj) {
                            int ni = i * 2 + di;
                            int nj = j * 2 + dj;
                            if (ni >= 0 && ni < 18 && nj >= 0 && nj < 12) {
                                int data_index = (b * 24 + (di * 12 + (nj * 2 + dj))) - 13;
                                current_value = fmaxf(current_value, data[data_index]);
                            }
                        }
                    }
                    pool_max[index] = current_value;
                }
            }
        }
    }
}