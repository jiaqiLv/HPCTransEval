void default_function_kernel(float* data, float* resize) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 40; ++j) {
            int blockIdx_x = i * 40 + j;
            int threadIdx_x = j % 2;
            resize[blockIdx_x * 36 + threadIdx_x] = data[(blockIdx_x / 40) * 360 + ((blockIdx_x % 40) / 2) * 18 + threadIdx_x];
        }
    }
}