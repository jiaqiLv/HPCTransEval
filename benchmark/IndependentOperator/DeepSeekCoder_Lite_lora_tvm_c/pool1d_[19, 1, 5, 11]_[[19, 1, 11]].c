void default_function_kernel(float* data, float* pool_max) {
    #pragma omp parallel for
    for (int i = 0; i < 114; ++i) {
        pool_max[i] = -3.402823e+38f;
    }

    #pragma omp parallel for
    for (int i = 0; i < 114; ++i) {
        for (int j = 0; j < 3; ++j) {
            int index = ((i / 6) * 11) + (((i % 6) * 2) + j);
            if (index < 114) {
                pool_max[i] = fmaxf(pool_max[i], data[index - 1]);
            }
        }
    }
}