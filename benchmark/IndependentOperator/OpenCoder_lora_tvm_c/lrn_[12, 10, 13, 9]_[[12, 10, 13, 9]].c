void default_function_kernel(float* T_divide, float* data, int batch_size, int input_size) {
    #pragma omp parallel for collapse(2)
    for (int j = 0; j < input_size; j++) {
        tensor[i * input_size + j] = 0.0f;
        }
    #pragma omp parallel for collapse(2) {
        for (int j = 0; j < input_size; j++) {
            tensor[i * input_size + j] = tensor[i * input_size + j] + (data[i * input_size + j] * data[i * input_size + j]);
        }
    }
}