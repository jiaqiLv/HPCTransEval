extern "C" __global__ void __launch_bounds__(1024) default_function_kernel(float* __restrict__ A, float* __restrict__ resize) {
  if (((((int)blockIdx.x) * 8) + (((int)threadIdx.x) >> 7)) < 375) {
    resize[((((int)blockIdx.x) * 1024) + ((int)threadIdx.x))] = ((((((A[(((((((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) / 125) * 32768) + (max(min(((int)floorf((((((float)((((((int)blockIdx.x) * 6) + (((int)threadIdx.x) >> 2)) % 250) / 25)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))), 31), 0) * 1024)) + (max(min(((int)floorf((((((float)((((((int)blockIdx.x) * 12) + (((int)threadIdx.x) >> 1)) % 50) / 5)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))), 31), 0) * 32)) + max(min(((int)floorf((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))), 31), 0))] * (1.000000e+00f - ((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f) - ((float)((int)floorf((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))))))) + (A[(((((((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) / 125) * 32768) + (max(min(((int)floorf((((((float)((((((int)blockIdx.x) * 6) + (((int)threadIdx.x) >> 2)) % 250) / 25)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))), 31), 0) * 1024)) + (max(min(((int)floorf((((((float)((((((int)blockIdx.x) * 12) + (((int)threadIdx.x) >> 1)) % 50) / 5)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))), 31), 0) * 32)) + max(min((((int)floorf((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))) + 1), 31), 0))] * ((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f) - ((float)((int)floorf((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))))))) * (1.000000e+00f - ((((((float)((((((int)blockIdx.x) * 12) + (((int)threadIdx.x) >> 1)) % 50) / 5)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f) - ((float)((int)floorf((((((float)((((((int)blockIdx.x) * 12) + (((int)threadIdx.x) >> 1)) % 50) / 5)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))))))) + (((A[(((((((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) / 125) * 32768) + (max(min(((int)floorf((((((float)((((((int)blockIdx.x) * 6) + (((int)threadIdx.x) >> 2)) % 250) / 25)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))), 31), 0) * 1024)) + (max(min((((int)floorf((((((float)((((((int)blockIdx.x) * 12) + (((int)threadIdx.x) >> 1)) % 50) / 5)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))) + 1), 31), 0) * 32)) + max(min(((int)floorf((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))), 31), 0))] * (1.000000e+00f - ((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f) - ((float)((int)floorf((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))))))) + (A[(((((((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) / 125) * 32768) + (max(min(((int)floorf((((((float)((((((int)blockIdx.x) * 6) + (((int)threadIdx.x) >> 2)) % 250) / 25)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))), 31), 0) * 1024)) + (max(min((((int)floorf((((((float)((((((int)blockIdx.x) * 12) + (((int)threadIdx.x) >> 1)) % 50) / 5)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))) + 1), 31), 0) * 32)) + max(min((((int)floorf((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))) + 1), 31), 0))] * ((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f) - ((float)((int)floorf((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))))))) * ((((((float)((((((int)blockIdx.x) * 12) + (((int)threadIdx.x) >> 1)) % 50) / 5)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f) - ((float)((int)floorf((((((float)((((((int)blockIdx.x) * 12) + (((int)threadIdx.x) >> 1)) % 50) / 5)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))))))) * (1.000000e+00f - ((((((float)((((((int)blockIdx.x) * 6) + (((int)threadIdx.x) >> 2)) % 250) / 25)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f) - ((float)((int)floorf((((((float)((((((int)blockIdx.x) * 6) + (((int)threadIdx.x) >> 2)) % 250) / 25)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))))))) + (((((A[(((((((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) / 125) * 32768) + (max(min((((int)floorf((((((float)((((((int)blockIdx.x) * 6) + (((int)threadIdx.x) >> 2)) % 250) / 25)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))) + 1), 31), 0) * 1024)) + (max(min(((int)floorf((((((float)((((((int)blockIdx.x) * 12) + (((int)threadIdx.x) >> 1)) % 50) / 5)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))), 31), 0) * 32)) + max(min(((int)floorf((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))), 31), 0))] * (1.000000e+00f - ((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f) - ((float)((int)floorf((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))))))) + (A[(((((((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) / 125) * 32768) + (max(min((((int)floorf((((((float)((((((int)blockIdx.x) * 6) + (((int)threadIdx.x) >> 2)) % 250) / 25)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))) + 1), 31), 0) * 1024)) + (max(min(((int)floorf((((((float)((((((int)blockIdx.x) * 12) + (((int)threadIdx.x) >> 1)) % 50) / 5)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))), 31), 0) * 32)) + max(min((((int)floorf((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))) + 1), 31), 0))] * ((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f) - ((float)((int)floorf((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))))))) * (1.000000e+00f - ((((((float)((((((int)blockIdx.x) * 12) + (((int)threadIdx.x) >> 1)) % 50) / 5)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f) - ((float)((int)floorf((((((float)((((((int)blockIdx.x) * 12) + (((int)threadIdx.x) >> 1)) % 50) / 5)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))))))) + (((A[(((((((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) / 125) * 32768) + (max(min((((int)floorf((((((float)((((((int)blockIdx.x) * 6) + (((int)threadIdx.x) >> 2)) % 250) / 25)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))) + 1), 31), 0) * 1024)) + (max(min((((int)floorf((((((float)((((((int)blockIdx.x) * 12) + (((int)threadIdx.x) >> 1)) % 50) / 5)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))) + 1), 31), 0) * 32)) + max(min(((int)floorf((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))), 31), 0))] * (1.000000e+00f - ((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f) - ((float)((int)floorf((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))))))) + (A[(((((((((int)blockIdx.x) * 128) + (((int)threadIdx.x) >> 3)) / 125) * 32768) + (max(min((((int)floorf((((((float)((((((int)blockIdx.x) * 6) + (((int)threadIdx.x) >> 2)) % 250) / 25)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))) + 1), 31), 0) * 1024)) + (max(min((((int)floorf((((((float)((((((int)blockIdx.x) * 12) + (((int)threadIdx.x) >> 1)) % 50) / 5)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))) + 1), 31), 0) * 32)) + max(min((((int)floorf((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))) + 1), 31), 0))] * ((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f) - ((float)((int)floorf((((((float)(((((int)blockIdx.x) * 4) + ((int)threadIdx.x)) % 10)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))))))) * ((((((float)((((((int)blockIdx.x) * 12) + (((int)threadIdx.x) >> 1)) % 50) / 5)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f) - ((float)((int)floorf((((((float)((((((int)blockIdx.x) * 12) + (((int)threadIdx.x) >> 1)) % 50) / 5)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f))))))) * ((((((float)((((((int)blockIdx.x) * 6) + (((int)threadIdx.x) >> 2)) % 250) / 25)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f) - ((float)((int)floorf((((((float)((((((int)blockIdx.x) * 6) + (((int)threadIdx.x) >> 2)) % 250) / 25)) + 5.000000e-01f) * 3.200000e+00f) - 5.000000e-01f)))))));
  }
}

