void default_function_kernel(float* MirrorPadInput, float* data) {
    #pragma omp parallel for
    for (int i = 0; i < 45; ++i) {
        int x = i / 11;
        int y = i % 11;

        int row = (y < 9) ? 0 : (y / 9) - 1;
        int col = (y < 2) ? 1 - y : (y == 8) ? 13 - y : y - 2;

        MirrorPadInput[i] = data[(row * 6) + col];
    }
}