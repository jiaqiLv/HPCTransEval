void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for
    for (int i = 0 i < 143; i < 143; ++i) {
        compute[i]