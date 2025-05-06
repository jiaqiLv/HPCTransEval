void default_function_kernel(float* compute, float* data) {
    int num_blocks = 4 * 4 * 15 * 19; // Total number of elements
    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        compute[i] = asinhf(data[i]);
    }
}