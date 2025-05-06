void default_function_kernel(float* T_reverse_sequence, float* data) {
    int numBlocks = 4; // Assuming the number of blocks is fixed as 4 based on the input shape
    int numThreads = 13; // Assuming the number of threads is fixed as 13 based on the input shape

    #pragma omp parallel for
    for (int blockIdx = 0; blockIdx < numBlocks; blockIdx++) {
        for (int threadIdx = 0; threadIdx < numThreads; threadIdx++) {
            int index = ((blockIdx * numThreads) + threadIdx);
            T_reverse_sequence[index] = data[(index + 312 - ((blockIdx >> 3) * 104))];
        }
    }
}