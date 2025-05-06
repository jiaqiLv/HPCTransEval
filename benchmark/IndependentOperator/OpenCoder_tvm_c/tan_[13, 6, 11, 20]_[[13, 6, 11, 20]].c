void default_function_kernel(float* compute, float* data) {
    int i;
    for (i = 0; i < 13 * 6 * 11 * 20; i++) {
        compute[i]=