void default_function_kernel(float* compute, float* data) {
    int num_blocks = 16 * 3 * 4; // Assuming the shape is [16, 3, 4, 12]
    int threads_per_block = 64;

    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        for (int j = 0; j < threads_per_block; ++j) {
            int index = i * threads_per_block + j;
            compute[index] = fabsf(data[index]);
        }
    }
}