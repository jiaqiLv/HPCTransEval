void default_function_kernel(float* data, float* pool_max) {
    // Initialize pool_max array with a very small number
    #pragma omp parallel for
    for (int i = 0; i < 11 * 3 * 6; i++) {
        pool_max[i] = -3.402823e+38f;
    }

    // Loop over the input data and update pool_max array
    #pragma omp parallel for collapse(2)
    for (int rv0 = 0; rv0 < 3; ++rv0) {
        for (int rv1 = 0; rv1 < 3; ++rv1) {
            #pragma omp critical
            {
                pool_max[((((int)blockIdx.x) * 6) + ((int)threadIdx.x))] = max(pool_max[((((int)blockIdx.x) * 6) + ((int)threadIdx.x))], (((1 <= (((((int)blockIdx.x) % 9) * 2) + rv0)) && (1 <= ((((int)threadIdx.x) * 2) + rv1))) ? data[(((((((int)blockIdx.x) * 24) + (rv0 * 12)) + (((int)threadIdx.x) * 2)) + rv1) - 13)] : -3.402823e+38f));
            }
        }
    }
}