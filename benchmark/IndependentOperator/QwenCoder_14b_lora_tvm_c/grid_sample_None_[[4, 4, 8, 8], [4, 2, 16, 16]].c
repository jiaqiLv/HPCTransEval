void default_function_kernel(float* compute, float* data, float* grid) {
    #pragma omp parallel for collapse(2)
    for (int blockIdx_x = 0; blockIdx_x < 4; blockIdx_x++) {
        for (int threadIdx_x = 0; threadIdx_x < 1024; threadIdx_x++) {
            int idx = (blockIdx_x * 1024) + threadIdx_x;
            float grid_value = grid[((blockIdx_x * 512) + (threadIdx_x & 255)) + 256];
            float transformed_grid_value = (grid_value + 1.0f) * 7.0f * 0.5f;
            int floor_transformed_grid_value = (int)floorf(transformed_grid_value);

            if (floor_transformed_grid_value >= 0 && floor_transformed_grid_value < 8) {
                compute[idx] = data[((blockIdx_x * 256) + ((threadIdx_x >> 8) * 64)) + (floor_transformed_grid_value * 8) + floor_transformed_grid_value] *
                               (1.0f - (transformed_grid_value - (float)floor_transformed_grid_value)) *
                               (1.0f - (transformed_grid_value - (float)floor_transformed_grid_value));
            } else {
                compute[idx] = 0.0f;
            }

            if (floor_transformed_grid_value >= -1 && floor_transformed_grid_value < 7) {
                compute[idx] += data[((blockIdx_x * 256) + ((threadIdx_x >> 8) * 64)) + (floor_transformed_grid_value * 8) + floor_transformed_grid_value + 1] *
                                (1.0f - (transformed_grid_value - (float)floor_transformed_grid_value)) *
                                (transformed_grid_value - (float)floor_transformed_grid_value);
            }

            if (floor_transformed_grid_value >= 0 && floor_transformed_grid_value < 7) {
                compute[idx] += data[((blockIdx_x * 256) + ((threadIdx_x >> 8) * 64)) + (floor_transformed_grid_value * 8) + floor_transformed_grid_value + 8] *
                                (transformed_grid_value - (float)floor_transformed_grid_value) *
                                (1.0f - (transformed_grid_value - (float)floor_transformed_grid_value));
            }

            if (floor_transformed_grid_value >= -1 && floor_transformed_grid_value < 7) {
                compute[idx] += data[((blockIdx_x * 256) + ((threadIdx_x >> 8) * 64)) + (floor_transformed_grid_value * 8) + floor_transformed_grid_value + 9] *
                                (transformed_grid_value - (float)floor_transformed_grid_value) *
                                (transformed_grid_value - (float)floor_transformed_grid_value);
            }
        }
    }
}