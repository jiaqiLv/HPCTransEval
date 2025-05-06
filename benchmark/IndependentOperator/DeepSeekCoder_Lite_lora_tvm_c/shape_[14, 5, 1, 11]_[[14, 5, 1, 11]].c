void default_function_kernel(int32_t* T_shape) {
    #pragma omp parallel for
    for (int i = 0; i < 4; ++i) {
        switch (i) {
            case 3: T_shape[i] = 11; break;
            case 2: T_shape[i] = 1; break;
            case 1: T_shape[i] = 5; break;
            default: T_shape[i] = 14; break;
        }
    }
}