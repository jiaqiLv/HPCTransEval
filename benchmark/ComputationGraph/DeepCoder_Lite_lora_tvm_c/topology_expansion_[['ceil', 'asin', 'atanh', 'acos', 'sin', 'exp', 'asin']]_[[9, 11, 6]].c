#include <math.h>
#include <omp.h>

void default_function_kernel_1(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        compute[i] = tanhf(asinhf(ph_0[i]));
    }
}

void default_function_kernel(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        if (i < 9 * num_blocks * threads_per_block) {
            compute[i] = ceilf(ph_0[i]);
        }
    }
}

void default_function_kernel_3(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        if (i < 9 * num_blocks * threads_per_block) {
            compute[i] = expf(sinf(ph_0[i]));
        }
    }
}

void default_function_kernel_4(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        if (i < 9 * num_blocks * threads_per_block) {
            compute[i] = asinf(sinf(ph_0[i]));
        }
    }
}

void default_function_kernel_2(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    #pragma omp parallel for
    for (int i = 0; i < num_blocks * threads_per_block; ++i) {
        if (i < 9 * num_blocks * threads_per_block) {
            compute[i] = acosf(ph_0[i]);
        }
    }
}

void default_function_kernel(float* compute, float* ph_0, int num_blocks, int threads_per_block) {
    // Combine all the kernels into one function
    default_function_kernel_1(compute, ph_0, num_blocks, threads_per_block);
    default_function_kernel(compute, ph_0, num_blocks, threads_per_block);
    default_function_kernel_3(compute, ph_0, num_blocks, threads_per_block);
    default_function_kernel_4(compute, ph_0, num_blocks, threads_per_block);
    default_function_kernel_2(compute, ph_0, num_blocks, threads_per_block);
}