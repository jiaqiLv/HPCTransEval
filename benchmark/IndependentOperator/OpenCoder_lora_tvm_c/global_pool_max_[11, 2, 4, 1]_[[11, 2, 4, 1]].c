void default_function_kernel(float* adaptive_pool_max, float* data) {
    #pragma omp parallel for
    for (int i = 0; i < 11; i++) {
        float max_val = -FLT_MAX;
        for (int j = 0; j < 4; j++) {
            max_val = fmax(max_val, data[i * 4 + j]);
        }
        adaptive_pool_max[i] = max_val;
    }
}