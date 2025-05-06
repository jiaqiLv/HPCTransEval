#include <math.h>
#include <omp.h>

void default_function_kernel_2(float* __restrict__ T_batch_matmul_NN, float* __restrict__ ph_0, float* __restrict__ ph_6) {
  #pragma omp parallel for
  for (int b_c_inner_init = 0; b_c_inner_init < 2; ++b_c_inner_init) {
    T_batch_matmul_NN[((int)blockIdx.x * 80 + (int)threadIdx.x)] = 0.000000e+00f;
  }
  for (int ax0_ax1_fused_ax2_fused_outer_outer = 0; ax0_ax1_fused_ax2_fused_outer_outer < 2; ++ax0_ax1_fused_ax2_fused_outer_outer) {
    if (((ax0_ax1_fused_ax2_fused_outer_outer * 4) + (((int)threadIdx.x) / 10)) < 5) {
      ph_6[((int)blockIdx.x * 50 + (ax0_ax1_fused_ax2_fused_outer_outer * 40) + ((int)threadIdx.x))] = ph_6[((int)blockIdx.x * 50 + (ax0_ax1_fused_ax2_fused_outer_outer * 40) + ((int)threadIdx.x))];
    }
  }
  __syncthreads();
  for (int k_inner = 0; k_inner < 5; ++k_inner) {
    for (int b_c_inner = 0; b_c_inner < 2; ++b_c_inner) {
      T_batch_matmul_NN[((int)blockIdx.x * 80 + (b_c_inner * 40) + ((int)threadIdx.x))] = (T_batch_matmul_NN[((int)blockIdx.x * 80 + (b_c_inner * 40) + ((int)threadIdx.x))] + (ph_0[((int)blockIdx.x * 80 + (b_c_inner * 40) + ((((int)threadIdx.x) / 5) * 5) + k_inner)] * ph_6[(((b_c_inner * 25) + (k_inner * 5)) + ((int)threadIdx.x) % 5)]));
    }
  }
}

void default_function_kernel(float* __restrict__ compute, float* __restrict__ ph_0) {
  #pragma omp parallel for
  for (int i = 0; i < 20 * 8 * 8; ++i) {
    compute[i] = asinhf(fmodf(ph_0[i], ceilf(ph_0[i])));
  }
}

void default_function_kernel_1(float* __restrict__ compute, float* __restrict__ ph_0) {
  #pragma omp parallel for
  for (int i = 0; i < 20 * 8 * 8; ++i) {
    compute[i] = atanf(ph_0[i]);
  }
}