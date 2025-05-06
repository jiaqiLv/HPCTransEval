void default_function_kernel(float* T_transpose, float* ph, float* ph_1) {
    const int outer_loop_iterations = 2;
    const int block_size = 128;
    const int thread_size = 1024;
    const int total_elements = 43923;

    #pragma omp parallel for collapse(2)
    for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < outer_loop_iterations; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
        for (int blockIdx_x = 0; blockIdx_x < block_size; ++blockIdx_x) {
            for (int threadIdx_x = 0; threadIdx_x < thread_size; ++threadIdx_x) {
                int index = (ax0_ax1_fused_ax2_fused_ax3_fused_outer * 32768) + (blockIdx_x * 128) + (threadIdx_x >> 3);
                if (index < total_elements) {
                    int global_index = (ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (blockIdx_x * 1024) + threadIdx_x;

                    // Kernel 1
                    T_transpose[global_index] = ph[((((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 32768) + (blockIdx_x * 128) + (threadIdx_x >> 3)) % 11) * 31944) + ((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 32768) + (blockIdx_x * 128) + (threadIdx_x >> 3)) % 7986) / 363) * 1452)) + (((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 131072) + (blockIdx_x * 512) + (threadIdx_x >> 1)) / 3993) * 33)) + (((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (blockIdx_x * 1024) + threadIdx_x) % 363) / 11))];

                    // Kernel 2
                    T_transpose[global_index] = T_transpose[global_index] + ph_1[(((((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 32768) + (blockIdx_x * 128) + (threadIdx_x >> 3)) % 1331) / 121) * 31944) + (((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 32768) + (blockIdx_x * 128) + (threadIdx_x >> 3)) / 1331) * 968)) + (((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (blockIdx_x * 1024) + threadIdx_x) % 44) * 22)) + (((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 65536) + (blockIdx_x * 256) + (threadIdx_x >> 2)) % 242) / 11)))];

                    // Kernel 3
                    T_transpose[global_index] = T_transpose[global_index] + T_transpose_1[((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (blockIdx_x * 1024) + threadIdx_x)) % 968) * 363) + ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 32768) + (blockIdx_x * 128) + (threadIdx_x >> 3)) / 121)))];

                    // Kernel 4
                    T_transpose[global_index] = T_transpose[global_index] + T_transpose_1[((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (blockIdx_x * 1024) + threadIdx_x)) % 968) * 363) + ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 32768) + (blockIdx_x * 128) + (threadIdx_x >> 3)) / 121)))];

                    // Kernel 5
                    T_transpose[global_index] = T_transpose[global_index] + ph[((((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 32768) + (blockIdx_x * 128) + (threadIdx_x >> 3)) / 3993) * 31944) + ((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 65536) + (blockIdx_x * 256) + (threadIdx_x >> 2)) % 242) / 11) * 1452)) + ((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 32768) + (blockIdx_x * 128) + (threadIdx_x >> 3)) % 3993) / 121) * 44)) + ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (blockIdx_x * 1024) + threadIdx_x)) % 44)))];
                }
            }
        }
    }
}