#include <math.h>
#include <omp.h>

void default_function_kernel(float* T_divide, float* ph_0, float* ph_3, int num_blocks, int num_threads) {
    #pragma omp parallel for collapse(2) num_threads(num_threads)
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < num_threads; ++thread) {
            int idx = block * num_threads + thread;
            if (idx < 9) {
                T_divide[idx] = ph_0[idx] / ph_3[idx];
            }
        }
    }
}

void default_function_kernel_2(float* compute, float* ph_0, int num_blocks, int num_threads) {
    #pragma omp parallel for num_threads(num_threads)
    for (int block = 0; block < num_blocks; ++block) {
        int idx = block;
        compute[idx] = expf(ph_0[idx] - asinhf(ph_0[idx]));
    }
}

void default_function_kernel_1(float* compute, float* ph_0, int num_blocks, int num_threads) {
    #pragma omp parallel for collapse(2) num_threads(num_threads)
    for (int block = 0; block < num_blocks; ++block) {
        for (int thread = 0; thread < num_threads; ++thread) {
            int idx = block * num_threads + thread;
            if (idx < 9) {
                compute[idx] = fabsf(ph_0[idx] - asinhf(ph_0[idx]));
            }
        }
    }
}