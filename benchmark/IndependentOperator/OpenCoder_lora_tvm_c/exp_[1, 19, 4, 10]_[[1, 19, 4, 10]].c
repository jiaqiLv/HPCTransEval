void default_function_kernel(float* compute, float* data) {
    int blockIdx_x = 0;
    #pragma omp parallel for collapse(= exp(data[((blockIdx_x * 20) + (threadIdx_x))];
    }