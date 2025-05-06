void default_function_kernel(float* T_cast, float* data, float* weight) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    int k1 = 0;
    #pragma omp parallel for private(threadIdx_x, k1)