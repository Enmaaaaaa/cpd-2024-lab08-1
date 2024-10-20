#include "openmp_critical.h"
#include <omp.h>

std::vector<int> OpenMPCritical::calculate(const int* input, const int numElements, const int maxValue) {
    std::vector<int> histogram(maxValue, 0); 

    #pragma omp parallel
    {
        std::vector<int> localHistogram(maxValue, 0); 

        #pragma omp for
        for (int i = 0; i < numElements; ++i) {
            if (input[i] > 0 && input[i] <= maxValue) {
                localHistogram[input[i] - 1]++;
            }
        }

        #pragma omp critical
        {
            for (int j = 0; j < maxValue; ++j) {
                histogram[j] += localHistogram[j];
            }
        }
    }

    return histogram;
}
