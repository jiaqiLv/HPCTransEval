void default_function_kernel(float* T_transpose, float* ph) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 4; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            int index = (blockIdx_x * 1024) + threadIdx_x;
            if (index < 1035) {
                T_transpose[index] = ph[(((((((blockIdx_x * 256) + (threadIdx_x >> 2)) / 3) * 12) + (((((blockIdx_x * 4) + threadIdx_x) % 60) / 3) * 3)) + ((((blockIdx_x + threadIdx_x) % 3) * 4) + (threadIdx_x & 3)))];
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 4; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            int index = (blockIdx_x * 1024) + threadIdx_x;
            if (index < 1035) {
                T_transpose[index] = min(9.000000e+00f, T_transpose[index]);
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 4; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            int index = (blockIdx_x * 1024) + threadIdx_x;
            if (index < 1035) {
                T_transpose[index] = max(-9.000000e+00f, T_transpose[index]);
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 4; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            int index = (blockIdx_x * 1024) + threadIdx_x;
            if (index < 1035) {
                T_transpose[index] = (T_transpose[index] * (((T_transpose[index] * T_transpose[index]) * (((T_transpose[index] * T_transpose[index]) * (((T_transpose[index] * T_transpose[index]) * (((T_transpose[index] * T_transpose[index]) * (((T_transpose[index] * T_transpose[index]) * -2.760768e-16f) + 2.000188e-13f)) + -8.604672e-11f)) + 5.122297e-08f)) + 1.485722e-05f)) + 6.372619e-04f)) + 4.893525e-03f)) / (((T_transpose[index] * T_transpose[index]) * (((T_transpose[index] * T_transpose[index]) * (((T_transpose[index] * T_transpose[index]) * 1.198258e-06f) + 1.185347e-04f)) + 2.268435e-03f)) + 4.893525e-03f);
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 4; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            int index = (blockIdx_x * 1024) + threadIdx_x;
            if (index < 1035) {
                T_transpose[index] = T_transpose[((((blockIdx_x * 1024) + threadIdx_x) % 1380) * 3) + (((((blockIdx_x * 256) + (threadIdx_x >> 2)) / 345) * 4) + (threadIdx_x & 3))];
            }
        }
    }
}