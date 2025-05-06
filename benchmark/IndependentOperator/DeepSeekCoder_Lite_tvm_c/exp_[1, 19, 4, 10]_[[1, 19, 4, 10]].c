void default_function_kernel(float* compute, float* data) {
    int numBlocks = 19; // Assuming numBlocks is derived from the input shape
    int threadsPerBlock = 10; // Assuming threadsPerBlock is derived from the input shape

    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        compute[i] = expf(data[i]);
    }
}