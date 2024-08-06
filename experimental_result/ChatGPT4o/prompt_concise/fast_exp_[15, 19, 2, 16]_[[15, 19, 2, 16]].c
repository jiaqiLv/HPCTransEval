#include <math.h>
#include <stdio.h>

void default_function_kernel(float* __restrict__ T_fast_exp, float* __restrict__ data, int size) {
    for (int i = 0; i < size; i++) {
        float val = data[i];
        float clamped_val = fmaxf(fminf(val, 8.837627e+01f), -8.837626e+01f);
        float exp_val = clamped_val * 1.442695e+00f;
        int v_ = ((int)(floorf(exp_val + 5.000000e-01f)) + 1.270000e+02f) << 23;

        float mantissa = clamped_val - floorf(exp_val) * 6.931472e-01f;
        float result = (*(float *)&v_);
        result *= (((((((((((((1.987569e-04f * mantissa) + 1.398200e-03f) * mantissa) + 8.333452e-03f) * mantissa) + 4.166580e-02f) * mantissa) + 1.666667e-01f) * mantissa) + 5.000000e-01f) * mantissa) + 1.000000e+00f);

        T_fast_exp[i] = fmaxf(result, val);
    }
}

int main() {
    int size = 15 * 19 * 2 * 16;
    float data[size];
    float T_fast_exp[size];

    // Initialize data array with some values
    for (int i = 0; i < size; i++) {
        data[i] = (float)(i - (size / 2)); // Some sample initialization
    }

    default_function_kernel(T_fast_exp, data, size);

    // Print a few values for verification
    for (int i = 0; i < 10; i++) {
        printf("T_fast_exp[%d] = %f\n", i, T_fast_exp[i]);
    }

    return 0;
}

// |End-of-Code|
