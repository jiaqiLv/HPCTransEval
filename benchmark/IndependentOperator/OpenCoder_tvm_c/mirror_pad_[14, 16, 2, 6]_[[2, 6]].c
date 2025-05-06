void default_function_kernel(float* MirrorPadInput, float* data) {
    int i;
    #pragma omp parallel for private(i)
    for (i = 0; i < 45; i++) {
        if (i < 45) {
            MirrorPadInput[i] = data[((((27 <= i) ? (4 - (i / 9)) : ((i < 9) ? 0 : ((i / 9) - 1))) * 6) + (((((i % 9) == 8) ? (13 - (i % 9)) : ((i % 9) < 2) ? (1 - (i % 9)) : ((i % 9) - 2))))];
        }
    }
}