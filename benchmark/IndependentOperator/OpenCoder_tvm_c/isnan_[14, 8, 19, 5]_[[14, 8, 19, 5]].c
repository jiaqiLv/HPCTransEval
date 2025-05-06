void default_function_kernel(int8_t* compute, float* data) {
    int i;
    #pragma omp parallel for
    for (i = 0; i < 665; i++) {
        compute[i] = isnan(data[i]);
    }
}