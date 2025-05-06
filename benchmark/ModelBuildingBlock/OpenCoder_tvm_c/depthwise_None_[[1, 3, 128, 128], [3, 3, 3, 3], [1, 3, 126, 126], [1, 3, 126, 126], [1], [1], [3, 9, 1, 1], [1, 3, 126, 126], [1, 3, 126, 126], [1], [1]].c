void default_function_kernel(float* compute, float* ph, float* ph_1, float* ph_2, float* ph_3, float* ph_4, float* ph_5, float* ph_6, float* ph_7, float* ph_8, float* ph_9, float* ph_10) {
    // Your code here
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 11907; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 3; threadIdx_x++) {
            // Kernel 4
            compute[(blockIdx_x * 1024) + threadIdx_x] = ph[(blockIdx_x * 256) + threadIdx_x];
            // Kernel 15
            if (blockIdx_x * 256 + threadIdx_x / 3969 < 11907) {
                compute[(blockIdx_x * 1024) + threadIdx_x] = ph_1[(blockIdx_x * 256) + threadIdx_x / 3969] - compute[(blockIdx_x * 1024) + threadIdx_x];
            }
            // Kernel 18
            compute[(blockIdx_x * 1024) + threadIdx_x] = sqrtf(compute[(blockIdx_x * 1024) + threadIdx_x]);
            // Kernel 23
            if (blockIdx_x * 256 + threadIdx_x / 3969 < 11907) {
                compute[(blockIdx_x * 1024) + threadIdx_x] = compute[(blockIdx_x * 1024) + threadIdx_x] + ph_2[(blockIdx_x * 256) + threadIdx_x / 3969];
            }
            // Kernel 20
            compute[(blockIdx_x * 1024) + threadIdx_x] = ph_3[0];
            // Kernel 17
            compute[(blockIdx_x * 1024) + threadIdx_x] = compute[(blockIdx_x * 1024) + threadIdx_x] + 1.000000e-05f;
            // Kernel 6
            compute[(blockIdx_x * 1024) + threadIdx_x] = sqrtf(compute[(blockIdx_x * 1024) + threadIdx_x]);
            // Kernel 21
            if (blockIdx_x * 256 + threadIdx_x / 3969 < 11907) {
                compute[(blockIdx_x * 1024) + threadIdx_x] = compute[(blockIdx_x * 1024) + threadIdx_x] * ph_4[(blockIdx_x * 256) + threadIdx_x / 3969];
            }
            // Kernel 22
            compute[(blockIdx_x * 1024) + threadIdx_x] = ph_5[0];
            // Kernel 2
            compute[(blockIdx_x * 1024) + threadIdx_x] = ph[(blockIdx_x * 256) + threadIdx_x];
            // Kernel 8
            compute[(blockIdx_x * 1024) + threadIdx_x] = ph_6[0];
            // Kernel 5
            compute[(blockIdx_x * 1024) + threadIdx_x] = compute[(blockIdx_x * 1024) + threadIdx_x] + 1.000000e-05f;
            // Kernel 19
            if (blockIdx_x * 256 + threadIdx_x / 3969 < 11907) {
                compute[(blockIdx_x * 1024) + threadIdx_x] = ph_7[(blockIdx_x * 256) + threadIdx_x / 3969] / compute[(blockIdx_x * 1024) + threadIdx_x];
            }
            // Kernel 13
            if (blockIdx_x * 256 + threadIdx_x / 3969 < 11907) {
                ph_8[(blockIdx_x * 256) + threadIdx_x] = 0.000000e+00f;
            }
            for (int rc = 0; rc < 3; ++rc) {
                if (blockIdx_x * 256 + threadIdx_x / 3969 < 11907) {
                    ph_8[(blockIdx_x * 256) + threadIdx_x] = ph_8[(blockIdx_x * 256) + threadIdx_x] + ph_9[((((blockIdx_x * 256) + threadIdx_x / 3969) * 9) + rc)] * ph[((((blockIdx_x * 256) + threadIdx_x / 3969) * 9) + rc)];
                }
            }
            // Kernel 9
            if (blockIdx_x * 256 + threadIdx_x / 3969 < 11907) {
                compute[(blockIdx_x * 1024) + threadIdx_x] = compute[(blockIdx_x * 1024) + threadIdx_x] * ph_10[(blockIdx_x * 256) + threadIdx_x / 3969];
            }
            // Kernel 7
            if (blockIdx_x * 256 + threadIdx_x / 3969 < 11907) {
                compute[(blockIdx_x * 1024) + threadIdx_x] = ph_11[(blockIdx_x * 256) + threadIdx_x / 3969] / compute[(blockIdx_x * 1024) + threadIdx_x];
            }
            // Kernel 10
            compute[(blockIdx_x * 1024) + threadIdx_x] = ph_12[0];
            // Kernel 14
            compute[(blockIdx_x * 1024) + threadIdx_x] = ph[(blockIdx_x * 256) + threadIdx_x];
            // Kernel 12
            if (blockIdx_x * 256 + threadIdx_x / 3969 < 11907) {
                compute[(blockIdx_x * 1024) + threadIdx_x] = fmaxf(compute[(blockIdx_x * 1024) + threadIdx_x], 0.000000e+00f);
            }
            // Kernel 11
            if (blockIdx_x * 256 + threadIdx_x / 3969 < 11907) {
                compute[(blockIdx_x * 1024) + threadIdx_x] = compute[(blockIdx_x * 1024) + threadIdx_x] + ph_13[(blockIdx_x * 256) + threadIdx_x / 3969];
            }
            // Kernel 1
            if (blockIdx_x * 256 + threadIdx_x / 3969 < 11907) {
                ph_14[(blockIdx_x * 256) + threadIdx_x] = 0.000000e+00f;
            }
            for (int ry = 0; ry < 3; ++ry) {
                for (int rx = 0; rx < 3; ++rx) {
                    if (blockIdx_x * 256 + threadIdx_x / 3969 < 11907) {
                        ph_14[(blockIdx_x * 256) + threadIdx_x] = ph_14[(blockIdx_x * 256) + threadIdx_x] + ph_15[((((((((blockIdx_x * 256) + threadIdx_x / 3969) * 16384) + ((blockIdx_x * 512 + threadIdx_x / 1 % 7938) / 63) * 128) + (ry * 128)) + rx) + ((blockIdx_x * 16 + threadIdx_x % 126)))] * ph[((((((((blockIdx_x * 256) + threadIdx_x / 3969) * 27) + (ry * 3)) + rx))];
                    }
                }
            }
            // Kernel 3
            if (blockIdx_x * 256 + threadIdx_x / 3969 < 11907) {
                compute[(blockIdx_x * 1024) + threadIdx_x] = ph_16[(blockIdx_x * 256) + threadIdx_x / 3969] - compute[(blockIdx_x * 1024) + threadIdx_x];
            }
        }
    }
}