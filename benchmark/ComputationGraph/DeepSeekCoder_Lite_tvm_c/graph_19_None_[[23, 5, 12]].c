void default_function_kernel(float* compute, float* ph) {
    int num_threads = 168; // Assuming the number of threads is fixed based on the CUDA kernel code

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int idx = i;
        compute[idx] = __expf(ph[(((((((idx / 21) * 60) + ((((idx % 21) / 7) * 12)) + (idx % 7)) + 61)))]);
    }
}