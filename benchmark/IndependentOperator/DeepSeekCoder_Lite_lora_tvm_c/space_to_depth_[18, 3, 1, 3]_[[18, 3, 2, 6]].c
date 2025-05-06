void default_function_kernel(float* data, float* space_to_depth) {
    int blockSize = 8;
    int numBlocks = 18;
    int numThreads = blockSize * numBlocks;

    #pragma omp parallel for
    for (int i = 0; i < numThreads; i++) {
        int blockIndex = i / blockSize;
        int threadIndex = i % blockSize;
        int dataIndex = (((((blockIndex * 2) + (threadIndex >> 2)) / 9) * 36) + (((((((blockIndex * 8) + threadIndex) % 36) / 3) % 3) * 12)) + (((((((blockIndex * 8) + threadIndex) % 36) / 3) / 6) * 6)) + (((((blockIndex * 8) + threadIndex) % 36) / 3) % 6) / 3) * 2) + (((((((blockIndex * 8) + threadIndex) % 36) / 3) % 6) / 3) + (((((blockIndex * 8) + threadIndex) % 36) / 3) % 6) % 3);
        space_to_depth[i] = data[dataIndex];
    }
}