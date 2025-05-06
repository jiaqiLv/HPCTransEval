void default_function_kernel(float* data, float* depth_to_space) {
    int blockIdx_x = omp_get_thread_num();
    int threadIdx_x = omp_get_thread_num();

    depth_to_space[((((int)blockIdx_x) * 54) + ((int)threadIdx_x))] = data[((((((((int)blockIdx_x) >> 2) * 270) + (((((((int)blockIdx_x) & 3) * 9) + (((int)threadIdx_x) / 6)) % 2) * 108)) + (((((int)threadIdx_x) % 6) % 2) * 54)) + (((((((int)blockIdx_x) & 3) * 9) + (((int)threadIdx_x) / 6)) / 2) * 3)) + ((((int)threadIdx_x) % 6) / 2))];
}