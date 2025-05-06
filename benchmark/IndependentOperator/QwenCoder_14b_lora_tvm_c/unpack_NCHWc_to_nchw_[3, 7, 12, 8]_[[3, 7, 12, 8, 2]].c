void default_function_kernel(float* output_unpack, float* packed_out) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 3; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 64; threadIdx_x++) {
            int output_index = (blockIdx_x * 64) + threadIdx_x;
            int packed_index = (((blockIdx_x / 3) * 192) + (((blockIdx_x * 8) + (threadIdx_x >> 3)) % 12) * 16) + ((threadIdx_x & 7) * 2) + (((blockIdx_x % 3) * 2) + (threadIdx_x >> 5)) / 3;
            output_unpack[output_index] = packed_out[packed_index];
        }
    }
}