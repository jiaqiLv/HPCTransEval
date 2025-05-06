void default_function_kernel(float* compute, data) {
        #pragma omp parallel for private(threadIdx_x) {
        }