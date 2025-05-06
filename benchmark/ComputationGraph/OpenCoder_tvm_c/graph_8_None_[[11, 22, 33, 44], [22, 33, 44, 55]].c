void default_function_kernel(float* compute, float* ph, float* ph_1) {
    // Initialize compute array with large negative number
    #pragma omp parallel for
    for (int i = 0; i < 1024; ++i) {
        compute[i] = -3.402823e+38f;
    }

    // Perform max operation on compute array
    #pragma omp parallel for
    for (int i = 0; i < 10; ++i) {
        compute[i] = max(compute[i], ph[i]);
    }

    // Perform computation on compute array
    #pragma omp parallel for
    for (int i = 0; i < 10; ++i) {
        compute[i] = exp(compute[i] - ph_1[i]);
    }

    // Perform computation on compute array
    #pragma omp parallel for
    for (int i = 0; i < 10; ++i) {
        compute[i] = (compute[i] + log(compute[i]));
    }

    // Perform computation on compute array
    #pragma omp parallel for
    for (int i = 0; i < 10; ++i) {
        compute[i] = (compute[i] + ph[i]);
    }
}