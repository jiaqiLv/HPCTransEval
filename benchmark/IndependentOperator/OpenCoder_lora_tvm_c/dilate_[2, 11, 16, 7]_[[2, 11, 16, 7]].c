void default_function_kernel(float* DilatedInput, float* data) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    #pragma omp parallel for collapse(=2)
    for (blockIdx_x=0; blockIdx_x < 2; blockIdx_x=0; blockIdx_x < 11; threadIdx_x++) {
        for ( blockIdx_x=0; blockIdx_x < 11; threadIdx_x++) {
            DilatedInput[((blockIdx_x * 11) + threadIdx_x=0; threadIdx_x < 11; threadIdx_x++) {
                DilatedInput[((blockIdx_x * 11) + threadIdx_x]) = data[((blockIdx_x * 11) + threadIdx_x]);
        }
}