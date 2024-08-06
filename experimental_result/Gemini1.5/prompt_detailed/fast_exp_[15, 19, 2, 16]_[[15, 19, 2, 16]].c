#include <omp.h>
#include <math.h>
#include <float.h>

void default_function_kernel(float* T_fast_exp, float* data, int size) {
  #pragma omp parallel for
  for (int i = 0; i < size; i++) {
    float x = fmaxf(fminf(data[i], 8.837627e+01f), -8.837626e+01f);
    int v_ = (int)(floorf((fmaxf(fminf(x, 8.837627e+01f), -8.837626e+01f) * 1.442695e+00f) + 5.000000e-01f)) + 1.270000e+02f) << 23;
    float exp_val = (*(float *)(&(v_))) * (((((((((((((1.987569e-04f * (x - (floorf((x * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.398200e-03f) * (x - (floorf((x * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 8.333452e-03f) * (x - (floorf((x * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 4.166580e-02f) * (x - (floorf((x * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.666667e-01f) * (x - (floorf((x * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 5.000000e-01f) * (x - (floorf((x * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) * (x - (floorf((x * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + (x - (floorf((x * 1.442695e+00f) + 5.000000e-01f)) * 6.931472e-01f))) + 1.000000e+00f);
    T_fast_exp[i] = fmaxf(exp_val, data[i]);
  }
}
//End-of-Code|

