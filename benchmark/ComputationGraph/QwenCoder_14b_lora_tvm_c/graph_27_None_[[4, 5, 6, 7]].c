void default_function_kernel(float* T_transpose, float* ph) {
    // Assuming the size of T_transpose and ph is known and is 840
    #pragma omp parallel for
    for (int i = 0; i < 840; ++i) {
        T_transpose[i] = ph[i];
    }
}