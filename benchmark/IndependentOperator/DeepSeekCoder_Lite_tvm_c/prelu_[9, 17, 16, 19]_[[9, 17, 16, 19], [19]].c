void default_function_kernel(float* Scale, float* compute, float* data) {
    int numBlocks = 9; // Assuming numBlocks is derived from the input shape
    int threadsPerBlock = 19; // Assuming threadsPerBlock is derived from the input shape

    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        int idx = i;
        if (idx < numBlocks * threadsPerBlock) {
            compute[idx] = (0.000000e+00f < data[idx]) ? data[idx] : (data[idx] * Scale[idx % 19]);
        }
    }
}