void default_function_kernel(float* T_divide, float* data, float* tensor, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        tensor[i] = 0.0f;
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; i++) {
        T_divide[i] = data[i] / powf(2.0f + 1.0e-4f * tensor[i], 0.75f);
    }
}