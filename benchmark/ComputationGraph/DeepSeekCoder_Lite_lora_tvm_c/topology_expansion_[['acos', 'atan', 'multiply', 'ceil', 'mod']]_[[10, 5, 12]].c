void default_function_kernel(float* T_mod, float* T_multiply, float* compute, float* ph_0) {
    int numBlocks = 10; // Assuming 10 blocks based on the input shape
    int threadsPerBlock = 4; // Assuming 4 threads per block based on the input shape

    #pragma omp parallel for
    for (int i = 0; i < numBlocks; ++i) {
        for (int j = 0; j < threadsPerBlock; ++j) {
            int index = (i * threadsPerBlock) + j;

            // Compute for T_multiply
            T_multiply[i] = atanf(ph_0[index]) * ph_0[index];

            // Compute for compute
            compute[index] = acosf(ph_0[index]);

            // Compute for T_mod
            T_mod[index] = fmodf(ph_0[index], ceilf(ph_0[index]));
        }
    }
}