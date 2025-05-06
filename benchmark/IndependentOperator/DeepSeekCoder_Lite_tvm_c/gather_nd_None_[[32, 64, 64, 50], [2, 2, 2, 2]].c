void default_function_kernel(float* A, float* T_gather_nd, float* indices) {
    int blockSize = 1024;
    int numBlocks = 32 * 64 * 64; // Assuming the number of blocks is derived from the input shape

    #pragma omp parallel for
    for (int i = 0; i < numBlocks; i++) {
        int threadIdx = omp_get_thread_num();
        int idx = ((i * blockSize) + threadIdx);
        int index0 = indices[(i * 8) + (threadIdx >> 7)];
        int index1 = indices[((i * 8) + (threadIdx >> 7)) + 8];
        int index2 = (i * 1024) + threadIdx;

        T_gather_nd[idx] = A[(index0 * 204800) + (index1 * 3200) + index2 % 3200];
    }
}