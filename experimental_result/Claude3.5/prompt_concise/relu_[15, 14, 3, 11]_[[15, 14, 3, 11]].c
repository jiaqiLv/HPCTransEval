void default_function_kernel_cpu(float* compute, float* data) {
    for (int blockIdx_x = 0; blockIdx_x < 15; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < 14; ++threadIdx_x) {
            int index = (blockIdx_x * 14) + threadIdx_x;
            compute[index] = fmaxf(data[index], 0.000000e+00f);
        }
    }
}
