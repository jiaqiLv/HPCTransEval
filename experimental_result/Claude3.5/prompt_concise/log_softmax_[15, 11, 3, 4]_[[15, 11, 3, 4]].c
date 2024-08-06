#include <math.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

void default_function_kernel_1(float* T_softmax_maxelem, float* compute, float* data) {
    for (int blockIdx_x = 0; blockIdx_x < 15; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 11; threadIdx_x++) {
            if ((blockIdx_x * 2 + threadIdx_x) < 495) {
                compute[blockIdx_x * 2 + threadIdx_x] = 0.0f;
            }
            for (int k = 0; k < 4; ++k) {
                if ((blockIdx_x * 2 + threadIdx_x) < 495) {
                    compute[blockIdx_x * 2 + threadIdx_x] += expf(data[((blockIdx_x * 8 + threadIdx_x * 4) + k)] - T_softmax_maxelem[blockIdx_x * 2 + threadIdx_x]);
                }
            }
        }
    }
} 

void default_function_kernel_2(float* T_softmax_maxelem, float* compute, float* compute_1, float* data) {
    for (int blockIdx_x = 0; blockIdx_x < 15; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 11; threadIdx_x++) {
            if ((blockIdx_x * 8 + (threadIdx_x >> 2)) < 495) {
                compute[blockIdx_x * 32 + threadIdx_x] = (data[blockIdx_x * 32 + threadIdx_x] - T_softmax_maxelem[blockIdx_x * 8 + (threadIdx_x >> 2)] - logf(compute_1[blockIdx_x * 8 + (threadIdx_x >> 2)]));
            }
        }
    }
}

void default_function_kernel(float* T_softmax_maxelem, float* data) {
    for (int blockIdx_x = 0; blockIdx_x < 15; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 11; threadIdx_x++) {
            if ((blockIdx_x * 8 + threadIdx_x) < 495) {
                T_softmax_maxelem[blockIdx_x * 8 + threadIdx_x] = -3.402823e+38f;
            }
            for (int k = 0; k < 4; ++k) {
                if ((blockIdx_x * 8 + threadIdx_x) < 495) {
                    T_softmax_maxelem[blockIdx_x * 8 + threadIdx_x] = max(T_softmax_maxelem[blockIdx_x * 8 + threadIdx_x], data[((blockIdx_x * 32 + threadIdx_x * 4) + k)]);
                }
            }
        }
    }
}

// |End-of-Code|