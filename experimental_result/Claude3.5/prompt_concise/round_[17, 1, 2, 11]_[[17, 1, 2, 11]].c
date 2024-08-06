void default_function_kernel_cpu(float* compute, float* data) {
    for (int blockIdx_x = 0; blockIdx_x < 17; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < 3; ++threadIdx_x) {
            int index = (blockIdx_x * 3) + threadIdx_x;
            if (index < 374) {
                compute[index] = roundf(data[index]);
            }
        }
    }
}
