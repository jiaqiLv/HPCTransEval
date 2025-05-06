void default_function_kernel(float* compute, float* data) {
    int numBlocks = 8; // Assuming numBlocks is known from the CUDA kernel code context
    int threadsPerBlock = 32; // Assuming threadsPerBlock is known from the CUDA kernel code context

    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        if (i < 187) {
            compute[i] = ceilf(data[i]);
        }
    }
}