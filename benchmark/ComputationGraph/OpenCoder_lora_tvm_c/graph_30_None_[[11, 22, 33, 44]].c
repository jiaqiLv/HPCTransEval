void default_function_kernel_2(float* compute) {
    #pragma omp parallel for
    for (int i = 0; i < 384; i++) {
        compute[i] = roundf(compute[i]);
    }
}