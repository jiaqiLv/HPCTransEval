void default_function_kernel(float* __restrict__ T_reshape, float* __restrict__ ph) {
    int num_blocks = 4; // Assuming 4 blocks based on the input shape
    int threads_per_block = 256;

    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        for (int t = 0; t < threads_per_block; ++t) {
            int index = b * 1024 + t;
            if (index < 1035) {
                if (((b * 256) + (t >> 2)) < 1035) {
                    T_reshape[b * 1024 + t] = ph[((((b * 256 + t) / 3) * 12) + ((b * 4 + t) % 12))];
                }
            }
        }
    }
}