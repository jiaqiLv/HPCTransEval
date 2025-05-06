void default_function_kernel(float* compute, float* ph) {
    int num_threads = 384; // Assuming the number of threads is fixed based on the CUDA kernel

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        compute[i] = expf(ph[((((((i / 192) * 31944) + (((i % 192) / 48) * 1452)) + (((i % 48) >> 3) * 44)) + (i & 7)) + 149194)]);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        compute[i] = log10f(compute[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        compute[i] = roundf(compute[i]);
    }
}