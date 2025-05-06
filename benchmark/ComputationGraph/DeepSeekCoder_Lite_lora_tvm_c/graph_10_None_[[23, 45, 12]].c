void default_function_kernel_4(float* T_reshape, float* T_reshape_1) {
    int num_blocks = 1; // Assuming the number of blocks is determined by the input size and block size
    int num_threads_per_block = 1024;

    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < num_threads_per_block; ++t) {
            int index = ((b * num_threads_per_block) + t);
            if (index < 1035) {
                T_reshape[index] = T_reshape_1[((((((b * 256) + t) / 15) * 60) + (((((b * 4) + t) % 60) / 3) * 3)) + (b + t) % 3)];
            }
        }
    }
}