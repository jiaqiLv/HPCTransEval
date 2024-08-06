#include <stdio.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* __restrict__ compute, float* __restrict__ data, int num_elements) {
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        compute[i] = sqrtf(data[i]);
    }
}

int main() {
    int num_elements = 7 * 20 * 9 * 1;
    float compute[num_elements];
    float data[num_elements];

    // Initialize data (for example purposes)
    for (int i = 0; i < num_elements; ++i) {
        data[i] = (float)i;
    }

    // Call the function
    default_function_kernel(compute, data, num_elements);

    // Print results (for example purposes)
    for (int i = 0; i < num_elements; ++i) {
        printf("compute[%d] = %f\n", i, compute[i]);
    }

    return 0;
}

// |End-of-Code|
