#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

void default_function_kernel(float* T_broadcast_to, float* ph) {
    int i;
    #pragma omp parallel for private(i)
    for (i = 0; i < 640; i++) {
        T_broadcast_to[i] = (T_broadcast_to[i] < 0.0f) ? T_broadcast_to[i] : (T_broadcast_to[i] * ph[((i % 160) / 5)]);
    }
}