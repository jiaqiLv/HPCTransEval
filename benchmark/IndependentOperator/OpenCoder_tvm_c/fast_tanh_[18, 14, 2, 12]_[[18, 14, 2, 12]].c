void default_function_kernel(float* T_fast_tanh, float* data, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        float x = data[i];
        if (x > 9.0f) x = 9.0f;
        if (x < -9.0f) x = -9.0f;
        T_fast_tanh[i] = (x * (1.0f - exp(-2.0f * x * x))) / (1.0f + exp(-2.0f * x * x));
    }
}