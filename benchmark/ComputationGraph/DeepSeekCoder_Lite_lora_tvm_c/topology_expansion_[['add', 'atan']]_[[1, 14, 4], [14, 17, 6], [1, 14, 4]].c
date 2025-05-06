void default_function_kernel(float* T_add, float* ph_0, float* ph_3) {
    int numBlocks = 1; // Assuming the number of blocks is fixed based on the input shape
    int threadsPerBlock = 36; // Assuming the threads per block is fixed based on the input shape

    #pragma omp parallel for
    for (int blockIdx = 0; blockIdx < numBlocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < threadsPerBlock; ++threadIdx) {
            int index = blockIdx * threadsPerBlock + threadIdx;
            T_add[index] = ph_0[index] + ph_3[index];
        }
    }

    threadsPerBlock = 4; // Re-adjust for the second kernel
    #pragma omp parallel for
    for (int blockIdx = 0; blockIdx < numBlocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < threadsPerBlock; ++threadIdx) {
            int index = blockIdx * threadsPerBlock + threadIdx;
            compute[blockIdx * threadsPerBlock + threadIdx] = atanf(ph_0[index]);
        }
    }
}