void default_function_kernel(float* Scale, float* ScaleShift, float* Shift, float* data) {
    int total_elements = 10 * 13 * 18 * 19;
    
    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        int channel = (i / (18 * 19)) % 13;
        ScaleShift[i] = (data[i] * Scale[channel]) + Shift[channel];
    }
}