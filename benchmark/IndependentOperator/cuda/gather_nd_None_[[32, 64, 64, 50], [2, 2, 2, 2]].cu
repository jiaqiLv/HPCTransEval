extern "C" __global__ void __launch_bounds__(1024) default_function_kernel(float* __restrict__ A, float* __restrict__ T_gather_nd, float* __restrict__ indices) {
  T_gather_nd[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = A[(((((int)indices[(((((int)blockIdx.x) * 8) + (((int)threadIdx.x) >> 7)) / 25)]) * 204800) + (((int)indices[((((((int)blockIdx.x) * 8) + (((int)threadIdx.x) >> 7)) / 25) + 8)]) * 3200)) + (((((int)blockIdx.x) * 1024) + ((int)threadIdx.x)) % 3200))];
}

