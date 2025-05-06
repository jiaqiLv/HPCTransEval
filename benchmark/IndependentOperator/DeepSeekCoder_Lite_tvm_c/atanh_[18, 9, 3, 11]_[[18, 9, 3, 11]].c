void default_function_kernel(float* compute, float* data) {
    int numBlocks = 18; // Assuming numBlocks is the same as the number of blocks in the CUDA kernel
    int threadsPerBlock = 33; // Assuming threadsPerBlock is the same as the number of threads per block in the CUDA kernel

    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        compute[i] = atanhf(data[i]);
    }
}