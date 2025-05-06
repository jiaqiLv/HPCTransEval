void default_function_kernel(float* compute, float* data) {
    int numBlocks = 17 * 12 * 7 * 9; // Assuming the input shapes are correct
    int numThreads = 18;

    #pragma omp parallel for
    for (int i = 0; i < numBlocks; ++i) {
        for (int j = 0; j < numThreads; ++j) {
            int index = i * numThreads + j;
            compute[index] = atanf(data[index]);
        }
    }
}