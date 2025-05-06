void default_function_kernel(float* T_strided_slice, {
    #pragma omp parallel for collapse(2)
    for (int j = 0; j < 5; j++) {
        T_strided_slice[(i * 15) + j] {
            T_str {
                #pragma omp parallel for collapse(2)
                for (int j = 0; j < 5; j++) {
                    T_strided_slice[(i * 15) + j> {
                        #pragma omp parallel for collapse(2)
                        for (int j =  j < 5; j++) {
                            T_strided_slice[(i * 15) + j]