void default_function_kernel(float* T_strided_slice, float* a) {
    int num_blocks = 2; // Number of blocks is given by the shape of the output tensor
    int num_threads_per_block = 7; // Number of threads per block is given by the shape of the output tensor

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; i++) {
        T_strided_slice[i] = a[i + 183];
    }
}