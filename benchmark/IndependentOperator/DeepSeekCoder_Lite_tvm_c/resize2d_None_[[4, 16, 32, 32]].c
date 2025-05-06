void default_function_kernel(float* A, float* resize) {
    int numBlocks = 4; // Number of blocks is given as 4
    int numThreads = 1024; // Number of threads per block is given as 1024

    #pragma omp parallel for
    for (int i = 0; i < numBlocks * numThreads; i++) {
        int blockIdx = i / numThreads;
        int threadIdx = i % numThreads;

        if (blockIdx * 1024 + threadIdx < 625 * 4) {
            int index = (blockIdx * 256 + (threadIdx >> 2)) / 625 * 1024 + (threadIdx & 0x3);
            int valueIndex = (blockIdx * 256 + (threadIdx >> 2)) / 625 * 1024 + (threadIdx & 0x3);
            int valueIndex2 = (blockIdx * 256 + (threadIdx >> 2)) / 625 * 1024 + (threadIdx & 0x3) + 1;

            float value = A[valueIndex];
            float value2 = A[valueIndex2];

            float weight = 1.0f - (valueIndex % 50 + 0.5f) * 0.64f - (int)((valueIndex % 50 + 0.5f) * 0.64f);
            float weight2 = 1.0f - (valueIndex2 % 50 + 0.5f) * 0.64f - (int)((valueIndex2 % 50 + 0.5f) * 0.64f);

            resize[blockIdx * 1024 + threadIdx] = value * (1.0f - weight) + value2 * weight2;
        }
    }
}