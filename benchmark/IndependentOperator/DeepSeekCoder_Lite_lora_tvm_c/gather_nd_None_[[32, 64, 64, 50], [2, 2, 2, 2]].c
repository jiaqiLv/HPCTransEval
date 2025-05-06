void default_function_kernel(float* A, float* T_gather_nd, float* indices) {
    int blockSize = 1024;
    int numBlocks = (32 * 64 * 64 * 50) / blockSize;

    #pragma omp parallel for
    for (int blockIdx = 0; blockIdx < numBlocks; blockIdx++) {
        int threadIdx = omp_get_thread_num();
        int idx = ((blockIdx * blockSize) + threadIdx);
        int index1 = indices[(blockIdx * 8) + (threadIdx >> 7)];
        int index2 = indices[((blockIdx * 8) + (threadIdx >> 7)) + 8];
        int index3 = (blockIdx * 1024) + threadIdx;

        T_gather_nd[idx] = A[(index1 * 204800) + (index2 * 3200) + index3];
    }
}