void default_function_kernel(float* T_softmax_norm, float* data) {
    const int num_blocks = 195;
    const int threads_per_block = 32;
    const int total_elements = 13 * 20 * 3 * 15;

    #pragma omp parallel for collapse(2)
    for (int blockIdx = 0; blockIdx < num_blocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < threads_per_block; ++threadIdx) {
            int idx = (blockIdx * threads_per_block) + threadIdx;
            if (idx < num_blocks) {
                T_softmax_norm[idx] = 0.0f;
            }
        }
    }

    #pragma omp parallel for collapse(3)
    for (int blockIdx = 0; blockIdx < num_blocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < threads_per_block; ++threadIdx) {
            for (int k = 0; k < 15; ++k) {
                int idx = (blockIdx * threads_per_block) + threadIdx;
                if (idx < num_blocks) {
                    int v_ = ((int)(floorf(((max(min((data[((blockIdx * 480) + (threadIdx * 15)) + k] - T_softmax_norm[idx]), 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) + 127.0f)) << 23;
                    T_softmax_norm[idx] += max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min((data[((blockIdx * 480) + (threadIdx * 15)) + k] - T_softmax_norm[idx]), 8.837627f), -8.837626f) - (floorf(((max(min((data[((blockIdx * 480) + (threadIdx * 15)) + k] - T_softmax_norm[idx]), 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) + 1.398200e-03f) * (max(min((data[((blockIdx * 480) + (threadIdx * 15)) + k] - T_softmax_norm[idx]), 8.837627f), -8.837626f) - (floorf(((max(min((data[((blockIdx * 480) + (threadIdx * 15)) + k] - T_softmax_norm[idx]), 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) + 8.333452e-03f) * (max(min((data[((blockIdx * 480) + (threadIdx * 15)) + k] - T_softmax_norm[idx]), 8.837627f), -8.837626f) - (floorf(((max(min((data[((blockIdx * 480) + (threadIdx * 15)) + k] - T_softmax_norm[idx]), 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) + 4.166580e-02f) * (max(min((data[((blockIdx * 480) + (threadIdx * 15)) + k] - T_softmax_norm[idx]), 8.837627f), -8.837626f) - (floorf(((max(min((data[((blockIdx * 480) + (threadIdx * 15)) + k] - T_softmax_norm[idx]), 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) + 1.666667e-01f) * (max(min((data[((blockIdx * 480) + (threadIdx * 15)) + k] - T_softmax_norm[idx]), 8.837627f), -8.837626f) - (floorf(((max(min((data[((blockIdx * 480) + (threadIdx * 15)) + k] - T_softmax_norm[idx]), 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) + 0.5f) * (max(min((data[((blockIdx * 480) + (threadIdx * 15)) + k] - T_softmax_norm[idx]), 8.837627f), -8.837626f) - (floorf(((max(min((data[((blockIdx * 480) + (threadIdx * 15)) + k] - T_softmax_norm[idx]), 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) * (max(min((data[((blockIdx * 480) + (threadIdx * 15)) + k] - T_softmax_norm[idx]), 8.837627f), -8.837626f) - (floorf(((max(min((data[((blockIdx * 480) + (threadIdx * 15)) + k] - T_softmax_norm[idx]), 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) + (max(min((data[((blockIdx * 480) + (threadIdx * 15)) + k] - T_softmax_norm[idx]), 8.837627f), -8.837626f) - (floorf(((max(min((data[((blockIdx * 480) + (threadIdx * 15)) + k] - T_softmax_norm[idx]), 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) + 1.0f)), (data[((blockIdx * 480) + (threadIdx * 15)) + k] - T_softmax_norm[idx]));
                }
            }
        }
    }

    #pragma omp parallel for collapse(2)
    for (int blockIdx = 0; blockIdx < num_blocks; ++blockIdx) {
        for (int threadIdx = 0; threadIdx < threads_per_block; ++threadIdx) {
            int idx = (blockIdx * threads_per_block) + threadIdx;
            if (idx < num_blocks) {
                int v_ = ((int)(floorf(((max(min((data[idx] - T_softmax_norm[idx]), 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) + 127.0f)) << 23;
                T_softmax_norm[idx] = (max(((*(float *)(&(v_))) * ((((((((((((((1.987569e-04f * (max(min((data[idx] - T_softmax_norm[idx]), 8.837627f), -8.837626f) - (floorf(((max(min((data[idx] - T_softmax_norm[idx]), 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) + 1.398200e-03f) * (max(min((data[idx] - T_softmax_norm[idx]), 8.837627f), -8.837626f) - (floorf(((max(min((data[idx] - T_softmax_norm[idx]), 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) + 8.333452e-03f) * (max(min((data[idx] - T_softmax_norm[idx]), 8.837627f), -8.837626f) - (floorf(((max(min((data[idx] - T_softmax_norm[idx]), 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) + 4.166580e-02f) * (max(min((data[idx] - T_softmax_norm[idx]), 8.837627f), -8.837626f) - (floorf(((max(min((data[idx] - T_softmax_norm[idx]), 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) + 1.666667e-01f) * (max(min((data[idx] - T_softmax_norm[idx]), 8.837627f), -8.837626f) - (floorf(((max(min((data[idx] - T_softmax_norm[idx]), 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) + 0.5f) * (max(min((data[idx] - T_softmax_norm[idx]), 8.837627f), -8.837626f) - (floorf(((max(min((data[idx] - T_softmax_norm[idx]), 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) * (max(min((data[idx] - T_softmax_norm[idx]), 8.837627f), -8.837626f) - (floorf(((max(min((data[idx] - T_softmax_norm[idx]), 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) + (max(min((data[idx] - T_softmax_norm[idx]), 8.837627f), -8.837626f) - (floorf(((max(min((data[idx] - T_softmax_norm[idx]), 8.837627f), -8.837626f) * 1.442695f) + 0.5f)) * 0.6931472f))) + 1.0f)), (data[idx] - T_softmax_norm[idx])) / T_softmax_norm[idx]);
            }
        }
    }
}