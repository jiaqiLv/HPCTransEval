#include <math.h>

void default_function_cpu(float* compute, float* data) {
    int block_x = 9;
    int block_y = 11;
    int block_z = 11;
    int block_w = 7;
    int total_elements = block_x * block_y * block_z * block_w;
    
    for (int i = 0; i < total_elements; i++) {
        if (i < 7623) {
            compute[i] = asinf(data[i]);
        }
    }
}

// |End-of-Code|