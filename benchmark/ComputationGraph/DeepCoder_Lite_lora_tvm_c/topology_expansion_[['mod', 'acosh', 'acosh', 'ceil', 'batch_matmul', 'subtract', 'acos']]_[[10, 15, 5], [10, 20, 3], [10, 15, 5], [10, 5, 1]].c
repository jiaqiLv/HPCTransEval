#include <math.h>
#include <omp.h>

void default_function_kernel_4(float* __restrict__ compute, float* __restrict__ ph_0, float* __restrict__ ph_3, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        compute[i] = acosf(fmodf(ph_0[i], ph_3[i]));
    }
}

void default_function_kernel_3(float* __restrict__ T_subtract, float* __restrict__ ph_0, float* __restrict__ ph_3, int num_blocks) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks; ++i) {
        T_subtract[i] = fmodf(ph_0[i], ph_3[i]) - ph_0[i];
    }
}

void default_function_kernel_1(float* __restrict__ compute, float* __restrict__ ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        compute[i] = ceilf(acoshf(ph_0[i]));
    }
}

void default_function_kernel(float* __restrict__ compute, float* __restrict__ ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        compute[i] = acoshf(ph_0[i]);
    }
}

void default_function_kernel_2(float* __restrict__ T_batch_matmul_NN, float* __restrict__ ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        float T_batch_matmul_NN_local[32];
        for (int i_c_outer_inner_init = 0; i_c_outer_inner_init < 4; ++i_c_outer_inner_init) {
            for (int j_c_outer_inner_init = 0; j_c_outer_inner_init < 4; ++j_c_outer_inner_init) {
                for (int j_c_inner_init = 0; j_c_inner_init < 2; ++j_c_inner_init) {
                    T_batch_matmul_NN_local[(i_c_outer_inner_init * 8) + (j_c_outer_inner_init * 2) + j_c_inner_init] = 0.000000e+00f;
                }
            }
        }
        for (int k_outer_outer = 0; k_outer_outer < 2; ++k_outer_outer) {
            for (int i_c_outer_inner = 0; i_c_outer_inner < 4; ++i_c_outer_inner) {
                for (int j_c_outer_inner = 0; j_c_outer_inner < 4; ++j_c_outer_inner) {
                    for (int k_inner = 0; k_inner < 4; ++k_inner) {
                        for (int j_c_inner = 0; j_c_inner < 2; ++j_c_inner) {
                            T_batch_matmul_NN_local[(i_c_outer_inner * 8) + (j_c_outer_inner * 2) + j_c_inner] = (T_batch_matmul_NN_local[(i_c_outer_inner * 8) + (j_c_outer_inner * 2) + j_c_inner)] + (acoshf(ph_0[(blockIdx.x * 32) + threadIdx.x]) * ph_0[(blockIdx.x * 32) + threadIdx.x]));
                        }
                    }
                }
            }
        }
        for (int i_inner = 0; i_inner < 4; ++i_inner) {
            for (int j_inner = 0; j_inner < 8; ++j_inner) {
                T_batch_matmul_NN[(blockIdx.x * 32) + threadIdx.x + (i_inner * 8) + j_inner] = T_batch_matmul_NN_local[(i_inner * 8) + j_inner];
            }
        }
    }
}

void default_function_kernel(float* __restrict__ compute, float* __restrict__ ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        compute[i] = acoshf(ph_0[i]);
    }
}