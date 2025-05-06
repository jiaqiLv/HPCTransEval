void default_function_kernel(float* T_power, float* ph, float* ph_1) {
    const int num_elements = 4 * 32 * 120;
    
    #pragma omp parallel for
    for (int i = 0; i < num_elements; ++i) {
        // Step 1: Copy ph to T_reshape (equivalent to default_function_kernel)
        float T_reshape[num_elements];
        T_reshape[i] = ph[i];

        // Step 2: Reshape T_reshape to T_transpose (equivalent to default_function_kernel_1)
        float T_transpose[num_elements];
        T_transpose[i] = T_reshape[
            ((((i % 120) * 128) + (((i / 128) % 480) / 15) * 4)) + (((i / 4) / 15))
        ];

        // Step 3: Add 3.0 to T_transpose (equivalent to default_function_kernel_2)
        T_transpose[i] += 3.0f;

        // Step 4: Multiply T_transpose by ph (equivalent to default_function_kernel_4)
        T_transpose[i] *= ph[i];

        // Step 5: Subtract 11.0 from T_transpose (equivalent to default_function_kernel_3)
        T_transpose[i] -= 11.0f;

        // Step 6: Square T_transpose and store in T_power (equivalent to default_function_kernel_5)
        T_power[i] = powf(T_transpose[i], 2.0f);
    }
}