void default_function_kernel(float* Scale, float* ScaleShift, float* Shift, float* data) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    int gridDim_x = 1;
    int blockDim_x = 32;
    int i = 0;
    #pragma omp parallel for private(i, threadIdx_x)
    for (blockIdx_x = 0; blockIdx_x < gridDim_x; blockIdx_x++) {
        for (threadIdx_x = 0; threadIdx_x < blockDim_x; threadIdx_x++) {
            i = blockIdx_x * blockDim_x + threadIdx_x;
            if (i < 11115) {
                ScaleShift[i] = data[i] * Scale[i / 171] + Shift[i / 171];
            }
        }
    }
}