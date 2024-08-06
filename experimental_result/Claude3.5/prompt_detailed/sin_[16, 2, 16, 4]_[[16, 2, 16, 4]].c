#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* data) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 16; k++) {
                for (int l = 0; l < 4; l++) {
                    int blockIdx_x = i * 2 * 16 + j * 16 + k;
                    int threadIdx_x = l;
                    compute[blockIdx_x * 4 + threadIdx_x] = sinf(data[blockIdx_x * 4 + threadIdx_x]);
                }
            }
        }
    }
}
