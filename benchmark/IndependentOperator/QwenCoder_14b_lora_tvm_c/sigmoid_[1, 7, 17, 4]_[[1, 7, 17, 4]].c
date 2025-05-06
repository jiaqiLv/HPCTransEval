void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 7; ++j) {
            int index = (i * 7 + j) * 17 * 4;
            for (int k = 0; k < 17; ++k) {
                for (int l = 0; l < 4; ++l) {
                    compute[index + k * 4 + l] = 1.0f / (1.0f + expf(-data[index + k * 4 + l]));
                }
            }
        }
    }
}