void default_function_kernel(float* T_cast, float* data, float* weight) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    int k1 = 0;
    float sum = 0.0f;

    #pragma omp parallel for collapse(2) private(threadIdx_x, k1, sum)
    for (blockIdx_x = 0; blockIdx_x < 8; blockIdx_x++) {
        for (threadIdx_x = 0; threadIdx_x < 35; threadIdx_x++) {
            sum = 0.0f;
            for (k1 = 0; k1 < 10; k1++) {
                sum += data[(blockIdx_x * 35 + threadIdx_x) % 168] * data[(blockIdx_x * 35 + threadIdx_x) % 168];
            }
            T_cast[(blockIdx_x * 35 + threadIdx_x)] = data[(blockIdx_x * 35 + threadIdx_x) % 168] * weight[(blockIdx_x * 35 + threadIdx_x) % 24] * (1.0f / sqrtf(sum * 0.01f + 0.00001f));
        }
    }
}