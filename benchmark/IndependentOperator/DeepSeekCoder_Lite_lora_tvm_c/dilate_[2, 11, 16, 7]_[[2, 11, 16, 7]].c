void default_function_kernel(float* DilatedInput, float* data) {
    int numBlocks = 2 * 11 * 16 * 7; // Assuming the input shapes are correct and consistent
    int threadsPerBlock = 44;

    #pragma omp parallel for
    for (int i = 0; i < numBlocks; i++) {
        for (int j = 0; j < threadsPerBlock; j++) {
            DilatedInput[i * threadsPerBlock + j] = data[i * threadsPerBlock + j];
        }
    }
}