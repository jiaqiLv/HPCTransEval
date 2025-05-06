void default_function_kernel(int8_t* compute, float* data) {
    int numBlocks = 14; // Assuming numBlocks is derived from the input shape
    int threadsPerBlock = 32; // Assuming threadsPerBlock is derived from the input shape

    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        if ((((int)i / threadsPerBlock) * 2 + (i % threadsPerBlock) / 16) < 665) {
            compute[i] = (int8_t)(data[i] != data[i]);
        }
    }
}