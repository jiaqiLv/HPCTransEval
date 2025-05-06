
void default_function_kernel(float* T_add, float* ph, float* ph_1, float* ph_2, float* ph_3, float* ph_4, float* ph_5, float* ph_6, float* ph_7, float* ph_8, float* ph_9, float* ph_10, float* ph_11, float* ph_12) {
    int threadIdx_x = omp_get_thread_num();
    int num_threads = omp_get_max_threads();

    for (int t = 0; t < num_threads; ++t) {
        int start = (1000 * (threadIdx_x / 256)) + (256 * (threadIdx_x % 256));
        int end = start + 256;

        for (int i = start; i < end; ++i) {
            T_add[i] = 0.000000e+00f;
            for (int k = 0; k < 1000; ++k) {
                T_add[i] += ph[((((threadIdx_x / 256) * 1000) + k) * 256) + (threadIdx_x % 256)] * ph_1[(k * 256) + (threadIdx_x % 256)];
            }
        }
    }
}