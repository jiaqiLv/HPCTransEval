void default_function_kernel(float* T_strided_slice, float* data) {
    #pragma omp parallel for collapse(4)
    for (int i0 = 0; i0 < 15; i0++) {
        for (int i1 = 0; i1 < 19; i1++) {
            for (int i2 = 0; i2 < 2; i2++) {
                i = i0 * 380 + i1 * 20 + i2 * 20;
                o = (i0 / 3 * 4560 + i1 / 5 * 2280 + i0 / 3 % 20 * 40 + i1 / 5 % 4 * 20 + i0 / 4 % 20;
                T_strided_slice[o]= data[i];
 o = (i0 / 3 * 4560 + i1 / 5 * 2280 + i0 / 3 % 20 * 40 + i1 / 5 % 4 * 20 + i0 / 4 % 20;
                T_strided_slice[o]= data[i];