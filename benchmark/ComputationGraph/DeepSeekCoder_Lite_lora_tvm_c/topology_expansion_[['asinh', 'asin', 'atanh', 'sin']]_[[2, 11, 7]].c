void default_function_kernel(float* compute, float* compute_1, float* compute_2, float* ph_0) {
    int numBlocks = 2; // Assuming the number of blocks is known from the CUDA code
    int threadsPerBlock = 36; // Assuming the threads per block is known from the CUDA code

    #pragma omp parallel for
    for (int b = 0; b < numBlocks; ++b) {
        for (int t = 0; t < threadsPerBlock; ++t) {
            int index = b * threadsPerBlock + t;
            compute[index] = atanhf(asinf(ph_0[index]));
            compute_1[index] = __sinf(ph_0[index]);
            compute_2[index] = asinhf(ph_0[index]);
        }
    }
}