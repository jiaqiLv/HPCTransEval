void default_function_kernel(float* compute, float* ph) {
    int num_threads = omp_get_max_threads();
    #pragma omp parallel for
    for (int t = 0; t < num_threads; ++t) {
        int thread_id = omp_get_thread_num();
        int local_size = 168;
        if (thread_id < local_size) {
            int idx = thread_id;
            compute[idx] = expf(ph[(((((((idx / 21) * 60) + ((((idx % 21) / 7) * 12)) + (idx % 7)) + 61))]));
        }
    }
}