#include <math.h>
#include <omp.h>

extern "C" void default_function_kernel(float* __restrict__ Im, float* __restrict__ Re, float* __restrict__ dft_cuda, float* __restrict__ dft_cuda_1, int num_blocks, int num_threads_per_block) {
    #pragma omp parallel for
    for (int blockIdx_x = 0; blockIdx_x < num_blocks; ++blockIdx_x) {
        for (int threadIdx_x = 0; threadIdx_x < num_threads_per_block; ++threadIdx_x) {
            if (((blockIdx_x * 64) + (threadIdx_x >> 4)) < 75) {
                for (int i = 0; i < 50; ++i) {
                    int idx = (((blockIdx_x * 51200) + (threadIdx_x * 50)) + i);
                    dft_cuda[idx] = 0.000000e+00f;
                    dft_cuda_1[idx] = 0.000000e+00f;
                    for (int j = 0; j < 50; ++j) {
                        float cse_var_1 = ((-6.283185e+00f * ((float)i)) * 2.000000e-02f) * ((float)j);
                        dft_cuda[idx] += (Re[((blockIdx_x * 51200) + (threadIdx_x * 50)) + j] * cosf(cse_var_1)) - (Im[((blockIdx_x * 51200) + (threadIdx_x * 50)) + j] * sinf(cse_var_1));
                        dft_cuda_1[idx] += (Re[((blockIdx_x * 51200) + (threadIdx_x * 50)) + j] * sinf(cse_var_1)) + (Im[((blockIdx_x * 51200) + (threadIdx_x * 50)) + j] * cosf(cse_var_1));
                    }
                }
            }
        }
    }
}