#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define NUM_THREADS 64

// Function to calculate the maximum of two values
float max(float a, float b) {
  return (a > b) ? a : b;
}

// Function to calculate the minimum of two values
float min(float a, float b) {
  return (a < b) ? a : b;
}

// Function to perform the softmax operation on a 2D array
void default_function_kernel(float* T_softmax_expsum, float* T_softmax_maxelem, float* T_softmax_norm, float* data) {
  // Calculate the maximum element for each row
  #pragma omp parallel for num_threads(NUM_THREADS)
  for (int i = 0; i < 195; i++) {
    T_softmax_maxelem[i] = -3.402823e+38f;
    for (int k = 0; k < 15; k++) {
      T_softmax_maxelem[i] = max(T_softmax_maxelem[i], data[(i * 960) + (k * 20) + (i % 20)]);
    }
  }

  // Calculate the exponential sum for each row
  #pragma omp parallel for num_threads(NUM_THREADS)
  for (int i = 0; i < 195; i++) {
    T_softmax_expsum[i] = 0.0f;
    for (int k = 0; k < 15; k++) {
      float val = data[(i * 960) + (k * 20) + (i % 20)] - T_softmax_maxelem[i];
      val = max(min(val, 8.837627e+01f), -8.837626e+01f);
      float exp_val = expf((val * 1.442695e+00f) - floorf((val * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f);
      T_softmax_expsum[i] += exp_val;
    }
  }

  // Normalize the exponential sum for each row
  #pragma omp parallel for num_threads(NUM_THREADS)
  for (int i = 0; i < 195; i++) {
    for (int k = 0; k < 15; k++) {
      float val = data[(i * 960) + (k * 20) + (i % 20)] - T_softmax_maxelem[i];
      val = max(min(val, 8.837627e+01f), -8.837626e+01f);
      float exp_val = expf((val * 1.442695e+00f) - floorf((val * 1.442695e+00f) + 5.000000e-01f) * 6.931472e-01f);
      T_softmax_norm[(i * 960) + (k * 20) + (i % 20)] = exp_val / T_softmax_expsum[i];
    }
  }
}

int main() {
  // Allocate memory for the input data and output arrays
  float* data = (float*)malloc(13 * 20 * 3 * 15 * sizeof(float));
  float* T_softmax_expsum = (float*)malloc(195 * sizeof(float));
  float* T_softmax_maxelem = (float*)malloc(195 * sizeof(float));
  float* T_softmax_norm = (float*)malloc(13 * 20 * 3 * 15 * sizeof(float));

  // Initialize the input data (replace with your actual data)
  for (int i = 0; i < 13 * 20 * 3 * 15; i++) {
    data[i] = (float)i;
  }

  // Call the softmax function
  default_function_kernel(T_softmax_expsum, T_softmax_maxelem, T_softmax_norm, data);

  // Print the normalized softmax output (replace with your desired usage)
  // for (int i = 0; i < 13 * 20 * 3 * 15; i++) {
  //   printf("%f ", T_softmax_norm[i]);
  // }

  // Free allocated memory
  free(data);
  free(T_softmax_expsum);
  free(T_softmax_maxelem);
  free(T_softmax_norm);

  return 0;
}

