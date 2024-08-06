#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

void default_function(float* T_fast_tanh, float* data, int total_elements) {
    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        float x = fmaxf(-9.000000e+00f, fminf(9.000000e+00f, data[i]));
        float x2 = x * x;
        float x4 = x2 * x2;
        float x8 = x4 * x4;

        float numerator = ((((((((x * x2 * x4 * x8 * -2.760768e-16f) + 2.000188e-13f) * x2 * x4 * x8) + -8.604672e-11f) * x2 * x4) + 5.122297e-08f) * x2) + 1.485722e-05f) * x2 + 6.372619e-04f) * x2 + 4.893525e-03f;

        float denominator = (((((x2 * x4 * x8 * 1.198258e-06f) + 1.185347e-04f) * x2 * x4) + 2.268435e-03f) * x2 + 4.893525e-03f);

        T_fast_tanh[i] = numerator / denominator;
    }
}

int main() {
    int n = 18, c = 14, h = 2, w = 12;
    int total_elements = n * c * h * w; // Calculating the total number of elements in the tensor
    float* data = (float*)malloc(total_elements * sizeof(float));
    float* T_fast_tanh = (float*)malloc(total_elements * sizeof(float));

    // Initialize data with some values for demonstration
    for (int i = 0; i < total_elements; i++) {
        data[i] = (float)rand() / (float)RAND_MAX * 18.0f - 9.0f; // Random values between -9 and 9
    }

    default_function(T_fast_tanh, data, total_elements);

    // Optionally print the computed array
    for (int i = 0; i < total_elements; i++) {
        printf("%f ", T_fast_tanh[i]);
    }
    printf("\n");

    free(data);
    free(T_fast_tanh);

    return 0;
}

// |End-of-Code|
