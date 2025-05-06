void default_function_kernel(float* T_strided_slice, float* data) {
    int blockIdx_x = 0;
    int threadIdx_x = 0;
    int i, j, k, l, m, n;
    int data_dim0 = 15;
    int data_dim1 = 19;
    int data_dim2 = 2;
    int data_dim3 = 20;
    int T_strided_slice_dim0 = 3;
    int T_strided_slice_dim1 = 38;
    int T_strided_slice_dim2 = 4;
    int T_strided_slice_dim3 = 20;
    int data_strides[4] = {20, 20, 20, 20};
    int T_strided_slice_strides[4] = {80, 20, 20, 20};

    #pragma omp parallel for collapse(4)
    for (i = 0; i < data_dim0; i++) {
        for (j = 0; j < data_dim1; j++) {
            for (k = 0; k < data_dim2; k++) {
                for (l = 0; l < data_dim3; l++) {
                    blockIdx_x = i;
                    threadIdx_x = j * data_dim3 + k;
                    T_strided_slice[((((blockIdx_x * T_strided_slice_dim0) + (threadIdx_x >> 3)) % T_strided_slice_dim3) / 10) * T_strided_slice_strides[0] + ((((blockIdx_x * 6) + (threadIdx_x >> 2)) % 10) / 5) * T_strided_slice_strides[1] + (((blockIdx_x * 3) + (threadIdx_x >> 3)) / 20) * T_strided_slice_strides[2] + ((blockIdx_x * 3) + (threadIdx_x >> 3)) % 10 / 5) * T_strided_slice_strides[3] + (blockIdx_x * 4) + threadIdx_x) % T_strided_slice_dim3] = data[((blockIdx_x * data_dim0) + (j * data_dim3 + k)) % data_dim3];
                }
            }
        }
    }
}