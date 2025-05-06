void default_function_kernel(float* T_add, float* ph, float* ph_1, float* ph_2, float* ph_3, float* ph_4, float* ph_5, float* ph_6, float* ph_7, float* ph_8, float* ph_9, float* ph_10, float* ph_11, float* ph_12) {
    int num_threads = omp_get_max_threads();
    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 1000; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += ph[(thread_id * 1000) + k] * ph_1[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] = T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 256; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += T_matmul_NN[(thread_id * 256) + k] * ph[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 1000; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += ph[(thread_id * 1000) + k] * ph_1[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 256; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += T_matmul_NN[(thread_id * 256) + k] * ph[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 1000; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += ph[(thread_id * 1000) + k] * ph_1[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 256; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += T_matmul_NN[(thread_id * 256) + k] * ph[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 1000; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += ph[(thread_id * 1000) + k] * ph_1[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 256; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += T_matmul_NN[(thread_id * 256) + k] * ph[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 1000; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += ph[(thread_id * 1000) + k] * ph_1[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 256; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += T_matmul_NN[(thread_id * 256) + k] * ph[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 1000; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += ph[(thread_id * 1000) + k] * ph_1[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 256; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += T_matmul_NN[(thread_id * 256) + k] * ph[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 1000; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += ph[(thread_id * 1000) + k] * ph_1[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 256; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += T_matmul_NN[(thread_id * 256) + k] * ph[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 1000; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += ph[(thread_id * 1000) + k] * ph_1[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 256; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += T_matmul_NN[(thread_id * 256) + k] * ph[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 1000; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += ph[(thread_id * 1000) + k] * ph_1[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 256; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += T_matmul_NN[(thread_id * 256) + k] * ph[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 1000; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += ph[(thread_id * 1000) + k] * ph_1[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 256; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += T_matmul_NN[(thread_id * 256) + k] * ph[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 1000; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += ph[(thread_id * 1000) + k] * ph_1[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 256; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += T_matmul_NN[(thread_id * 256) + k] * ph[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 1000; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += ph[(thread_id * 1000) + k] * ph_1[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 256; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += T_matmul_NN[(thread_id * 256) + k] * ph[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 1000; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += ph[(thread_id * 1000) + k] * ph_1[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 256; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += T_matmul_NN[(thread_id * 256) + k] * ph[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 1000; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += ph[(thread_id * 1000) + k] * ph_1[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 256; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += T_matmul_NN[(thread_id * 256) + k] * ph[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 1000; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += ph[(thread_id * 1000) + k] * ph_1[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }

    #pragma omp parallel for
    for (int i = 0; i < num_threads; ++i) {
        int thread_id = omp_get_thread_num();
        int local_size = 512;
        float* T_matmul_NN = (float*)malloc(local_size * sizeof(float));
        for (int j = 0; j < local_size; ++j) {
            T_matmul_NN[j] = 0.000000e+00f;
        }

        for (int k = 0; k < 256; ++k) {
            for (int j = 0; j < local_size; ++j) {
                T_matmul_NN[j] += T_matmul_NN[(thread_id * 256) + k] * ph[(k * 256) + j];
            }
        }

        for (int j = 0; j < local_size; ++j) {
            T_add[thread_id * local_size + j] += T_matmul_NN[j];
        }

        free(T_matmul_NN);
    }
}