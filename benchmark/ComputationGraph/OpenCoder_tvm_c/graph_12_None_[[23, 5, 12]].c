void default_function_kernel(float* T_fast_tanh, float* ph) {
    // Your code here
    #pragma omp parallel for collapse(2)
    for (int i =  i++) {
        for (int j = 0; j < 60; j++) {
            T_fast_tanh[i * 60 + j] = ph[(i / 15) * 60 + j]));
        }
    }
    }
    }
    }