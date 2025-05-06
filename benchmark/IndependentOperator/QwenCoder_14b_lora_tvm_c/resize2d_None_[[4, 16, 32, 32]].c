void default_function_kernel(float* A, float* resize) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 625; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            int idx = (blockIdx_x * 1024) + threadIdx_x;
            if (idx < 625 * 1024) {
                int x = (blockIdx_x * 256 + (threadIdx_x >> 2)) / 625;
                int y = (blockIdx_x * 256 + (threadIdx_x >> 2)) % 625;

                float fx = ((float)(x * 50 + 25) * 6.4f - 5.0f);
                float fy = ((float)(y * 50 + 25) * 6.4f - 5.0f);

                int ix = (int)floorf(fx);
                int iy = (int)floorf(fy);

                ix = ix < 0 ? 0 : (ix > 31 ? 31 : ix);
                iy = iy < 0 ? 0 : (iy > 31 ? 31 : iy);

                float wx = fx - ix;
                float wy = fy - iy;

                float v1 = A[(x * 32 + ix) * 32 + iy] * (1.0f - wx) + A[(x * 32 + ix + 1) * 32 + iy] * wx;
                float v2 = A[(x * 32 + ix) * 32 + iy + 1] * (1.0f - wx) + A[(x * 32 + ix + 1) * 32 + iy + 1] * wx;

                resize[idx] = v1 * (1.0f - wy) + v2 * wy;
            }
        }
    }
}