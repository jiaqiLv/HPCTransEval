void default_function_kernel_cpu(float* data, float* data_red) {
    data_red[0] = 1.000000e+00f;
    for (int k0 = 0; k0 < 15; ++k0) {
        for (int k1 = 0; k1 < 20; ++k1) {
            for (int k2 = 0; k2 < 3; ++k2) {
                for (int k3 = 0; k3 < 7; ++k3) {
                    data_red[0] *= data[((k0 * 20 * 3 * 7) + (k1 * 3 * 7) + (k2 * 7) + k3)];
                }
            }
        }
    }
}