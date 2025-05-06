void default_function_kernel(float* data, float* kernel, float* output_unpack) {
    int blockIdx_z = 0; // Assuming blockIdx.z is always 0 for simplicity
    int blockIdx_y = 0; // Assuming blockIdx.y is always 0 for simplicity
    int blockIdx_x = 0; // Assuming blockIdx.x is always 0 for simplicity
    int threadIdx_x = 0; // Assuming threadIdx.x is always 0 for simplicity
    int threadIdx_z = 0; // Assuming threadIdx.z is always 0 for simplicity

    float conv2d_nchw_local[8];
    #pragma omp parallel for
    for (int yy_c_init = 0; yy_c_init < 2; ++yy_c_init) {
        conv2d_nchw_local[yy_c_init] = 0.000000e+00f;
        conv2d_nchw_local[(yy_c_init + 2)] = 0.000000e+00f;
        conv2d_nchw_local[(yy_c_init + 4)] = 0.000000e+00f;
        conv2d_nchw_local[(yy_c_init + 6)] = 0.000000e+00f;
    }

    for (int rc_outer = 0; rc_outer < 16; ++rc_outer) {
        for (int ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner = 0; ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner < 2; ++ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner) {
            int idx = (((((((((blockIdx_z >> 1) * 2097152) + (rc_outer * 131072)) + (((threadIdx_z >> 2) * 65536) + (blockIdx_y * 512) + (((threadIdx_z & 3) * 256) + (blockIdx_x * 2) + (threadIdx_x * 2) + ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner))));
            int idx_pad_temp_shared = ((((threadIdx_z * 4) + (threadIdx_x * 2) + ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner));
            int idx_kernel_shared = (((((threadIdx_z * 18) + (rc_outer * 18) + ((ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner / 18) * 288) + (ax0_ax1_fused_ax2_fused_ax3_fused_inner_inner_inner % 18)));
            int idx_kernel_shared_1 = (idx_kernel_shared + 144);
            int idx_kernel_shared_2 = (idx_kernel_shared + 288);
            int idx_kernel_shared_3 = (idx_kernel_shared + 432);

            float pad_temp_shared = data[idx];
            float kernel_shared_0 = kernel[idx_kernel_shared];
            float kernel_shared_1 = kernel[(idx_kernel_shared + 144)];
            float kernel_shared_2 = kernel[(idx_kernel_shared + 288)];
            float kernel_shared_3 = kernel[(idx_kernel_shared + 432)];

            conv2d_nchw_local[0] += (pad_temp_shared * kernel_shared_0);
            conv2d_nchw_local[2] += (pad_temp_shared * kernel_shared_1);
            conv2d_nchw_local[4] += (pad_temp_shared * kernel_shared_2);
            conv2d_nchw_local[6] += (pad_temp_shared * kernel_shared_3);
        }
    }

    for (int yy_inner_inner_inner = 0; yy_inner_inner_inner < 2; ++yy_inner_inner_inner) {
        int idx_output = (((((((blockIdx_z * 2064512) + (threadIdx_z * 64516) + (blockIdx_y * 508) + (yy_inner_inner_inner * 254) + (blockIdx_x * 2) + threadIdx_x)));
        output_unpack[idx_output] = conv2d_nchw_local[yy_inner_inner_inner];
        output_unpack[(idx_output + 516128)] = conv2d_nchw_local[(yy_inner_inner_inner + 2)];
        output_unpack[(idx_output + 1032256)] = conv2d_nchw_local[(yy_inner_inner_inner + 4)];
        output_unpack[(idx_output + 1548384)] = conv2d_nchw_local[(yy_inner_inner_inner + 6)];
    }
}