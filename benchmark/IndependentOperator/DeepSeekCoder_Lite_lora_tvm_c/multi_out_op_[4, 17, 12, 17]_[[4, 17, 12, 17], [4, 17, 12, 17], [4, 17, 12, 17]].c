void default_function_kernel(float* compute, float* compute_1, float* data, float* data_1) {
    int numBlocks = 4; // Number of blocks in the CUDA kernel
    int threadsPerBlock = 6; // Threads per block in the CUDA kernel

    #pragma omp parallel for
    for (int b = 0; b < numBlocks; ++b) {
        for (int t = 0; t < threadsPerBlock; ++t) {
            int index = b * threadsPerBlock + t;
            compute[index] = sqrtf((data[index] + data_1[index]));
        }
    }
}