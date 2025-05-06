void default_function_kernel(float* T_multiply, float* compute, float* compute_1, float* ph_0, float* ph_3) {
    int size_T_multiply = 19 * 20 * 18;
    int size_compute = 9 * 19 * 17;

    // Kernel 1: Compute absolute values
    #pragma omp parallel for
    for (int i = 0; i < size_compute; ++i) {
        compute[i] = fabsf(ph_0[i]);
    }

    // Kernel 2: Compute inverse hyperbolic tangent values
    #pragma omp parallel for
    for (int i = 0; i < size_compute; ++i) {
        compute_1[i] = atanhf(ph_0[i]);
    }

    // Kernel 3: Compute element-wise multiplication
    #pragma omp parallel for
    for (int i = 0; i < size_T_multiply; ++i) {
        T_multiply[i] = ph_0[i] * ph_3[i];
    }
}