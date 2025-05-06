void default_function_kernel(float* compute, float* data) {
    const int num_elements = 495;
    const int block_size = 8;

    // Initialize T_softmax_maxelem array
    float T_softmax_maxelem[num_elements];
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        T_softmax_maxelem[i] = -3.402823e+38f;
    }

    // Find the maximum element for each block
    #pragma omp parallel for collapse(2)
    for (int blockIdx = 0; blockIdx < num_elements / block_size; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < block_size; ++threadIdx) {
            int idx = (blockIdx * block_size) + threadIdx;
            if (idx < num_elements) {
                for (int k = 0; k < 4; ++k) {
                    int data_idx = (blockIdx * 32) + (threadIdx * 4) + k;
                    T_softmax_maxelem[idx] = fmaxf(T_softmax_maxelem[idx], data[data_idx]);
                }
            }
        }
    }

    // Compute the sum of exponentials
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        compute[i] = 0.0f;
        for (int k = 0; k < 4; ++k) {
            int data_idx = (i * 4) + k;
            compute[i] += expf(data[data_idx] - T_softmax_maxelem[i]);
        }
    }

    // Compute the final result
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        for (int j = 0; j < 4; ++j) {
            int idx = (i * 4) + j;
            compute[idx] = (data[idx] - T_softmax_maxelem[i]) - logf(compute[i]);
        }
    }
}