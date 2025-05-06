void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for collapse(4)
    for (int i0 = 0; i0 < 3; i0++) {
        for (int i1 = 0; i1 < 18; i1++) {
            for (int i2 = 0; i2 < 6; i2++) {
                for (int i3 = 0; i3 < 17; i3++) {
                    compute[((i0 * 18 + i1) * 6 + i2) * 17 + i3] = logf(data[((i0 * 18 + i1) * 6 + i2) * 17 + i3]);
                }
            }
        }
    }
}