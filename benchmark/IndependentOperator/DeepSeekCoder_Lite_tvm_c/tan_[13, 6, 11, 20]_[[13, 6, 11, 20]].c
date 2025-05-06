void default_function_kernel(float* compute, float* data) {
    int numBlocks = 13 * 6 * 11; // Assuming the shape is [13, 6, 11, 20]
    int threadsPerBlock = 20; // Each block has 20 threads based on the CUDA kernel code

    #pragma omp parallel for
    for (int i = 0; i < numBlocks; ++i) {
        for (int j = 0; j < threadsPerBlock; ++j) {
            int index = i * threadsPerBlock + j;
            compute[index] = tanf(data[index]);
        }
    }
}