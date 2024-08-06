#include <stdio.h>

void default_function_kernel_CPU(float* Scale, float* compute, float* data) {
    int blockId_x = 0; // Assuming blockIdx.x = 0 for simplicity
    int threadIdx_x = 0; // Assuming threadIdx.x = 0 for simplicity
    int tensor_shape[] = {9, 17, 16, 19};
    int scale_shape[] = {19};
    int index = ((blockId_x * 38) + threadIdx_x);

    // Flattening the 4D tensor to a 1D array
    int flattened_index = index;
    int stride = 1;
    for (int i = 3; i >= 0; i--) {
        flattened_index += stride * (index % tensor_shape[i]);
        stride *= tensor_shape[i];
        index /= tensor_shape[i];
    }

    // Adjusting for Scale array
    int scale_index = threadIdx_x % scale_shape[0];

    // Performing the computation
    float value = data[flattened_index];
    compute[flattened_index] = (value < 0.0f) ? value : (value * Scale[scale_index]);
}

// Print the single C code function implementation
default_function_kernel_CPU(Scale, compute, data);  // Function call

// |End-of-Code|