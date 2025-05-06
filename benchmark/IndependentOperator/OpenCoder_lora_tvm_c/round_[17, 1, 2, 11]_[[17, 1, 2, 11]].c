void default_function_kernel(float* compute, float* data) {
    int i;
 {
        #pragma omp parallel for
        for (i = 0; i = 0; {
            compute[i] = data[i];
    }
}