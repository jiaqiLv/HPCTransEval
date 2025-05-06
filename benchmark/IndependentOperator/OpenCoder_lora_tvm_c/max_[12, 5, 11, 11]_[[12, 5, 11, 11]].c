void default_function_kernel(float* data, float* data_red) {
    // Initialize data_red to the smallest possible float value
    *data_red = -FLT_MAX;

    // Parallelize the loop using OpenMP
    #pragma omp parallel for collapse(4)
    for (int k0 = 0; k0 < 12; ++k0) {
        for (int k1 = 0; k1 < 5; ++k1) {
            for (int k2 = 0; k2 < 11; ++k2) {
                for (int k3 = 0; k3 < 11; ++k3) {
                    // Update data_red with the maximum value found
                    *data_red = fmax(*data_red, data[((((k0 * 605) + (k1 * 121)) + (k2 * 11)) + k3)]);
                }
            }
        }
    }
}