void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 7; ++j) {
            int index = (i * 7) + j;
            compute[index] = 1.0f / (1.0f + expf(-data[index]));
        }
    }
}