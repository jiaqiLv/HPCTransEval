void default_function_kernel(float* T_reshape, float* ph) {
    int idx = (int)threadIdx.x;
    T_reshape[idx] = ph[idx];
}