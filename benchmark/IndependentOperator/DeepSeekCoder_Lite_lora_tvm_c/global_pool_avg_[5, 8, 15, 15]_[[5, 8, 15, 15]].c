void default_function_kernel(float* adaptive_pool_avg, float* data) {
    #pragma omp parallel for
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 8; ++j) {
            int idx = i * 8 * 15 * 15 + j * 15 * 15;
            float sum = 0.0;
            for (int k = 0; k < 15; ++k) {
                for (int l = 0; l < 15; ++l) {
                    sum += data[idx + k * 15 + l];
                }
            }
            adaptive_pool_avg[i * 8 * 15 * 15 + j * 15 * 15] = sum * 0.00444444f;
        }
    }
}