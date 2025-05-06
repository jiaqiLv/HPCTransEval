void default_function_kernel(float* T_transpose, float* ph) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 625; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            int index = (blockIdx_x * 1024) + threadIdx_x;
            if (index < 625 * 1024) {
                // Kernel 1: Logarithm base 2
                T_transpose[index] = log2f(T_transpose[index]);

                // Kernel 2: Clamp value between 0 and 10
                T_transpose[index] = fmaxf(fminf(T_transpose[index], 10.0f), 0.0f);

                // Kernel 3: Hyperbolic tangent
                T_transpose[index] = tanhf(T_transpose[index]);

                // Kernel 4: Copy from ph array with complex indexing
                int ph_index = (((((blockIdx_x * 128) + (threadIdx_x >> 3)) / 125) * 31944) +
                               (((((blockIdx_x * 6) + (threadIdx_x >> 2)) % 250) / 25) * 1452) +
                               (((((blockIdx_x * 12) + (threadIdx_x >> 1)) % 50) / 5) * 44) +
                               (((blockIdx_x * 4) + threadIdx_x) % 10) + 16973);
                T_transpose[index] = ph[ph_index];

                // Kernel 5: Copy back to T_transpose with complex indexing
                int T_index = (((((blockIdx_x * 4) + threadIdx_x) % 10) * 1000) +
                               (((((blockIdx_x * 128) + (threadIdx_x >> 3)) / 125) * 100) +
                               (((((blockIdx_x * 12) + (threadIdx_x >> 1)) % 50) / 5) * 10) +
                               (((((blockIdx_x * 6) + (threadIdx_x >> 2)) % 250) / 25));
                T_transpose[T_index] = T_transpose[index];
            }
        }
    }
}