void default_function_kernel(float* T_softmax_norm, float* data) {
    int num_blocks = 13; // Assuming num_blocks is known from the CUDA kernel code
    int num_threads_per_block = 32; // Assuming num_threads_per_block is known from the CUDA kernel code
    int num_elements_per_thread = 15; // Assuming num_elements_per_thread is known from the CUDA kernel code

    float max_elem = -3.402823e+38f;
    float expsum = 0.0f;

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        int idx = i * num_elements_per_thread;
        for (int k = 0; k < num_elements_per_thread; ++k) {
            float val = data[idx + k];
            if (val > max_elem) {
                max_elem = val;
            }
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < num_blocks * num_threads_per_block; ++i) {
        int idx = i * num_elements_per_thread;
        expsum = 0.0f;
        for (int k = 0; k < num_elements_per_thread; ++k) {
            float val = data[idx + k] - max_elem;
            float exp_val = exp(val);
            expsum += exp_val;
        }
        for (int k = 0; k < num_elements_per_thread; ++k) {
            float val = data[idx + k] - max_elem;
            T_softmax_norm[idx + k] = exp(val) / expsum;
        }
    }
}