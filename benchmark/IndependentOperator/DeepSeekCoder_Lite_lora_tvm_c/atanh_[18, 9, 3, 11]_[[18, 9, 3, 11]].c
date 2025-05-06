void default_function_kernel(float* compute, float* data) {
    int numBlocks = 18; // Assuming numBlocks is derived from the input shape
    int threadsPerBlock = 33; // Assuming threadsPerBlock is derived from the input shape

    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        compute[i] = atanhf(data[i]);
    }
}