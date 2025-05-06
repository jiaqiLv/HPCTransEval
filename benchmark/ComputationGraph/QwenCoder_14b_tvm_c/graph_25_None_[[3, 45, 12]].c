void default_function_kernel(float* compute, float* ph) {
    const int num_elements = 405 * 1024;
    
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        // First kernel: floor operation
        compute[i] = floorf(compute[i]);
        
        // Second kernel: assignment from ph array
        compute[i] = ph[((i % 3) * 540) + (i / 3)];
        
        // Third kernel: clamp operation
        compute[i] = fmaxf(fminf(compute[i], 1.111000e+01f), 1.100000e+00f);
    }
}