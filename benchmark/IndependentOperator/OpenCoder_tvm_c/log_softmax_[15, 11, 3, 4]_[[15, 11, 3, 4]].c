void default_function_kernel(float* compute, float* data) {
    int num_threads = omp_get_max_threads();
    omp_set_num_threads(num_threads);

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 11; ++j) {
            float max_val = -FLT_MAX;
            for (int k = 0; k < 4; ++k) {
                max_val = max(max_val, data[i * 32 + j * 4 + k]);
            }
            compute[i * 32 + j * 4] = max_val;
        }
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 11; ++j) {
            float sum_exp = 0.0f;
            for (int k = 0; k < 4; ++k) {
                sum_exp += exp(data[i * 32 + j * 4 + k] - compute[i * 32 + j * 4]);
            }
            for (int k = 0; k < 4; ++k) {
                compute[i * 32 + j * 4 + k] = exp(data[i * 32 + j * 4 + k] - compute[i * 32 + j * 4]) / sum_exp;
            }
        }
    }
}