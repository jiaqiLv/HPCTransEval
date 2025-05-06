#include <omp.h>
#include <math.h>

void default_function_kernel(float* T_broadcast_to, float* ph) {
    #pragma omp parallel for
    for (int i = 0; i < 640; ++i) {
        if (T_broadcast_to[i] < 0) {
            T_broadcast_to[i] = T_broadcast_to[i] * ph[(i % 160) / 5];
        } else {
            T_broadcast_to[i] = (max(min(T_broadcast_to[i], 4.0f), -4.0f) *
                                   (((max(min(T_broadcast_to[i], 4.0f), -4.0f) * max(min(T_broadcast_to[i], 4.0f), -4.0f)) *
                                     (((max(min(T_broadcast_to[i], 4.0f), -4.0f) * max(min(T_broadcast_to[i], 4.0f), -4.0f)) *
                                       (((max(min(T_broadcast_to[i], 4.0f), -4.0f) * max(min(T_broadcast_to[i], 4.0f), -4.0f)) *
                                         (((max(min(T_broadcast_to[i], 4.0f), -4.0f) * max(min(T_broadcast_to[i], 4.0f), -4.0f)) *
                                           (((max(min(T_broadcast_to[i], 4.0f), -4.0f) * max(min(T_broadcast_to[i], 4.0f), -4.0f)) *
                                             (((max(min(T_broadcast_to[i], 4.0f), -4.0f) * max(min(T_broadcast_to[i], 4.0f), -4.0f)) *
                                               -2.726142e-10f) + 2.770681e-08f)) + -2.101024e-06f)) + -5.692506e-05f)) + -7.349906e-04f)) + -2.954600e-03f)) + -1.609603e-02f)) /
                                  (((max(min(T_broadcast_to[i], 4.0f), -4.0f) * max(min(T_broadcast_to[i], 4.0f), -4.0f)) *
                                    (((max(min(T_broadcast_to[i], 4.0f), -4.0f) * max(min(T_broadcast_to[i], 4.0f), -4.0f)) *
                                      (((max(min(T_broadcast_to[i], 4.0f), -4.0f) * max(min(T_broadcast_to[i], 4.0f), -4.0f)) *
                                        (((max(min(T_broadcast_to[i], 4.0f), -4.0f) * max(min(T_broadcast_to[i], 4.0f), -4.0f)) *
                                          -1.456607e-05f) + -2.133740e-04f)) + -1.682827e-03f)) + -7.373329e-03f)) + -1.426474e-02f));
        }
    }
}