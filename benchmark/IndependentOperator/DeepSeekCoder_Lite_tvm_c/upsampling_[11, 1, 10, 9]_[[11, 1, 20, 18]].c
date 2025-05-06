void default_function_kernel(float* data, float* resize) {
    int num_blocks = 11; // Given from the input shape
    int num_threads_per_block = 36; // Given from the input shape

    #pragma omp parallel for
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < num_threads_per_block; ++thread) {
            int index = (block * num_threads_per_block) + thread;
            resize[((block * num_threads_per_block) + thread)] = data[((((block / 40) * 360) + (((block % 40) / 2) * 18)) + ((thread / 2)))]);
        }
    }
}