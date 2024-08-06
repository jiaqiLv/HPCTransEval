#include <math.h>

void default_function_cpu(float* compute, float* data) {
    int block_x = 4;
    int block_y = 4;
    int block_z = 15;
    int block_w = 19;
    int total_elements = block_x * block_y * block_z * block_w;

    for (int i = 0; i < total_elements; i++) {
        compute[i] = asinhf(data[i]);
    }
}

// |End-of-Code|