void default_function_kernel(float* MirrorPadInput, float* data) {
    #pragma omp parallel for
    for (int i = 0; i < 45; i++) {
        if (i < 45) {
            int row = i / 9;
            int col = i % 9;
            int src_index = (row * 6 + col) % 36;
            if (row >= 2 && row < 4 && col >= 3 && col < 6) {
                src_index = (row * 6 + col) % 36;
            } else if (row >= 2 && row < 4) {
                src_index = (row * 6 + col) % 36;
            } else if (col >= 3 && col < 6) {
                src_index = (row * 6 + col) % 36;
            } else {
                src_index = (row * 6 + col) % 36;
            }
            MirrorPadInput[i] = data[src_index];
        }
    }
}