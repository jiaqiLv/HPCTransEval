#include <omp.h>
#include <math.h>
#include <float.h>

void default_function_kernel(float* __restrict__ pad_temp, float* __restrict__ ph) {
    #pragma omp parallel for
    for (int ax0_ax1_fused_ax2_fused_ax3_fused_outer = 0; ax0_ax1_fused_ax2_fused_ax3_fused_outer < 13; ++ax0_ax1_fused_ax2_fused_ax3_fused_outer) {
        if ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 1024) + (((int)omp_get_thread_num()) * 4)) + (((int)omp_get_thread_num()) >> 8)) < 12675) {
            pad_temp[(((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)omp_get_thread_num()) * 1024)) + ((int)omp_get_thread_num()))] = (((((195 <= (((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 2048) + (((int)omp_get_thread_num()) * 8)) + (((int)omp_get_thread_num()) >> 7))) && ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 2048) + (((int)omp_get_thread_num()) * 8)) + (((int)omp_get_thread_num()) >> 7)) < 25155)) && (3 <= ((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 4096) + (((int)omp_get_thread_num()) * 16)) + (((int)omp_get_thread_num()) >> 6)) % 390))) && (((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)omp_get_thread_num()) * 1024)) + ((int)omp_get_thread_num())) % 24960) < 24768)) ? ph[(((((((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 2048) + (((int)omp_get_thread_num()) * 8)) + (((int)omp_get_thread_num()) >> 7)) / 195) * 24576) + (((ax0_ax1_fused_ax2_fused_ax3_fused_outer * 262144) + (((int)omp_get_thread_num()) * 1024)) + ((int)omp_get_thread_num())) % 24960)) - 24768)] : -3.402823e+38f);
        }
    }
}