#include <math.h>

void default_function_kernel(float* compute, float* data) {
    int blockId = 0;
    int threadId = 0;
    int blockStride = 36;

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 20; j++) {
            for (int k = 0; k < 9; k++) {
                int dataIdx = (((blockId * blockStride) + threadId));
                compute[dataIdx] = sqrtf(data[dataIdx]);

                threadId++;
                if (threadId == 36) {
                    threadId = 0;
                    blockId++;
                }
            }
        }
    }
}

// |End-of-Code|