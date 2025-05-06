void default_function_kernel(float* T_strided_slice, float* ph) {
    int num_blocks = 1125 / 1024;
    #pragma omp parallel for
    for (int b = 0; b < num_blocks; ++b) {
        int idx = b * 1024 + omp_get_thread_num();
        if (idx < 1125) {
            T_strided_slice[idx] = ph[((((((((((b * 256) + (omp_get_thread_num() >> 2)) / 225) * 31944) + (((((((b * 62) + (omp_get_thread_num() >> 1)) % 450) / 45) * 1452)) + (((((b * 34) + omp_get_thread_num()) % 90) / 9) * 44)) + ((((b * 7) + omp_get_thread_num()) % 9)) + 50414))];
        }
    }
}