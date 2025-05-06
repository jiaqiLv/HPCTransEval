void default_function_kernel(float* compute, float* data) {
    int num_blocks = 3 * 12 * 18; // Assuming the shape is [3, 12, 18, 4]
    int num_threads = 24;

    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        for (int j = 0; j < num_threads; ++j) {
            int index = i * num_threads + j;
            if (0.000000e+00f < data[index]) {
                compute[index] = data[index];
            } else {
                compute[index] = data[index] * 5.000000e-01f;
            }
        }
    }
}