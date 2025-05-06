#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

void default_function_kernel(float* data, float* resize) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 40; ++j) {
            int blockIdx_x = i * 40 + j;
            for (int threadIdx_x = 0; threadIdx_x < 36; ++threadIdx_x) {
                resize[blockIdx_x * 36 + threadIdx_x] = data[((blockIdx_x / 40) * 360 + ((blockIdx_x % 40) / 2) * 18 + threadIdx_x / 2)];
            }
        }
    }
}
void bridge_call(void** void_args) {
    void* arg_0 = void_args[0];
    void* arg_1 = void_args[1];
    default_function_kernel(arg_0, arg_1);
}
