void default_function_kernel(float* T_subtract, float* ph_0, float* ph_3, int num_blocks, int threads_per_block) {
    default_function_kernel_1(T_subtract, ph_0, ph_3, num_blocks, threads_per_block);
    default_function_kernel_2(compute, ph_0, ph_3, num_blocks, threads_per_block);
}