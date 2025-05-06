void default_function_kernel(float* T_transpose, float* ph) {
    // Your code here
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 1125; i++) {
        for (int j = 0; j < 1024; j++) {
            T_transpose[i * 1024 + j] = ph[(i * 256 + j / 225) * 31944 + (i * 62 + j / 45) * 1452 + (i * 34 + j / 9) * 44 + i * 7 + j % 9 + 50414];
        }
    }
}