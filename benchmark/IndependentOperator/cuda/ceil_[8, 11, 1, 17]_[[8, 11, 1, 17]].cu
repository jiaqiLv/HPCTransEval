extern "C" __global__ void __launch_bounds__(32) default_function_kernel(float* __restrict__ compute, float* __restrict__ data) {
  if (((((int)blockIdx.x) * 4) + (((int)threadIdx.x) >> 3)) < 187) {
    compute[((((int)blockIdx.x) * 32) + ((int)threadIdx.x))] = ceilf(data[((((int)blockIdx.x) * 32) + ((int)threadIdx.x))]);
  }
}

