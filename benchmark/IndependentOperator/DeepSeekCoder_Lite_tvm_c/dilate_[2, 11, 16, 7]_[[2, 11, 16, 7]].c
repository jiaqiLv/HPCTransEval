void default_function_kernel(float* DilatedInput, float* data) {
    int numBlocks = 2 * 11 * 16 * 7; // Assuming the same shape for input and output
    int threadsPerBlock = 44;

    #pragma omp parallel for
    for (int i = 0; i < numBlocks; i++) {
        DilatedInput[i] = data[i];
    }
}