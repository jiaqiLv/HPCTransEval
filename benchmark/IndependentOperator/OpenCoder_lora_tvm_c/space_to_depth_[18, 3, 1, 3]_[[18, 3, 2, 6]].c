void default_function_kernel(float* data, float* space_to_depth) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    for (blockIdx_x = 0; threadIdx_x < 1; blockIdx_x++) {
        for (threadIdx_x = 0; threadIdx_x < 8; threadIdx_x++) {
            i = ((blockIdx_x * 8) + threadIdx_x);