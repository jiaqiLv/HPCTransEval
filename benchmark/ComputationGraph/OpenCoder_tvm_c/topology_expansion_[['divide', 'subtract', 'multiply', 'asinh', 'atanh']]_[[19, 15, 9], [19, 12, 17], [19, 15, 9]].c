#include <stdio.h>

int main() {
    float ph_0[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    float ph_3[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1);
    float T_divide[9];
    float compute[9];

    default_function_kernel(T_divide, ph_0, ph_3, 9);
    default_function_kernel_1(compute, ph_0, ph_3, 9);
    default_function_kernel_2(compute, ph_0, ph_3, 9);
}