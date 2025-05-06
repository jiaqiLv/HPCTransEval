void default_function_kernel(int32_t* T_shape) {
    // Define the expected values based on threadIdx.x
    int expected_values[4] = {14, 5, 1, 11};

    // Ensure the output array has the correct size
    if (sizeof(T_shape) / sizeof(T_shape[0]) != 4) {
        return;
    }

    // Parallelize the assignment based on threadIdx.x
    #pragma omp parallel for
    for (int i = 0; i < 4; ++i) {
        T_shape[i] = expected_values[i];
    }
}