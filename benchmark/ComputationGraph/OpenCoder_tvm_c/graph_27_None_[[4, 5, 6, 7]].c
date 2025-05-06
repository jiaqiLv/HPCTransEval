void default_function_kernel(float* T_reshape, float* ph) {
    int i;
    #pragma omp parallel for
    for (i = 0; i < 840; i++) {
        T_reshape[i] = ph[i];
    }
}

int main() {
    float T_reshape[840];
    float ph[840];
    int i;
    for (i = 0; i < 840; i++) {
        T_reshape[i] = i + 1;
        ph[i] = i + 1;
    }
    default_function_kernel(T_reshape, ph);
    for (i = 0; i < 840; i++) {
        printf("%f ", T_reshape[i]);
    }
    return 0;
}