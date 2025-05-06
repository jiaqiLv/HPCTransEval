#include <math.h>
#include <omp.h>

void default_function_kernel(float* compute, float* ph_0) {
    int blockIdx_x = omp_get_thread_num();
    int threadIdx_x = blockIdx_x;
    compute[((blockIdx_x * 9) + (threadIdx_x))] = exp((ph_0[((blockIdx_x * 9) + (threadIdx_x))] * asinhf(ph_0[((blockIdx_x * 9) + (threadIdx_x))])));
}