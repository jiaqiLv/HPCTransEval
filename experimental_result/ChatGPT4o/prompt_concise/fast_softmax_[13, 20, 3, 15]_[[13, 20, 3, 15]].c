#include <math.h>
#include <stdio.h>

void default_function_kernel_1(float* __restrict__ T_softmax_expsum, float* __restrict__ T_softmax_maxelem, float* __restrict__ data, int size) {
    int num_elements = 195; // derived from the shape [[13, 20, 3, 15]]

    // Initialize T_softmax_expsum to 0
    for (int i = 0; i < size; i++) {
        if ((i / 8) < num_elements) {
            T_softmax_expsum[i] = 0.0f;
        }
    }

    // Calculate T_softmax_expsum
    for (int k = 0; k < 15; ++k) {
        for (int i = 0; i < size; i++) {
            if ((i / 8) < num_elements) {
                float val = data[(i * 15) + k] - T_softmax_maxelem[i];
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
}

void default_function_kernel_2(float* __restrict__ T_softmax_expsum, float* __restrict__ T_softmax_maxelem, float* __restrict__ T_softmax_norm, float* __restrict__ data, int size) {
    for (int i = 0; i < size; i++) {
        float val = data[i] - T_softmax_maxelem[i / 15];
        float clamped_val = fmaxf(fminf(val, 8.837627e+01f), -8.837626e+01f);
        float exp_val = clamped_val * 1.442695e+00f;
        int v_ = ((int)(floorf(exp_val + 5.000000e-01f)) + 1.270000e+02f) << 23;

        float mantissa = clamped_val - floorf(exp_val) * 6.931472e-01f;
        float result = (*(float *)&v_);
        result *= (((((((((((((1.987569e-04f * mantissa) + 1.398200e-03f) * mantissa) + 8.333452e-03f) * mantissa) + 4.166580e-02f) * mantissa) + 1.666667e-01f) * mantissa) + 5.000000e-01f) * mantissa) + 1.000000e+00f);

        T_softmax_norm[i] = fmaxf(result, val) / T_softmax_expsum[i / 15];
    }
}

void default_function_kernel(float* __restrict__ T_softmax_maxelem, float* __restrict__ data, int size) {
    int num_elements = 195; // derived from the shape [[13, 20, 3, 15]]

    // Initialize T_softmax_maxelem to a very small value
    for (int i = 0; i < size; i++) {
        if ((i / 16) < num_elements) {
            T_softmax_maxelem[i] = -3.402823e+38f;
        }
    }

    // Calculate T_softmax_maxelem
    for (int k = 0; k < 15; ++k) {
        for (int i = 0; i < size; i++) {
            if ((i / 16) < num_elements) {
                T_softmax_maxelem[i] = fmaxf(T_softmax_maxelem[i], data[(i * 15) + k]);
            }
        }
    }
}