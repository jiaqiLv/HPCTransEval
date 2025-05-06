#include <omp.h>
#include <cmath>
#include <algorithm>
#include <iostream>

extern "C" void default_function_kernel(float* adaptive_pool_max, float* data, int num_elements) {
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        adaptive_pool_max[i] = -3.402823e+38f;
        for (int j = 0; j < 4; ++j) {
            adaptive_pool_max[i] = std::max(adaptive_pool_max[i], data[i * 4 + j]);
        }
    }
}