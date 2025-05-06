#include <stdio.h>

int main() {
    float ph_0[36] = {1.2, 2.3, 3.4, ..., 36.5);
    float compute[36] = {0};

    default_function_kernel(compute, ph_0);

    for (int i = 0; i < 36; i++) {
        printf("%f ", compute[i]);
    }
    printf("\n");

    return 0;
}