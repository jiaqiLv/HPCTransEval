#include <omp.h>
#include <atomic>
#include <iostream>

void default_function_kernel_1(float* atomic_add_return, int* indices, float* scatter_nd_cuda, float* updates, int num_indices, int num_updates) {
    #pragma omp parallel for
    for (int i = 0; i < num_indices; ++i) {
        for (int j = 0; j < 1024; ++j) {
            for (int k = 0; k < 1560; ++k) {
                int index = (i * 1560) + j * 1024 + k;
                if (index < num_updates) {
                    atomic_add_return[0] = atomic_add(&(scatter_nd_cuda[index]), updates[index]);
                }
            }
        }
    }
}

void default_function_kernel(float* data, float* scatter_nd_cuda, int num_elements) {
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        scatter_nd_cuda[i] = data[i];
    }
}

int main() {
    // Example usage
    int num_elements = 2 * 1560; // Output shape: [2, 1560]
    float* data = new float[num_elements];
    float* scatter_nd_cuda = new float[num_elements];
    float* updates = new float[num_elements];
    int* indices = new int[2]; // Assuming indices are provided
    float* atomic_add_return = new float[1];

    // Initialize data, indices, updates, etc.

    // Call the functions
    default_function_kernel(data, scatter_nd_cuda, num_elements);
    default_function_kernel_1(atomic_add_return, indices, scatter_nd_cuda, updates, 2, num_elements);

    // Clean up
    delete[] data;
    delete[] scatter_nd_cuda;
    delete[] updates;
    delete[] indices;
    delete[] atomic_add_return;

    return 0;
}