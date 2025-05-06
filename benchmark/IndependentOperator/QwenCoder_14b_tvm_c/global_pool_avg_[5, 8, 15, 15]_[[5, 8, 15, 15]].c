void default_function_kernel(float* adaptive_pool_avg, float* data) {
    #define BATCH_SIZE 5
    #define CHANNELS 8
    #define HEIGHT 15
    #define WIDTH 15
    #define THREADS_PER_BLOCK 20

    #pragma omp parallel for collapse(2)
    for (int b = 0; b < BATCH_SIZE; ++b) {
        for (int c = 0; c < CHANNELS; ++c) {
            int index = (b * CHANNELS + c) * THREADS_PER_BLOCK;
            float sum = 0.0f;

            for (int h = 0; h < HEIGHT; ++h) {
                for (int w = 0; w < WIDTH; ++w) {
                    sum += data[(b * CHANNELS * HEIGHT * WIDTH) + (c * HEIGHT * WIDTH) + (h * WIDTH) + w];
                }
            }

            adaptive_pool_avg[index] = sum * 4.444444e-03f;
        }
    }
}