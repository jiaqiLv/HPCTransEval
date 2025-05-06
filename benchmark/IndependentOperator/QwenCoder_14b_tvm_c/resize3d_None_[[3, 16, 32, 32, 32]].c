void default_function_kernel(float* A, float* resize) {
    #pragma omp parallel for collapse(3)
    for (int blockIdx_x = 0; blockIdx_x < 375; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            int idx = (blockIdx_x * 1024) + threadIdx_x;
            if (idx < 375 * 1024) {
                int x = blockIdx_x * 8 + (threadIdx_x >> 7);
                if (x < 375) {
                    int src_idx = (((blockIdx_x * 128) + (threadIdx_x >> 3)) / 125) * 32768;
                    int src_x = max(min(floorf(((blockIdx_x * 6 + (threadIdx_x >> 2)) % 250) / 25 + 0.5f) * 3.2f - 0.5f), 31);
                    int src_y = max(min(floorf(((blockIdx_x * 12 + (threadIdx_x >> 1)) % 50) / 5 + 0.5f) * 3.2f - 0.5f), 31);
                    int src_z = max(min(floorf(((blockIdx_x * 4 + threadIdx_x) % 10 + 0.5f) * 3.2f - 0.5f), 31);
                    float val1 = A[src_idx + (src_x * 1024) + (src_y * 32) + src_z];
                    float val2 = A[src_idx + (src_x * 1024) + (src_y * 32) + (src_z + 1)];
                    float val3 = A[src_idx + (src_x * 1024) + ((src_y + 1) * 32) + src_z];
                    float val4 = A[src_idx + (src_x * 1024) + ((src_y + 1) * 32) + (src_z + 1)];
                    float val5 = A[src_idx + ((src_x + 1) * 1024) + (src_y * 32) + src_z];
                    float val6 = A[src_idx + ((src_x + 1) * 1024) + (src_y * 32) + (src_z + 1)];
                    float val7 = A[src_idx + ((src_x + 1) * 1024) + ((src_y + 1) * 32) + src_z];
                    float val8 = A[src_idx + ((src_x + 1) * 1024) + ((src_y + 1) * 32) + (src_z + 1)];
                    float fx = ((blockIdx_x * 4 + threadIdx_x) % 10 + 0.5f) * 3.2f - 0.5f;
                    float fy = ((blockIdx_x * 12 + (threadIdx_x >> 1)) % 50) / 5 + 0.5f) * 3.2f - 0.5f;
                    float fz = ((blockIdx_x * 6 + (threadIdx_x >> 2)) % 250) / 25 + 0.5f) * 3.2f - 0.5f;
                    float wx = 1.0f - (fx - floorf(fx));
                    float wy = 1.0f - (fy - floorf(fy));
                    float wz = 1.0f - (fz - floorf(fz));
                    resize[idx] = val1 * wx * wy * wz + val2 * wx * wy * (1.0f - wz) + val3 * wx * (1.0f - wy) * wz + val4 * wx * (1.0f - wy) * (1.0f - wz) +
                                  val5 * (1.0f - wx) * wy * wz + val6 * (1.0f - wx) * wy * (1.0f - wz) + val7 * (1.0f - wx) * (1.0f - wy) * wz + val8 * (1.0f - wx) * (1.0f - wy) * (1.0f - wz);
                }
            }
        }
    }
}