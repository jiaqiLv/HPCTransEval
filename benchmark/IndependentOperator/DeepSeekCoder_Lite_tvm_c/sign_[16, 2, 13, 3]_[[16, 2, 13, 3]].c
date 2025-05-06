void default_function_kernel(float* T_sign, float* data) {
    int num_blocks = 16 * 2 * 13; // Calculate the total number of blocks based on the input shape
    int num_threads = 16; // Each block has 16 threads

    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        for (int j = 0; j < num_threads; ++j) {
            int index = i * num_threads + j;
            if (data[index] > 0.0f) {
                T_sign[index] = 1.0f;
            } else if (data[index] < 0.0f) {
                T_sign[index] = -1.0f;
            } else {
                T_sign[index] = 0.0f;
            }
        }
    }
}