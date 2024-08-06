#include <stdio.h>
#include <math.h>

#define N 8
#define C 17
#define H 1
#define W 11
#define BLOCK_SIZE 17

void default_function_kernel(float* compute, float* data) {
    for (int n = 0; n < N; ++n) {
        for (int c = 0; c < C; ++c) {
            for (int h = 0; h < H; ++h) {
                for (int w = 0; w < W; ++w) {
                    int index = n * C * H * W + c * H * W + h * W + w;
                    compute[index] = acosf(data[index]);
                }
            }
        }
    }
}

// Call the function like this:
// default_function_kernel(compute, data);
// |End-of-Code|