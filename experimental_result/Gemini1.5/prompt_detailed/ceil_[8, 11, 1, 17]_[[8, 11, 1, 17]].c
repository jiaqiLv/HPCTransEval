#include <omp.h>
#include <math.h>

void default_function_kernel(float* compute, float* data, int size) {
  #pragma omp parallel for
  for (int i = 0; i < size; i++) {
    if ((i / 8) < 187) {
      compute[i] = ceilf(data[i]);
    }
  }
}
//End-of-Code|
