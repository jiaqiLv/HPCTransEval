void default_function_kernel(float* T_transpose, float* ph) {
    #pragma omp parallel for
    for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 2; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
        for (int ax0_ax1_fused_ax2_fused_ax3_fused_inner = 0; ax0_ax1_fused_ax2_fused_ax3_fused_inner < 1024; ++ax0_ax1_fused_ax2_fused_ax3_fused_inner) {
            if ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 32768) + (((int)blockIdx.x) * 128)) + (((int)threadIdx.x) >> 3)) < 43923) {
                int index = (((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x));
                T_transpose[index] = ph[((((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 32768) + (((int)blockIdx.x) * 128)) + (((int)threadIdx.x) >> 3)) / 3993) * 31944) + ((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 65536) + (((int)blockIdx.x) * 256)) + (((int)threadIdx.x) >> 2)) % 242) / 11) * 1452)) + ((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 32768) + (((int)blockIdx.x) * 128)) + (((int)threadIdx.x) >> 3)) % 3993) / 121) * 44)) + ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)blockIdx.x) * 1024)) + ((int)threadIdx.x)) % 44))];
            }
        }
    }
}