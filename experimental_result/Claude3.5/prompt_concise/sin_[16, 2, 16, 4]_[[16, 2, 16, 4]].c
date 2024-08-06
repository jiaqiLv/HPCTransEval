#include <math.h>

void default_function_kernel_cpu(float* compute, float* data) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 16; k++) {
                for (int l = 0; l < 4; l++) {
                    int idx = i * 2 * 16 * 4 + j * 16 * 4 + k * 4 + l;
                    compute[i * 2 * 16 * 4 + j * 16 * 4 + k * 4 + l] = sinf(data[idx]);
                }
            }
        }
    }
}

// |End-of-Code|