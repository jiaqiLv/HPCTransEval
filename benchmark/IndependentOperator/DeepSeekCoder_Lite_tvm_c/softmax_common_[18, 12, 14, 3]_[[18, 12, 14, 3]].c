void default_function_kernel_1(float* T_softmax_expsum, float* T_softmax_maxelem, float* data) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < 189) {
        T_softmax_expsum[idx] = 0.000000e+00f;
    }
    for (int k = 0; k < 3; ++k) {
        int v_ = ((int)(floorf(((fmaxf(fminf((data[idx * 3 + k] - T_softmax_maxelem[idx]), 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f) << 23;
        T_softmax_expsum[idx] += (data[idx * 3 + k] - T_softmax_maxelem[idx]) / T_softmax_expsum[idx];
    }
}