void default_function_kernel_cpu(float* T_sign, float* data) {
    // Assuming that blockIdx.x and threadIdx.x are replaced with appropriate loop indices

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 13; k++) {
                for (int l = 0; l < 3; l++) {
                    int index = i * 2 * 13 * 3 + j * 13 * 3 + k * 3 + l;
                    T_sign[index] = (data[index] > 0.0f) ? 1.0f : ((data[index] < 0.0f) ? -1.0f : 0.0f);
                }
            }
        }
    }

} // |End-of-Code|