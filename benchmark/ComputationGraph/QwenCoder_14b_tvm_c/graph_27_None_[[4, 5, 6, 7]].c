void default_function_kernel(float* T_transpose, float* ph) {
    // Assuming the size of T_transpose and ph is known and is 840
    const int size = 840;

    #pragma omp parallel for
    for (int i = 0; i < size; ++i) {
        // Kernel 1: Clamp values between 11.11 and 99.99
        T_transpose[i] = fmaxf(fminf(ph[i], 99.99f), 11.11f);

        // Kernel 2: Complex transformation
        float value = fmaxf(fminf(T_transpose[i], 88.37627f), -88.37626f);
        int v_ = ((int)(floorf(value * 1.442695f + 0.5f)) + 127) << 23;
        float transformed_value = (*(float*)&v_) * (
            1.987569e-04f * (value - floorf(value * 1.442695f + 0.5f) * 0.6931472f) +
            1.398200e-03f * (value - floorf(value * 1.442695f + 0.5f) * 0.6931472f) +
            8.333452e-03f * (value - floorf(value * 1.442695f + 0.5f) * 0.6931472f) +
            4.166580e-02f * (value - floorf(value * 1.442695f + 0.5f) * 0.6931472f) +
            1.666667e-01f * (value - floorf(value * 1.442695f + 0.5f) * 0.6931472f) +
            5.000000e-01f * (value - floorf(value * 1.442695f + 0.5f) * 0.6931472f) *
            (value - floorf(value * 1.442695f + 0.5f) * 0.6931472f) +
            (value - floorf(value * 1.442695f + 0.5f) * 0.6931472f) + 1.0f
        );
        T_transpose[i] = fmaxf(transformed_value, T_transpose[i]);

        // Kernel 3: Transpose operation
        T_transpose[i] = ph[i];
    }
}