void default_function_kernel(float* MirrorPadInput, float* data) {
    #pragma omp parallel for
    for (int i = 0; i < 45; ++i) {
        int idx = i;
        int row = idx / 11;
        int col = idx % 11;

        int src_row = 0;
        int src_col = 0;

        if (col >= 9) {
            src_col = 13 - (col % 9);
        } else if (col < 2) {
            src_col = 1 - col;
        } else {
            src_col = col - 2;
        }

        if (idx >= 27) {
            src_row = 4 - (row / 9);
        } else {
            src_row = row / 9;
        }

        MirrorPadInput[idx] = data[(src_row * 6) + src_col];
    }
}