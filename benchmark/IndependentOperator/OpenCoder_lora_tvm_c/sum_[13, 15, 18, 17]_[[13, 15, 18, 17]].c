void default_function_kernel(float* data, float* data_red) {
    // Initialize the reduction variable to zero
    float reduction = 0.0f;

    // Use OpenMP to parallelize the reduction operation
    #pragma omp parallel for reduction(+:reduction)
    for (int i = 0; i < 29835; ++i) {
        reduction += data[i];
    }

    // Store the result in the output array
    data_red[0] = reduction;
}