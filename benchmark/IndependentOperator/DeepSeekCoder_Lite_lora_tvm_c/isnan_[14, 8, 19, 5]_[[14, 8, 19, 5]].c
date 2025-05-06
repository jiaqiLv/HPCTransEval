void default_function_kernel(int8_t* compute, float* data) {
    int numBlocks = 14; // Assuming the number of blocks is fixed based on the input shape
    int threadsPerBlock = 32; // Assuming the number of threads per block is fixed based on the input shape

    #pragma omp parallel for
    for (int blockIdx = 0; blockIdx < numBlocks; blockIdx++) {
        for (int threadIdx = 0; threadIdx < threadsPerBlock; threadIdx++) {
            int index = (blockIdx * threadsPerBlock) + threadIdx;
            if (index < 665) {
                compute[index] = (int8_t)(data[index] != data[index]);
            }
        }
    }
}