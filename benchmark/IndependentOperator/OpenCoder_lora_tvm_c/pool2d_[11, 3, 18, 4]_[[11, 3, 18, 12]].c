void default_function_kernel(float* data, float* pool_max) {
    // Initialize pool_max array with a very small number
    for (int i = 0; i < 11 * 3 * 6; ++i) {
        pool_max[i] = -FLT_MAX;
    }

    // Parallelize the loop using OpenMP
    #pragma omp parallel for collapse(2)
    for (int rv0 = 0; rv0 < 3; ++rv0) {
        for (int rv1 = 0; rv1 < 3; ++rv1) {
            for (int i = 0; i < 11 * 3 * 6; ++i) {
                int x = i % 6;
                int y = (i / 6) % 3;
                int z = i / (6 * 3);
                if (1 <= (z * 2 + rv0) && 1 <= (x * 2 + rv1)) {
                    float current_value = data[((z * 24 + rv0 * 12 + x * 2 + rv1) - 13)];
                    #pragma omp critical
                    {
                        pool_max[i] = fmax(pool_max[i], current_value);
                    }
                }
            }
        }
    }
}