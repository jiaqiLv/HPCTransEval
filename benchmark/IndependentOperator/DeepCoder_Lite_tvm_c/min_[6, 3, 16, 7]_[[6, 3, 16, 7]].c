#include <algorithm> // for std::min
#include <omp.h> // for OpenMP

extern "C" void default_function_kernel(float* __restrict__ data, float* __restrict__ data_red, int num_elements) {
  // Initialize the minimum value to a very large number
  data_red[0] = 3.402823e+38f;

  // Parallelize the loop over the data
  #pragma omp parallel for reduction(min:data_red[0])
  for (int k0 = 0; k0 < 6; ++k0) {
    for (int k1 = 0; k1 < 3; ++k1) {
      for (int k2 = 0; k2 < 16; ++k2) {
        for (int k3 = 0; k3 < 7; ++k3) {
          int index = ((((k0 * 336) + (k1 * 112)) + (k2 * 7)) + k3);
          data_red[0] = std::min(data_red[0], data[index]);
        }
      }
    }
  }
}