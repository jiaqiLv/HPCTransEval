#include <stdio.h>

void default_function_kernel_CPU(float* compute, float* data) {
    int blockId_x = 0; // Assuming blockIdx.x = 0 for simplicity
    int threadIdx_x = 0; // Assuming threadIdx.x = 0 for simplicity
    int tensor_shape[] = {4, 9, 6, 10};
    int index = ((blockId_x * 8) + threadIdx_x);

    // Flattening the 4D tensor to a 1D array
    int flattened_index = index;
    int stride = 1;
    for (int i = 3; i >= 0; i--) {
        flattened_index += stride * (index % tensor_shape[i]);
        stride *= tensor_shape[i];
        index /= tensor_shape[i];
    }

    compute[flattened_index] = data[flattened_index] * -1.0f;
}

// Print the single C code function implementation
default_function_kernel_CPU(compute, data);  // Function call

// |End-of-Code|