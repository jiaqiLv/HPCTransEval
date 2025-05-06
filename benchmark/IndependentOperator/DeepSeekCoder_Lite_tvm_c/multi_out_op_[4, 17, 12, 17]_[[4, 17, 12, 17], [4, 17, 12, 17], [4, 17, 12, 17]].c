void default_function_kernel(float* compute, float* data, float* data_1) {
    int numBlocks = 4; // Assuming the number of blocks is fixed based on the input shape
    int threadsPerBlock = 6; // Assuming the number of threads per block is fixed based on the input shape

    #pragma omp parallel for
    for (int block = 0; block < numBlocks; ++block) {
        for (int thread = 0; thread < threadsPerBlock; ++thread) {
            int index = block * threadsPerBlock + thread;
            compute[index] = sqrtf((data[index] + data_1[index]));
        }
    }
}