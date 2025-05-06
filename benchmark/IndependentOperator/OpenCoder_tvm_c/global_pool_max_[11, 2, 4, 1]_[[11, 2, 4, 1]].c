void default_function_kernel(float* adaptive_pool_max, float* data) {
    int i, j;
    #pragma omp parallel for private(j)
    for (i = 0; i < 11; i++) {
        adaptive_pool_max[i] = -FLT_MAX;
        for (j = 0; j < 4; j++) {
            adaptive_pool_max[i] = fmaxf(adaptive_pool_max[i], data[i * 4 + j]);
        }
    }
}