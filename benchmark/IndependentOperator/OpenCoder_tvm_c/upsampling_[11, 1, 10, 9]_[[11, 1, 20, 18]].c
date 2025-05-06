int main() {
    float data[11 * 20] = {0};
    float resize[11 * 40] = {0};

    // Initialize data with some values for testing
    for (int i = 0; i < 11 * 20; i++) {
        data[i] = (float)i;
    }

    // Call the kernel function
    default_function_kernel(data, resize, 11 * 20);

    // Print the result
    for (int i = 0; i < 11 * 40; i++) {
        printf("%f ", resize[i]);
        if ((i + 1) % 40 == 0) {
            printf("\n");
        }
    }

    return 0;
}