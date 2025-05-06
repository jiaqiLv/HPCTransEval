void default_function_kernel(float* T_reverse_sequence, float* compute, float* ph, float* ph_1) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    #pragma omp parallel for collapse(2) private(blockIdx_x, threadIdx_x)
    for (blockIdx_x = 0; blockIdx_x < 11; blockIdx_x++) {
        for (threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            if (((blockIdx_x * 64) + (threadIdx_x >> 4)) < 625) {
                T_reverse_sequence[(blockIdx_x * 1024) + threadIdx_x] = ph[((((blockIdx_x * 128) + (threadIdx_x >> 3)) / 125) * 31944) + ((((blockIdx_x * 6) + (threadIdx_x >> 2)) % 250) / 25) * 1452) + ((((blockIdx_x * 12) + (threadIdx_x >> 1)) % 50) / 5) * 44) + ((blockIdx_x * 4) + threadIdx_x) % 10) + 16973];
            }
        }
    }
    for (blockIdx_x = 0; blockIdx_x < 11; blockIdx_x++) {
        for (threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            if (((blockIdx_x * 64) + (threadIdx_x >> 4)) < 625) {
                compute[(blockIdx_x * 1024) + threadIdx_x] = atanf(T_reverse_sequence[(blockIdx_x * 1024) + threadIdx_x]);
            }
        }
    }
    for (blockIdx_x = 0; blockIdx_x < 11; blockIdx_x++) {
        for (threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            if (((blockIdx_x * 64) + (threadIdx_x >> 4)) < 625) {
                T_reverse_sequence[((blockIdx_x * 256) + (threadIdx_x >> 2)) / 25 * 100 + ((blockIdx_x * 4) + threadIdx_x) % 10) + 90 - (((blockIdx_x * 12) + (threadIdx_x >> 1)) % 50) / 5 * 10] = T_reverse_sequence[(blockIdx_x * 1024) + threadIdx_x];
            }
        }
    }
}