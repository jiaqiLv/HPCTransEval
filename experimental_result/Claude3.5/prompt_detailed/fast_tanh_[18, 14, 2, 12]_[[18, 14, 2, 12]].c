#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define BLOCK_SIZE 18
#define GRID_SIZE_X 14
#define GRID_SIZE_Y 2
#define GRID_SIZE_Z 12

void default_function_kernel(float* T_fast_tanh, float* data) {
    #pragma omp parallel for collapse(3)
    for (int i = 0; i < GRID_SIZE_X; i++) {
        for (int j = 0; j < GRID_SIZE_Y; j++) {
            for (int k = 0; k < GRID_SIZE_Z; k++) {
                for (int l = 0; l < BLOCK_SIZE; l++) {
                    int idx = ((((i * GRID_SIZE_Y + j) * GRID_SIZE_Z + k) * BLOCK_SIZE + l));
                    float val = data[idx];
                    float temp = fminf(9.0f, fmaxf(-9.0f, val));
                    T_fast_tanh[idx] = temp * (temp * (temp * (temp * (temp * (temp * (temp * (temp * (temp * (temp * (temp * (temp * (temp * -2.760768e-16f + 2.000188e-13f) - 8.604672e-11f) + 5.122297e-08f) + 1.485722e-05f) + 6.372619e-04f) + 4.893525e-03f) / (temp * (temp * (temp * (temp * (temp * (temp * (temp * (temp * (temp * (1.198258e-06f + 1.185347e-04f) + 2.268435e-03f) + 4.893525e-03f)))))))))));
                }
            }
        }
    }
}

int main() {
    float* T_fast_tanh = (float*)malloc(sizeof(float) * 18 * 14 * 2 * 12);
    float* data = (float*)malloc(sizeof(float) * 18 * 14 * 2 * 12);

    // Fill data with values

    default_function_kernel(T_fast_tanh, data);

    // Print or use T_fast_tanh

    free(T_fast_tanh);
    free(data);

    return 0;
}
