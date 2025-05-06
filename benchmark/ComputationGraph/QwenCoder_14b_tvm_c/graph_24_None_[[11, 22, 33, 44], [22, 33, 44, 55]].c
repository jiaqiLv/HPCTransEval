void default_function_kernel(float* T_reverse_sequence, float* compute, float* ph, float* ph_1) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 625; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            int index = (blockIdx_x * 1024) + threadIdx_x;

            // Kernel 1
            if (index < 625 * 1024) {
                T_reverse_sequence[index] = ph[((((((((((blockIdx_x * 128) + (threadIdx_x >> 3)) / 125) * 79860) + (((((((blockIdx_x * 6) + (threadIdx_x >> 2)) % 250) / 25) * 2420)) + (((((((blockIdx_x * 12) + (threadIdx_x >> 1)) % 50) / 5) * 55)) + (((blockIdx_x * 4) + threadIdx_x) % 10)) + 933559)];
            }

            // Kernel 2
            if (index < 625 * 1024) {
                compute[index] = atanhf(T_reverse_sequence[index]);
            }

            // Kernel 3
            if (index < 625 * 1024) {
                T_reverse_sequence[index] = ph_1[((((((((((blockIdx_x * 128) + (threadIdx_x >> 3)) / 125) * 31944) + (((((((blockIdx_x * 6) + (threadIdx_x >> 2)) % 250) / 25) * 1452)) + (((((((blockIdx_x * 12) + (threadIdx_x >> 1)) % 50) / 5) * 44)) + (((blockIdx_x * 4) + threadIdx_x) % 10)) + 16973)];
            }

            // Kernel 4
            if (index < 625 * 1024) {
                T_reverse_sequence[index] = T_reverse_sequence[(((((((((blockIdx_x * 256) + (threadIdx_x >> 2)) / 25) * 100) + (((blockIdx_x * 4) + threadIdx_x) % 10)) + 90) - (((((((blockIdx_x * 12) + (threadIdx_x >> 1)) % 50) / 5) * 10))];
            }
        }
    }
}