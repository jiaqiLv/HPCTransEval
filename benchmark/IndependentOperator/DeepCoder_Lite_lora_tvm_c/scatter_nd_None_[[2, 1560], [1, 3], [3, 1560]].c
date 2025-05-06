#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void default_function_kernel_1(float* atomic_add_return, int* indices, float* scatter_nd_cuda, float* updates, int num_indices, int num_updates) {
    #pragma omp parallel for
    for (int i = 0; i < num_indices; ++i) {
        for (int j = 0; j < 1024; ++j) {
            int index = indices[i] * 1560 + j;
            if (index < num_updates) {
                atomic_add_return[0] = atomicAdd(&scatter_nd_cuda[index], updates[index]);
            }
        }
    }
}

void default_function_kernel(float* data, float* scatter_nd_cuda, int num_data) {
    #pragma omp parallel for
    for (int i = 0; i < num_data; ++i) {
        scatter_nd_cuda[i] = data[i];
    }
}

void default_function_kernel_2(float* data, float* scatter_nd_cuda, int num_data) {
    #pragma omp parallel for
    for (int i = 0; i < num_data; ++i) {
        scatter_nd_cuda[i] = data[i];
    }
}

void default_function_kernel(float* data, float* scatter_nd_cuda, int* indices, float* updates, int num_indices, int num_updates) {
    // First kernel to copy data to scatter_nd_cuda
    default_function_kernel(data, scatter_nd_cuda, num_data);

    // Second kernel to perform atomic add
    default_function_kernel_1(atomic_add_return, indices, scatter_nd_cuda, updates, num_indices, num_updates);
}