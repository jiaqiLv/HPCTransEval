void default_function_kernel(float* compute, float* ph, float* ph_1) {
    int num_threads = omp_get_max_threads();
    #pragma omp parallel for
    for (int i = 0; i < 10 * 10 * 10 * 10; ++i) {
        compute[i] = 0.000000e+00f;
    }

    #pragma omp parallel for
    for (int i = 0; i < 10 * 10 * 10 * 10; ++i) {
        compute[i] = -3.402823e+38f;
        for (int k = 0; k < 10; ++k) {
            int index = (((i / 10) * 100) + (k * 10)) + (i % 10);
            compute[i] = fmaxf(compute[i], ph[index]);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 10 * 10 * 10 * 10; ++i) {
        int idx = (((((((i / 1024) * 128) + ((i % 1024) / 4)) / 125) * 31944) + (((((((i / 1024) * 6) + ((i % 1024) / 4)) % 250) / 25) * 1452)) + (((((i / 1024) * 4) + (i % 1024)) % 10)) + 16973);
        if (idx < 625) {
            compute[i] = ph[idx];
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 10 * 10 * 10 * 10; ++i) {
        compute[i] = 0.000000e+00f;
        for (int k = 0; k < 10; ++k) {
            int index = (((i / 10) * 100) + (k * 10)) + (i % 10);
            compute[i] += expf(ph[index] - ph_1[i]);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 10 * 10 * 10 * 10; ++i) {
        int idx = (((((i / 1024) * 1024) + (i % 1024)) / 10) * 10) + (i % 10);
        if (idx < 625) {
            compute[i] = ph[idx] - logf(compute[i]);
        }
    }

    #pragma omp parallel for
    for (int i = 0; i < 10 * 10 * 10 * 10; ++i) {
        int idx = (((((i / 1024) * 1024) + (i % 1024)) / 10) * 10) + (i % 10);
        if (idx < 625) {
            compute[i] = ph[idx] + ph_1[idx];
        }
    }
}