#include <math.h>
#include <stdio.h>

float fast_tanh(float x) {
    float clamped_val = fmaxf(-9.000000e+00f, fminf(9.000000e+00f, x));
    float x2 = clamped_val * clamped_val;
    float x4 = x2 * x2;
    float x8 = x4 * x4;

    float numerator = clamped_val * (x2 * (x4 * (x8 * -2.760768e-16f + 2.000188e-13f) + -8.604672e-11f) + 5.122297e-08f) + 1.485722e-05f;
    numerator = numerator * x2 + 6.372619e-04f;
    numerator = numerator * x2 + 4.893525e-03f;

    float denominator = (x2 * (x4 * 1.198258e-06f + 1.185347e-04f) + 2.268435e-03f) + 4.893525e-03f;

    return numerator / denominator;
}

void default_function_kernel(float* __restrict__ T_fast_tanh, float* __restrict__ data, int size) {
    for (int i = 0; i < size; i++) {
        T_fast_tanh[i] = fast_tanh(data[i]);
    }
}

int main() {
    int size = 18 * 14 * 2 * 12;
    float data[size];
    float T_fast_tanh[size];

    // Initialize data array with some values
    for (int i = 0; i < size; i++) {
        data[i] = (float)(i - (size / 2)); // Some sample initialization
    }

    default_function_kernel(T_fast_tanh, data, size);

    // Print a few values for verification
    for (int i = 0; i < 10; i++) {
        printf("T_fast_tanh[%d] = %f\n", i, T_fast_tanh[i]);
    }

    return 0;
}

// |End-of-Code|
