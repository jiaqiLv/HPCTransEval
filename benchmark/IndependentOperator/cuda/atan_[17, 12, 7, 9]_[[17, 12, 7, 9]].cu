extern "C" __global__ void __launch_bounds__(18) default_function_kernel(float* __restrict__ compute, float* __restrict__ data) {
  compute[((((int)blockIdx.x) * 18) + ((int)threadIdx.x))] = atanf(data[((((int)blockIdx.x) * 18) + ((int)threadIdx.x))]);
}

