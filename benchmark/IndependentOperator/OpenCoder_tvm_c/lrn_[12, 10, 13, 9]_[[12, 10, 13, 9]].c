void default_function_kernel(float* data, float* tensor, int size) {
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        tensor[i] = 0.0f;
    }
    #pragma omp parallel for
    for (int i = 0; i < size; i++) {
        tensor[i] += data[i] * data[i];
    }
}