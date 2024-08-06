#include <stdio.h>
#include <math.h>

void default_function_kernel_cpu(float* T_fast_tanh, float* data) {
    const int shape[4] = {18, 14, 2, 12};

    for (int i = 0; i < shape[0]; i++) {
        for (int j = 0; j < shape[1]; j++) {
            for (int k = 0; k < shape[2]; k++) {
                for (int l = 0; l < shape[3]; l++) {
                    int index = i * shape[1] * shape[2] * shape[3] + j * shape[2] * shape[3] + k * shape[3] + l;

                    float value = fmaxf(-9.0f, fminf(9.0f, data[index]));
                    float result = value * (value * (value * (value * (value * (value * (value * (value * -2.760768e-16f + 2.000188e-13f) - 8.604672e-11f) + 5.122297e-08f) + 1.485722e-05f) + 6.372619e-04f) + 4.893525e-03f) / (value * (value * (value * (value * (value * (value * 1.198258e-06f + 1.185347e-04f) + 2.268435e-03f) + 4.893525e-03f))));

                    T_fast_tanh[index] = result;
                }
            }
        }
    }
}

// |End-of-Code|