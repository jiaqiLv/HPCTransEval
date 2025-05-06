void default_function_kernel(float* T_mod, float* compute, float* compute_1, float* ph_0, float* ph_3) {
    int numBlocks = 14; // Assuming the number of blocks is fixed based on the input shape
    int threadsPerBlock = 16; // Assuming the threads per block is fixed based on the input shape

    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        if (((i / threadsPerBlock) * 2 + (i % threadsPerBlock) / 8) < 9) {
            T_mod[i] = fmodf(ph_0[i], ph_3[i]);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        compute[i] = sinf(ph_0[i]);
    }

    #pragma omp parallel for
    for (int i = 0; i < numBlocks * threadsPerBlock; i++) {
        compute_1[i] = asinhf(ceilf(ph_0[i]));
    }
}