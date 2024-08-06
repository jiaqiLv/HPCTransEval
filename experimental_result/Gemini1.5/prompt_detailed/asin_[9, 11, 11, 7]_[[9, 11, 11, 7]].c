#include <omp.h>
#include <math.h>

void default_function_kernel(float* compute, float* data, int size) {
  #pragma omp parallel for
  for (int i = 0; i < size; i++) {
    if (i < 7623) {
      compute[i] = asinf(data[i]);
    }
  }
}
//End-of-Code|

