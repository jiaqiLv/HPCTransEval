void default_function_kernel(float* data, float* data_red) {
    // Initialize data_red to 1.0
    *data_red = 1.0f;

    // Parallelize the loop using OpenMP
    #pragma omp parallel for collapse(4)
    for (int k0 = 0; k0 < 15; ++k0) {
        for (int k1 = 0; k1 < 20; ++k1) {
            for (int k2 = 0; k2 < 3; ++k2) {
                for (int k3 = 0; k3 < 7; ++k3) {
                    // Multiply the current value of data_red by the corresponding element in data
                    *data_red *= data[((((k0 * 420) + (k1 * 21)) + (k2 * 7)) + k3)];
                }
            }
        }
    }
}