extern "C" __global__ void __launch_bounds__(32) default_function_kernel(float* __restrict__ T_softmax_maxelem, float* __restrict__ data) {
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 4)) < 17) {
    T_softmax_maxelem[((((int)blockIdx.x) * 32) + ((int)threadIdx.x))] = -3.402823e+38f;
  }
  if (((((int)blockIdx.x) * 2) + (((int)threadIdx.x) >> 4)) < 17) {
    T_softmax_maxelem[((((int)blockIdx.x) * 32) + ((int)threadIdx.x))] = max(T_softmax_maxelem[((((int)blockIdx.x) * 32) + ((int)threadIdx.x))], data[((((int)blockIdx.x) * 32) + ((int)threadIdx.x))]);
  }
}

extern "C" __global__ void __launch_bounds__(64) default_function_kernel_2(float* __restrict__ T_softmax_expsum, float* __restrict__ T_softmax_maxelem, float* __restrict__ T_softmax_norm, float* __restrict__ data) {
  if (((((int)blockIdx.x) * 4) + (((int)threadIdx.x) >> 4)) < 17) {
    T_softmax_norm[((((int)blockIdx.x) * 64) + ((int)threadIdx.x))] = (__expf((data[((((int)blockIdx.x) * 64) + ((int)threadIdx.x))] - T_softmax_maxelem[((((int)blockIdx.x) * 64) + ((int)threadIdx.x))])) / T_softmax_expsum[((((int)blockIdx.x) * 64) + ((int)threadIdx.x))]);
  }
}

extern "C" __global__ void __launch_bounds__(8) default_function_kernel_1(float* __restrict__ T_softmax_expsum, float* __restrict__ T_softmax_maxelem, float* __restrict__ data) {
  T_softmax_expsum[((((int)blockIdx.x) * 8) + ((int)threadIdx.x))] = 0.000000e+00f;
  T_softmax_expsum[((((int)blockIdx.x) * 8) + ((int)threadIdx.x))] = (T_softmax_expsum[((((int)blockIdx.x) * 8) + ((int)threadIdx.x))] + __expf((data[((((int)blockIdx.x) * 8) + ((int)threadIdx.x))] - T_softmax_maxelem[((((int)blockIdx.x) * 8) + ((int)threadIdx.x))])));
}

