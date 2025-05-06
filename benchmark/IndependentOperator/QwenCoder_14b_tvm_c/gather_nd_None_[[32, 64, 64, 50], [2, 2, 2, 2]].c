void default_function_kernel(float* A, float* T_gather_nd, float* indices) {
#pragma omp parallel for collapse(2)
  for (int blockIdx_x = 0; blockIdx_x < 32; blockIdx_x++) {
    for (int threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
      int index1 = indices[((((blockIdx_x * 8) + (threadIdx_x >> 7)) / 25)];
      int index2 = indices[((((blockIdx_x * 8) + (threadIdx_x >> 7)) / 25) + 8)];
      int offset = (index1 * 204800) + (index2 * 3200) + ((blockIdx_x * 1024) + threadIdx_x) % 3200;
      T_gather_nd[(blockIdx_x * 1024) + threadIdx_x] = A[offset];
    }
  }
}