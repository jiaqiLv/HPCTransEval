extern "C" __global__ void __launch_bounds__(64) default_function_kernel_1(float* __restrict__ T_mod, float* __restrict__ ph_0) {
  T_mod[((((int)blockIdx.x) * 64) + ((int)threadIdx.x))] = fmodf(__sinf(ph_0[((((int)blockIdx.x) * 64) + ((int)threadIdx.x))]), ph_0[((((int)blockIdx.x) * 64) + ((int)threadIdx.x))]);
}

extern "C" __global__ void __launch_bounds__(12) default_function_kernel(float* __restrict__ compute, float* __restrict__ ph_0) {
  compute[((((int)blockIdx.x) * 12) + ((int)threadIdx.x))] = asinhf(ph_0[((((int)blockIdx.x) * 12) + ((int)threadIdx.x))]);
}

