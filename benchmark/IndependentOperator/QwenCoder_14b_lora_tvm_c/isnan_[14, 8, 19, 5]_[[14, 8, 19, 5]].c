void default_function_kernel(int8_t* compute, float* data) {
    #pragma omp parallel for collapse(4)
    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 8; ++j) {
            for (int k = 0; k < 19; ++k) {
                for (int l = 0; l < 5; ++l) {
                    int index = (i * 8 * 19 * 5) + (j * 19 * 5) + (k * 5) + l;
                    compute[index] = (int8_t)(data[index] != data[index]);
                }
            }
        }
    }
}