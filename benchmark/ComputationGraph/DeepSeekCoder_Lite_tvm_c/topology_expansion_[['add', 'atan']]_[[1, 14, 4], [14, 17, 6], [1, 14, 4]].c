void default_function_kernel(float* T_add, float* ph_0, float* ph_3) {
    int numBlocks = 1; // Assuming the number of blocks is 1 as per the input shape
    int threadsPerBlock = 4; // Assuming threads per block is 4 as per the second kernel

    #pragma omp parallel for
    for (int blockIdx = 0; blockIdx < numBlocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < threadsPerBlock; ++threadIdx) {
            int idx = blockIdx * threadsPerBlock + threadIdx;
            T_add[idx] = ph_0[idx] + ph_3[idx];
        }
    }

    // Assuming the first kernel is for computing atanf
    #pragma omp parallel for
    for (int blockIdx = 0; blockIdx < numBlocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < threadsPerBlock; ++threadIdx) {
            int idx = blockIdx * threadsPerBlock + threadIdx;
            compute[blockIdx * threadsPerBlock + threadIdx] = atanf(ph_0[idx]);
        }
    }
}