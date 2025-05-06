void default_function_kernel(float* output_unpack, float* packed_out) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    #pragma omp parallel for collapse(2)
    for(blockIdx_x = 0; blockIdx_x < 3; blockIdx_x++){
        for(threadIdx_x = 0; threadIdx_x < 64; threadIdx_x++){
            output_unpack[((((int)blockIdx_x) * 64) + ((int)threadIdx_x))] = packed_out[(((((((int)blockIdx_x) / 3) * 192) + ((((((int)blockIdx_x) * 8) + (((int)threadIdx_x) >> 3)) % 12) * 16)) + ((((int)threadIdx_x) & 7) * 2)) + ((((((int)blockIdx_x) % 3) * 2) + (((int)threadIdx_x) >> 5)) / 3))];
        }
    }
}