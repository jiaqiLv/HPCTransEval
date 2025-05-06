void default_function_kernel(float* data, float* pool_max) {
    // Initialize pool_max array with a very small number
    for (int i = 0; i < 64; ++i) {
        pool_max[i] = -3.402823e+38f;
    }

    // Parallelize the loop using OpenMP
    #pragma omp parallel for collapse(3)
    for (int rv0 = 0; rv0 < 3; ++rv0) {
        for (int rv1 = 0; rv1 < 3; ++rv1) {
            for (int rv2 = 0; rv2 < 3; ++rv2) {
                // Calculate the maximum value in the pooling window
                float max_val = -3.402823e+38f;
                for (int i = 0; i < 64; ++i) {
                    if (1 <= ((((((int)i) & 31) >> 3) * 2) + rv1) && (1 <= (((((int)i) & 7) * 2) + rv2))) {
                        max_val = fmax(max_val, data[((((((((((((int)i) >> 1) * 896) + ((((int)i) & 1) * 512)) + ((((int)i) >> 5) * 256)) + (rv0 * 128)) + (((((int)i) & 31) >> 3) * 32)) + (rv1 * 16)) + ((((int)i) & 7) * 2)) + rv2) - 145)]);
                    }
                }
                // Update the maximum value in pool_max
                pool_max[i] = fmax(pool_max[i], max_val);
            }
        }
    }
}