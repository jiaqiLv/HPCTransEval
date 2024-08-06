void default_function_kernel(float* __restrict__ compute, float* __restrict__ data) {
  int thread_id = blockIdx.x * 64 + threadIdx.x;
  compute[thread_id] = fabsf(data[thread_id]);
}