void default_function_kernel(float* Scale, float* ScaleShift, float* Shift, float* data) {
    int total_elements = 10 * 13 * 18 * 19;
    
    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        int blockIdx_x = i / 32;
        int threadIdx_x = i % 32;
        
        if (((blockIdx_x * 8) + (threadIdx_x >> 2)) < 11115) {
            ScaleShift[i] = (data[i] * Scale[((blockIdx_x * 16 + (threadIdx_x >> 1)) % 2223) / 171]) + Shift[((blockIdx_x * 16 + (threadIdx_x >> 1)) % 2223) / 171];
        }
    }
}