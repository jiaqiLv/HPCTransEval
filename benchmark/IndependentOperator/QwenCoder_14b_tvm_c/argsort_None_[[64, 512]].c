#include <iostream>
#include <vector>
#include <algorithm>
#include <omp.h>

void default_function_kernel(float* argsort_gpu, float* argsort_gpu_v0, const float* data, int num_elements) {
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        argsort_gpu_v0[i] = data[i];
        argsort_gpu[i] = static_cast<float>(i);
    }
}

void default_function_kernel_1(float* argsort_gpu, float* argsort_gpu_v0, float* argsort_gpu_v2, float* argsort_gpu_v3, int num_elements) {
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        argsort_gpu_v2[i] = argsort_gpu_v0[i];
        argsort_gpu_v3[i] = argsort_gpu[i];
    }
}

void default_function_kernel_2(float* argsort_gpu, float* argsort_gpu_v0, float* argsort_gpu_v2, float* argsort_gpu_v3, int cse_var_1, int i_0, int num_elements) {
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        int64_t first = std::max(0LL, i);
        int64_t last = std::min(i + (1LL << cse_var_1), 512LL);
        while (first < last) {
            int64_t mid = (first + last) >> 1;
            if (argsort_gpu_v0[mid] <= argsort_gpu_v0[mid + 1]) {
                first = mid + 1;
            } else {
                last = mid;
            }
        }
        first = i;
        last = i + (1LL << cse_var_1);
        for (int j = 0; j < (1LL << cse_var_1); ++j) {
            if (first < 512 && last < 512) {
                if (argsort_gpu_v0[first] <= argsort_gpu_v0[last]) {
                    argsort_gpu_v2[i + j] = argsort_gpu_v0[first];
                    argsort_gpu_v3[i + j] = argsort_gpu[first];
                    first++;
                } else {
                    argsort_gpu_v2[i + j] = argsort_gpu_v0[last];
                    argsort_gpu_v3[i + j] = argsort_gpu[last];
                    last++;
                }
            } else {
                if (first < 512) {
                    argsort_gpu_v2[i + j] = argsort_gpu_v0[first];
                    argsort_gpu_v3[i + j] = argsort_gpu[first];
                    first++;
                } else {
                    argsort_gpu_v2[i + j] = argsort_gpu_v0[last];
                    argsort_gpu_v3[i + j] = argsort_gpu[last];
                    last++;
                }
            }
        }
    }
}

void default_function_kernel(float* argsort_gpu, float* argsort_gpu_v0, float* argsort_gpu_v2, float* argsort_gpu_v3, const float* data, int cse_var_1, int i_0, int num_elements) {
    default_function_kernel(argsort_gpu, argsort_gpu_v0, data, num_elements);
    default_function_kernel_1(argsort_gpu, argsort_gpu_v0, argsort_gpu_v2, argsort_gpu_v3, num_elements);
    default_function_kernel_2(argsort_gpu, argsort_gpu_v0, argsort_gpu_v2, argsort_gpu_v3, cse_var_1, i_0, num_elements);
}