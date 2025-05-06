void default_function_kernel(float* T_transpose, float* ph, int num_blocks, int num_threads) {
    #pragma omp parallel for
    for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 2; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
        for (int i = 0; i < num_threads; ++i) {
            int idx = ((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (i / 32)) + (i % 32);
            if (idx < 43923) {
                T_transpose[idx] = ph[((((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 32768) + (i / 32)) + (i % 32)) % 11) * 31944) + ((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 65536) + (i / 32)) + (i % 32)) % 242) / 11) * 1452)) + ((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 32768) + (i / 32)) + (i % 32)) % 3993) / 121) * 44)) + ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (i / 32)) + (i % 32)) % 44))];
            }
        }
    }
}