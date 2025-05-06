void default_function_kernel(float* data, float* pool_max) {
    // Initialize pool_max with a very small number
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 64; ++j) {
            pool_max[i * 64 + j] = -FLT_MAX;
        }
    }

    // Perform the max pooling operation
    #pragma omp parallel for collapse(3)
    for (int k = 0; k < 3; ++k) {
        for (int l = 0; l < 3; ++l) {
            for (int m = 0; m < 3; ++m) {
                #pragma omp parallel for collapse(2)
                for (int n = 0; n < 64; ++n) {
                    int x = n / 8;
                    int y = n % 8;
                    int z = n % 2;
                    int w = n % 4;
                    int u = n % 8;
                    int v = n % 16;
                    int t = n % 32;
                    int s = n % 64;
                    if (1 <= x && x < 4 && 1 <= y && y < 4 && 1 <= z && z < 4 && 1 <= w && w < 4 && 1 <= u && u < 8 && 1 <= v && v < 16 && 1 <= t && t < 32 && 1 <= s && s < 64) {
                        pool_max[n] = fmaxf(pool_max[n], data[(k * 896 + l * 512 + m * 128 + (y * 32 + u * 2 + z) + (t * 2 + w)) - 145]);
                    }
                }
            }
        }
    }
}