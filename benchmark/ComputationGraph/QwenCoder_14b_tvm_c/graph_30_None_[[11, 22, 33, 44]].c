void default_function_kernel(float* compute, float* ph) {
    const int num_threads = 384;

    // Kernel 1: Compute exp of elements in compute array
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_threads; ++i) {
        compute[i] = expf(compute[i]);
    }

    // Kernel 2: Copy elements from ph to T_strided_slice based on complex indexing
    float T_strided_slice[num_threads];
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_threads; ++i) {
        int index = ((i / 192) * 31944) + (((i % 192) / 48) * 1452) + (((i % 48) >> 3) * 44) + (i & 7) + 149194;
        T_strided_slice[i] = ph[index];
    }

    // Kernel 3: Compute log10 of elements in T_strided_slice
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_threads; ++i) {
        T_strided_slice[i] = log10f(T_strided_slice[i]);
    }

    // Kernel 4: Round elements in T_strided_slice
    #pragma omp parallel for num_threads(num_threads)
    for (int i = 0; i < num_threads; ++i) {
        T_strided_slice[i] = roundf(T_strided_slice[i]);
    }
}