#include <math.h>
#include <stdio.h>
#include <float.h>

void default_function_kernel_1(float* __restrict__ T_softmax_maxelem, float* __restrict__ data, int size) {
    int limit = 189; // Derived from the shape and the condition in the CUDA kernel
    for (int i = 0; i < size; i++) {
        if ((i / 16) < limit) {
            T_softmax_maxelem[i] = -FLT_MAX;
        }
    }

    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < size; i++) {
            if ((i / 16) < limit) {
                int index = (i * 3) + k;
                T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], data[index]);
            }
        }
    }
}

void default_function_kernel_2(float* __restrict__ T_softmax_expsum, float* __restrict__ T_softmax_maxelem, float* __restrict__ T_softmax_norm, float* __restrict__ data, int size) {
    int limit = 567; // Derived from the shape and the condition in the CUDA kernel

    for (int i = 0; i < size; i++) {
        if ((i / 16) < limit) {
            float val = data[i] - T_softmax_maxelem[i / 3];
            float clamped_val = fmaxf(fminf(val, 8.837627e+01f), -8.837626e+01f);
            float exp_val = clamped_val * 1.442695e+00f;
            int v_ = ((int)(floorf(exp_val + 5.000000e-01f)) + 1.270000e+02f) << 23;

            float mantissa = clamped_val - floorf(exp_val) * 6.931472e-01f;
            float result = (*(float *)&v_);
            result *= (((((((((((((1.987569e-04f * mantissa) + 1.398200e-03f) * mantissa) + 8.333452e-03f) * mantissa) + 4.166580e-02f) * mantissa) + 1.666667e-01f) * mantissa) + 5.000000e-01f) * mantissa) + 1.000000e+00f);

            T_softmax_norm[i] = fmaxf(result, val) / T_softmax_expsum[i / 3];
        }
    }
}

void default_function_kernel_3(float* __restrict__ T_softmax_expsum, float* __restrict__ T_softmax_maxelem, float* __restrict__ data, int size) {
    for (int i = 0; i < size; i++) {
        T_softmax_expsum[i] = 0.0f;
    }

    for (int k = 0; k < 3; ++k) {
        for (int i = 0; i < size; i++) {
            float val = data[(i * 3) + k] - T_softmax_maxelem[i];
            float clamped_val = fmaxf(fminf(val, 8.837627e+01f), -8.837626e+01f);
            float exp_val = clamped_val * 1.442695e+00f;
            int v_ = ((int)(floorf(exp_val + 5.000000e-01f)) + 1.270000e+02f) << 23;

            float mantissa = clamped_val - floorf(exp_val) * 6.931472e-01f;
            float result = (*(float *)&v_);
            result *= (((((((((((((1.987569e-04f * mantissa) + 1.398200e-03f) * mantissa) + 8.333452e-03f) * mantissa) + 4.166580e-02f) * mantissa) + 1.666667e-01f) * mantissa) + 5.000000e-01f) * mantissa) + 1.000000e+00f);

            T_softmax_expsum[i] += fmaxf(result, val);
        }
    }
}

int main() {
    int size = 18 * 12 * 14 * 3;
    float data[size];
    float T_softmax_maxelem[size];
    float T_softmax_expsum[size];
    float T_softmax_norm[size];

    // Initialize data array with some values
    for (int i = 0; i < size; i++) {
        data[i] = (float)(i % 10); // Some sample initialization
    }

    default_function_kernel_1(T_softmax_maxelem, data, size);
    default_function_kernel_3(T_softmax_expsum, T_softmax_maxelem, data, size);
    default_function_kernel_2(T_softmax_expsum, T_softmax_maxelem, T_softmax_norm, data, size);

    // Print a few values for verification
    for (int i = 0; i < 10; i++) {
        printf("T_softmax_norm[%d] = %f\n", i, T_softmax_norm[i]);
    }

    return 0;
}

// |End-of-Code|
