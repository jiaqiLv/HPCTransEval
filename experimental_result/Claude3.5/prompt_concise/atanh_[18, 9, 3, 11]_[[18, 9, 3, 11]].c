#include <math.h>

void default_function_kernel_cpu(float* compute, float* data) {
    int dim0 = 18, dim1 = 9, dim2 = 3, dim3 = 11;
    
    for (int i = 0; i < dim0; i++) {
        for (int j = 0; j < dim1; j++) {
            for (int k = 0; k < dim2; k++) {
                for (int l = 0; l < dim3; l++) {
                    int index = (((i * dim1 + j) * dim2 + k) * dim3 + l);
                    compute[index] = atanhf(data[index]);
                }
            }
        }
    }
}

// |End-of-Code|