void default_function_kernel(float* compute, float* data) {
    int numBlocks = 1; // Assuming the number of blocks is 1 as per the input shape
    int threadsPerBlock = 28; // Assuming threads per block is 28 as per the input shape

    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        compute[i] = tanhf(data[i]);
    }
}