void default_function_kernel(float* T_transpose, float* ph) {
    #pragma for collapse(2)
    for (int i = 0; i++) {
        T_trans = tanhf(T_transpose);
    }