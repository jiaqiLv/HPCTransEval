void default_function_kernel(float* A, float* resize) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 625; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            int idx = (blockIdx_x * 1024) + threadIdx_x;
            if (idx < 625 * 1024) {
                int x = (blockIdx_x * 256) + (threadIdx_x >> 2);
                int y = (blockIdx_x * 24) + (threadIdx_x % 50);

                float fx = ((float)x + 0.5f) * 6.4f - 0.5f;
                float fy = ((float)y + 0.5f) * 6.4f - 0.5f;

                int ix = (int)floorf(fx);
                int iy = (int)floorf(fy);

                ix = max(min(ix, 31), 0);
                iy = max(min(iy, 31), 0);

                float wx = fx - ix;
                float wy = fy - iy;

                float v1 = A[(x / 625) * 1024 + ix * 32 + iy] * (1.0f - wx) + A[(x / 625) * 1024 + (ix + 1) * 32 + iy] * wx;
                float v2 = A[(x / 625) * 1024 + ix * 32 + (iy + 1)] * (1.0f - wx) + A[(x / 625) * 1024 + (ix + 1) * 32 + (iy + 1)] * wx;

                resize[idx] = v1 * (1.0f - wy) + v2 * wy;
            }
        }
    }
}