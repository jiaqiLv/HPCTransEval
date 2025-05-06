void default_function_kernel(float* compute, float* ph) {
    int num_threads = omp_get_max_threads();
    #pragma omp parallel for
    for (int i = 0; i < num_threads * 384; ++i) {
        compute[i] = expf(ph[((((((i / 192) * 31944) + (((i % 192) / 48) * 1452)) + (((i % 48) >> 3) * 44)) + (i & 7)) + 149194)]);
    }
}