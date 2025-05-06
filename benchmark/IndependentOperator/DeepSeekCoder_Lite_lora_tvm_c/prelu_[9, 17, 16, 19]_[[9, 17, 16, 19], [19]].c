void default_function_kernel(float* Scale, float* compute, float* data) {
    int numBlocks = 9; // Assuming numBlocks is derived from the input shape
    int threadsPerBlock = 38; // Assuming threadsPerBlock is derived from the input shape

    #pragma omp parallel for
    for (int blockIdx = 0; blockIdx < numBlocks; blockIdx++) {
        for (int threadIdx = 0; threadIdx < threadsPerBlock; threadIdx++) {
            int index = blockIdx * threadsPerBlock + threadIdx;
            if (0.000000e+00f < data[index]) {
                compute[index] = data[index];
            } else {
                compute[index] = data[index] * Scale[threadIdx % 19];
            }
        }
    }
}