void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for collapse(2)
    for (int j = 0; j < 17; j++) {
        compute[i * 17 + j] = {
            for (int j = 0; j < 17; j++) {
                compute[i * 17 + j] = {
                    compute[i * 17 + j] = {
                        compute[i * 17 + j] = acosf data[i * 17 + j]);
                    }
                }
            }