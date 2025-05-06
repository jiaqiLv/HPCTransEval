void default_function_kernel(float* data, int32_t* indices, float* scatter_nd_cpu, float* updates) {
    int i, j;
    #pragma omp parallel for collapse(2)
    for (i = 0; i < 195; i++) {
        for (j = 0; j < 1560; j++) {
            scatter_nd_cpu[i * 1560 + j] = scatter_nd_cpu[i * 1560 + j] + updates[i * 1560 + j];
        }
    }
}