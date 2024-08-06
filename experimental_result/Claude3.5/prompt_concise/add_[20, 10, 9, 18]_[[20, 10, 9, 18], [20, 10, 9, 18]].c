void default_function_cpu(float* T_add, float* data, float* data_1) {
    int block_x = 20;
    int block_y = 10;
    int block_z = 9;
    int block_w = 18;

    for (int i = 0; i < block_x; i++) {
        for (int j = 0; j < block_y; j++) {
            for (int k = 0; k < block_z; k++) {
                for (int l = 0; l < block_w; l++) {
                    int index = (((i * block_y + j) * block_z + k) * block_w + l);
                    T_add[index] = data[index] + data_1[index];
                }
            }
        }
    }
}

// End-of-Code