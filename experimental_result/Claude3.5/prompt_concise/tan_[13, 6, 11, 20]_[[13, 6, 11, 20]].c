#include <math.h>

void default_function_kernel(float* compute, float* data) {
    int blockId = 0;
    int threadId = 0;
    int blockStride = 55;

    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 6; j++) {
            for (int k = 0; k < 11; k++) {
                for (int l = 0; l < 20; l++) {
                    int dataIdx = (((blockId * blockStride) + threadId));
                    compute[dataIdx] = tanf(data[dataIdx]);

                    threadId++;
                    if (threadId == 55) {
                        threadId = 0;
                        blockId++;
                    }
                }
            }
        }
    }
}

// |End-of-Code|