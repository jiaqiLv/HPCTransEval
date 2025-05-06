void default_function_kernel(float* Scale, float* ScaleShift, float* Shift, float* data) {
    int numBlocks = 49; // Assuming the number of blocks is fixed based on the input shape
    int threadsPerBlock = 64;

    #pragma omp parallel for
    for (int blockIdx = 0; blockIdx < numBlocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < threadsPerBlock; ++threadIdx) {
            int index = blockIdx * threadsPerBlock + threadIdx;
            ScaleShift[blockIdx * threadsPerBlock + threadIdx] = (data[blockIdx * threadsPerBlock + threadIdx] * Scale[(blockIdx % 49) * 2 + (threadIdx >> 5) / 49 * 7 + (blockIdx + threadIdx) % 7]) + Shift[(blockIdx % 49) * 2 + (threadIdx >> 5) / 49 * 7 + (blockIdx + threadIdx) % 7];
        }
    }
}