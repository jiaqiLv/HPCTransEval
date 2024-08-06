#include <stdio.h>
#include <math.h>

void default_function_kernel_cpu(float* compute, float* data) {
    const int shape[4] = {3, 18, 11, 10};

    for (int i = 0; i < shape[0]; i++) {
        for (int j = 0; j < shape[1]; j++) {
            for (int k = 0; k < shape[2]; k++) {
                for (int l = 0; l < shape[3]; l++) {
                    int index = i * shape[1] * shape[2] * shape[3] + j * shape[2] * shape[3] + k * shape[3] + l;

                    compute[index] = floorf(data[index]);
                }
            }
        }
    }
}

// |End-of-Code|