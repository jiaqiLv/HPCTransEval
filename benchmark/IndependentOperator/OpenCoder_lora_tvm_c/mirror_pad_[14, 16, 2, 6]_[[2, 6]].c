void default_function_kernel(float* MirrorPadInput, float* data) {
    int i;
    #pragma omp parallel for
    for (i = 0; i < 45; i++) {
        MirrorPadInput[i] = data[((((27 <= i) ? (4 - (i / 9)) : ((i % 9) ? 0 : ((i % 9) - 1))) * 6)) * 6)))];