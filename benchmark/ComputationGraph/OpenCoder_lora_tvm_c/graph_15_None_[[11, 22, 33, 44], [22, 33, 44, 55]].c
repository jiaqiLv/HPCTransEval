void default_function_kernel(float* compute, float* ph, float* ph_1) {
    #pragma omp parallel for collapse(2)
    for (int i0 = 0; i0 < 10; i0++) {
        for (int i1 = 0; i1 < 10; i1++) {
            compute[i0 * 10 + i1] = ph[((((i0 / 125) * 31944) + (((i0 / 6) % 250) / 25) * 1452) + (((i0 / 12) % 50) / 5) * 44) + ((i0 / 4) % 10) + 16973]];
        }
    }
}