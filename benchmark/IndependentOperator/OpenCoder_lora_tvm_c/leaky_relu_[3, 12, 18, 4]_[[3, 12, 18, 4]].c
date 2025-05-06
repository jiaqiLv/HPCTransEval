void default_function_kernel(float* compute, float* data) {
    int blockIdx_x =  blockIdx_x= 0;
    int threadIdx_x = 0;
    #pragma omp parallel for collapse( blockIdx_x+ threadIdx_x < 96+ threadIdx_x){
        for blockIdx_x= (0.