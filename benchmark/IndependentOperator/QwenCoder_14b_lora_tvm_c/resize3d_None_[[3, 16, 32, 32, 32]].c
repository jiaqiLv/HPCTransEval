void default_function_kernel(float* A, float* resize) {
    #pragma omp parallel for collapse(5)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 16; ++j) {
            for (int k = 0; k < 10; ++k) {
                for (int l = 0; l < 10; ++l) {
                    for (int m = 0; m < 10; ++m) {
                        int idx = (i * 16 * 10 * 10 * 10) + (j * 10 * 10 * 10) + (k * 10 * 10) + (l * 10) + m;
                        float x = (float)(k * 3.2) - 0.5;
                        float y = (float)(l * 3.2) - 0.5;
                        float z = (float)(m * 3.2) - 0.5;

                        int ix = (int)x;
                        int iy = (int)y;
                        int iz = (int)z;

                        ix = ix < 0 ? 0 : (ix > 31 ? 31 : ix);
                        iy = iy < 0 ? 0 : (iy > 31 ? 31 : iy);
                        iz = iz < 0 ? 0 : (iz > 31 ? 31 : iz);

                        float dx = x - ix;
                        float dy = y - iy;
                        float dz = z - iz;

                        float v000 = A[(i * 16 * 32 * 32 * 32) + (j * 32 * 32 * 32) + (ix * 32 * 32) + (iy * 32) + iz];
                        float v001 = A[(i * 16 * 32 * 32 * 32) + (j * 32 * 32 * 32) + (ix * 32 * 32) + (iy * 32) + (iz + 1)];
                        float v010 = A[(i * 16 * 32 * 32 * 32) + (j * 32 * 32 * 32) + (ix * 32 * 32) + ((iy + 1) * 32) + iz];
                        float v011 = A[(i * 16 * 32 * 32 * 32) + (j * 32 * 32 * 32) + (ix * 32 * 32) + ((iy + 1) * 32) + (iz + 1)];
                        float v100 = A[(i * 16 * 32 * 32 * 32) + (j * 32 * 32 * 32) + ((ix + 1) * 32 * 32) + (iy * 32) + iz];
                        float v101 = A[(i * 16 * 32 * 32 * 32) + (j * 32 * 32 * 32) + ((ix + 1) * 32 * 32) + (iy * 32) + (iz + 1)];
                        float v110 = A[(i * 16 * 32 * 32 * 32) + (j * 32 * 32 * 32) + ((ix + 1) * 32 * 32) + ((iy + 1) * 32) + iz];
                        float v111 = A[(i * 16 * 32 * 32 * 32) + (j * 32 * 32 * 32) + ((ix + 1) * 32 * 32) + ((iy + 1) * 32) + (iz + 1)];

                        float v00 = v000 * (1 - dx) + v100 * dx;
                        float v01 = v001 * (1 - dx) + v101 * dx;
                        float v10 = v010 * (1 - dx) + v110 * dx;
                        float v11 = v011 * (1 - dx) + v111 * dx;

                        float v0 = v00 * (1 - dy) + v10 * dy;
                        float v1 = v01 * (1 - dy) + v11 * dy;

                        resize[idx] = v0 * (1 - dz) + v1 * dz;
                    }
                }
            }
        }
    }
}