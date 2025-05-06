void default_function_kernel(float* T_fast_exp, float* ph) {
    // Your code here
    #pragma omp parallel for collapse(4)
    for (int i0 = 0; i0 < 15; ++i0) {
        int i1 = i0 * 8;
        for (int i2 = 0; i2 < 3; ++i2) {
            int i3 = i1 + i2;
            for (int i4 = 0; i4 < 6; ++i4) {
                int i5 = i3 + i4;
                for (int i6 = 0; i6 < 4; ++i6) {
                    int i7 = i5 + i6;
                    T_fast_exp[i7] = ph[i7];
                }
            }
        }
    }
}