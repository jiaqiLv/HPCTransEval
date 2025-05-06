#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <float.h>
#include <inttypes.h>

#define BLOCK_SIZE 1024
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y)))

void default_function_kernel(float* ph, float* resize) {
  int blockIdx_x = 0;
  int threadIdx_x = 0;
  for (blockIdx_x = 0; blockIdx_x < 156; blockIdx_x++) {
    for (threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
      if (((blockIdx_x * 4) + (threadIdx_x >> 8)) < 625) {
        resize[((blockIdx_x * 1024) + threadIdx_x)] = (((ph[((((blockIdx_x * 256) + (threadIdx_x >> 2)) / 625) * 1024) + (MAX(MIN((threadIdx_x >> 1) / 25, 31), 0) * 32)]) + MAX(MIN(((threadIdx_x) / 50), 31), 0)) * (1.0f - (((float)((threadIdx_x) / 50)) - ((float)((int)floorf(((float)((threadIdx_x) / 50)) - 0.5f)))))) + (((ph[((((blockIdx_x * 256) + (threadIdx_x >> 2)) / 625) * 1024) + (MAX(MIN((threadIdx_x >> 1) / 25, 31), 0) * 32)]) + MAX(MIN(((threadIdx_x) / 50) + 1, 31), 0)) * (((float)((threadIdx_x) / 50)) - ((float)((int)floorf(((float)((threadIdx_x) / 50)) - 0.5f)))))) + (((ph[((((blockIdx_x * 256) + (threadIdx_x >> 2)) / 625) * 1024) + (MAX(MIN((threadIdx_x >> 1) / 25, 31), 0) * 32)]) + MAX(MIN(((threadIdx_x) / 50) + 1, 31), 0)) * (((float)((threadIdx_x) / 50)) - ((float)((int)floorf(((float)((threadIdx_x) / 50)) - 0.5f)))))) * (((float)((threadIdx_x) / 50)) - ((float)((int)floorf(((float)((threadIdx_x) / 50)) - 0.5f))))));
      }
    }
  }
}

void default_function_kernel_1(float* resize) {
  int blockIdx_x = 0;
  int threadIdx_x = 0;
  for (blockIdx_x = 0; blockIdx_x < 156; blockIdx_x++) {
    for (threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
      if (((blockIdx_x * 4) + (threadIdx_x >> 8)) < 625) {
        resize[((blockIdx_x * 1024) + threadIdx_x)] = (resize[((blockIdx_x * 1024) + threadIdx_x)] * 0.01f);
      }
    }
  }
}

void default_function_kernel_2(float* resize) {
  int blockIdx_x = 0;
  int threadIdx_x = 0;
  for (blockIdx_x = 0; blockIdx_x < 156; blockIdx_x++) {
    for (threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
      if (((blockIdx_x * 4) + (threadIdx_x >> 8)) < 625) {
        resize[((blockIdx_x * 1024) + threadIdx_x)] = ((0.0f < resize[((blockIdx_x * 1024) + threadIdx_x)]) ? resize[((blockIdx_x * 1024) + threadIdx_x)] : (resize[((blockIdx_x * 1024) + threadIdx_x)] * 0.5f));
      }
    }
  }
}

int main() {
  float ph[156 * 256];
  float resize[156 * 1024];
  default_function_kernel(ph, resize);
  default_function_kernel_1(resize);
  default_function_kernel_2(resize);
  return 0;
}