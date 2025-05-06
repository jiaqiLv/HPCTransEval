void default_function_kernel(float* compute, float* data) {
    int numBlocks = 13 * 6 * 11; // Assuming these are the correct dimensions based on the input shape
    int threadsPerBlock = 20; // Assuming this is the number of threads per block based on the input shape

    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        compute[i] = tanf(data[i]);
    }
}