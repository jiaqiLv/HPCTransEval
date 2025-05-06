void default_function_kernel(float* T_fast_tanh, float* ph, float* ph_1) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < 625) {
        T_fast_tanh[idx] = fminf(fmaxf(ph[idx], -9.0f), 9.0f);
    }
}