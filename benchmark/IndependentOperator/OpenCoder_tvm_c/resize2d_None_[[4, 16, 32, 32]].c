void default_function_kernel(float* A, float* resize) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    int i = 0;
    for (blockIdx_x = 0; blockIdx_x < 4; blockIdx_x++) {
        for (threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            if (i < 625) {
                int idx = blockIdx_x * 1024 + threadIdx_x;
                resize[idx] = A[idx] * (1.0f - ((float)((int)floorf((((((float)(((((int)blockIdx_x) * 24) + ((int)threadIdx_x)) % 50)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f)))) + A[idx] * ((((((float)(((((int)blockIdx_x) * 24) + ((int)threadIdx_x)) % 50)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f)))))) * ((((((float)(((((int)blockIdx_x) * 512) + (((int)threadIdx_x) >> 1)) % 1250) / 25)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f) - ((float)((int)floorf((((((float)(((((int)blockIdx_x) * 512) + (((int)threadIdx_x)) % 1250) / 25)) + 5.000000e-01f) * 6.400000e-01f) - 5.000000e-01f))))));
            }
            i++;
        }
    }
}