void default_function_kernel(int8_t* compute, float* data) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 14; ++i) {
        for (int j = 0; j < 8; ++j) {
            int base_index = (i * 8 + j) * 19 * 5;
            for (int k = 0; k < 19; ++k) {
                for (int l = 0; l < 5; ++l) {
                    int index = base_index + k * 5 + l;
                    compute[index] = (int8_t)(data[index] != data[index]);
                }
            }
        }
    }
}