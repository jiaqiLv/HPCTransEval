void default_function_kernel(float* compute, float* data) {
    int numBlocks = 7; // Assuming the number of blocks is fixed based on the input shape
    int threadsPerBlock = 36; // Assuming the number of threads per block is fixed based on the input shape

    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        compute[i] = sqrtf(data[i]);
    }
}