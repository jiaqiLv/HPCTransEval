#include <omp.h>
#include <stdio.h>

void default_function_kernel(int* T_shape) {
    // Define the values for each thread index
    int thread_values[] = {14, 5, 1, 11};

    // Number of threads (in this case, 4)
    int num_threads = 4;

    // Use OpenMP to parallelize the loop
    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        T_shape[i] = thread_values[i];
    }
}