#include <omp.h>

void default_function_kernel(float* T_add, float* data, float* data_1, int size) {
  #pragma omp parallel for
  for (int i = 0; i < size; i++) {
    T_add[i] = (data[i] + data_1[i]);
  }
}
//End-of-Code|

