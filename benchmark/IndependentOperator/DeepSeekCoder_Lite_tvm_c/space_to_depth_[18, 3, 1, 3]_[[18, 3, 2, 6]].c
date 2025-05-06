void default_function_kernel(float* data, float* space_to_depth) {
    int blockSize = 8;
    int numBlocks = 18;
    int inputWidth = 6;
    int inputHeight = 2;
    int inputChannels = 3;
    int outputWidth = 12;
    int outputHeight = 1;
    int outputChannels = 12;

    #pragma omp parallel for
    for (int block = 0; block < numBlocks; ++block) {
        for (int thread = 0; thread < blockSize; ++thread) {
            int index = (((block * blockSize) + thread) / 9) * 36 + (((((block * 8) + thread) % 36) / 3) % 3) * 12 + (((((block * 8) + thread) % 36) / 3) / 6) * 6 + ((((block * 8) + thread) % 36) / 3) % 3 + (((block * 2) + thread) % 3) * 2 + (((block * 8) + thread) % 36) / 3) / 3;
            space_to_depth[(block * blockSize) + thread] = data[index];
        }
    }
}