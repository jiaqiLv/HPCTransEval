void default_function_kernel(float* A, float* T_reshape) {
    int blockSize = 1024;
    int numBlocks = 16 * 64 * 128 / blockSize;

    #pragma omp parallel for
    for (int i = 0; i < numBlocks; ++i) {
        int threadIdx = omp_get_thread_num();
        int idx = (((((i >> 10) * 4194304) + ((i & 255) * 4096)) + (((threadIdx >> 7) * 512)) + ((((i & 1023) >> 9) * 256)) + (((threadIdx & 127) * 2)) + (((i & 511) >> 8))));
        T_reshape[((i * blockSize) + threadIdx)] = A[idx];
    }
}