extern "C" __global__ void __launch_bounds__(4) default_function_kernel_2(float* __restrict__ T_mod, float* __restrict__ ph_0) {
  T_mod[((((int)blockIdx.x) * 4) + ((int)threadIdx.x))] = fmodf(ph_0[((((int)blockIdx.x) * 4) + ((int)threadIdx.x))], ceilf(ph_0[((((int)blockIdx.x) * 4) + ((int)threadIdx.x))]));
}

extern "C" __global__ void default_function_kernel_1(float* __restrict__ T_multiply, float* __restrict__ ph_0) {
  T_multiply[((int)blockIdx.x)] = (atanf(ph_0[((int)blockIdx.x)]) * ph_0[((int)blockIdx.x)]);
}

extern "C" __global__ void __launch_bounds__(4) default_function_kernel(float* __restrict__ compute, float* __restrict__ ph_0) {
  compute[((((int)blockIdx.x) * 4) + ((int)threadIdx.x))] = acosf(ph_0[((((int)blockIdx.x) * 4) + ((int)threadIdx.x))]);
}

