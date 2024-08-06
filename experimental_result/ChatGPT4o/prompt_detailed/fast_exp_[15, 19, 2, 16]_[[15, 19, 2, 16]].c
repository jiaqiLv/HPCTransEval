#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

void default_function(float* T_fast_exp, float* data, int total_elements) {
    #pragma omp parallel for
    for (int i = 0; i < total_elements; i++) {
        float x = data[i];
        x = fmaxf(fminf(x, 8.837627e+01f), -8.837626e+01f);
        float v_ = ((int)(floorf(x * 1.442695e+00f + 5.000000e-01f) + 1.270000e+02f)) << 23;
        float base = *((float *)(&v_));
        float diff = x - floorf(x * 1.442695e+00f + 5.000000e-01f) * 6.931472e-01f;
        float result = base *
                       (((((((((((((1.987569e-04f * diff +
                                    1.398200e-03f) * diff +
                                    8.333452e-03f) * diff +
                                    4.166580e-02f) * diff +
                                    1.666667e-01f) * diff +
                                    5.000000e-01f) * diff +
                                    1.000000e+00f) * diff + 
                                    1.000000e+00f))));
        T_fast_exp[i] = fmaxf(result, x);
    }
}

int main() {
    int n = 15, c = 19, h = 2, w = 16;
    int total_elements = n * c * h * w; // Calculating the total number of elements in the tensor
    float* data = (float*)malloc(total_elements * sizeof(float));
    float* T_fast_exp = (float*)malloc(total_elements * sizeof(float));

    // Initialize data with some values for demonstration
    for (int i = 0; i < total_elements; i++) {
        data[i] = (float)rand() / (float)RAND_MAX * 20.0f - 10.0f; // Random values between -10 and 10
    }

    default_function(T_fast_exp, data, total_elements);

    // Optionally print the computed array
    for (int i = 0; i < total_elements; i++) {
        printf("%f ", T_fast_exp[i]);
    }
    printf("\n");

    free(data);
    free(T_fast_exp);

    return 0;
}

// |End-of-Code|
