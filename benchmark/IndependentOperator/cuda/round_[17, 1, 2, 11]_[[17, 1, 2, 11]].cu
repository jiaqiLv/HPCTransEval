extern "C" __global__ void __launch_bounds__(3) default_function_kernel(float* __restrict__ compute, float* __restrict__ data) {
  if (((((int)blockIdx.x) * 3) + ((int)threadIdx.x)) < 374) {
    compute[((((int)blockIdx.x) * 3) + ((int)threadIdx.x))] = roundf(data[((((int)blockIdx.x) * 3) + ((int)threadIdx.x))]);
  }
}

