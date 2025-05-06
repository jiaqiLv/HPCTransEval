void default_function_kernel(float* compute, float* ph_0) {
    int numBlocks = 10; // Assuming numBlocks is known from the context
    int threadsPerBlock = 36; // Assuming threadsPerBlock is known from the context

    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        compute[i] = ceilf(ph_0[i]);
    }
}