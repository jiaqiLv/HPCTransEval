void default_function_kernel(float* data, float* depth_to_space) {
    int blockSize = 54;
    int numBlocks = 14 * 5 * 18 * 3 / 54;

    #pragma omp parallel for
    for (int i = 0; i < numBlocks; i++) {
        int threadIdx = omp_get_thread_num();
        int blockIdx = i;

        depth_to_space[((((int)blockIdx) * blockSize) + ((int)threadIdx))] = data[((((((((int)blockIdx) >> 2) * 270) + (((((((int)blockIdx) & 3) * 9) + (((int)threadIdx) / 6)) % 2) * 108)) + (((((int)threadIdx) % 6) % 2) * 54)) + (((((((int)blockIdx) & 3) * 9) + (((int)threadIdx) / 6)) / 2) * 3)) + ((((int)threadIdx) % 6) / 2))];
    }
}