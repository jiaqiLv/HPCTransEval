void default_function_kernel(float* T_strided_slice, float* a) {
    #pragma omp parallel for
    for (int i = 0; i < 105; ++i) {
        T_strided_slice[i] = a[i + 183];
    }
}