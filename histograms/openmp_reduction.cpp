#include "openmp_reduction.h"
#include <omp.h>

std::vector<int> OpenMPReduction::calculate(const int* input, const int buckets, const int size) {
    std::vector<int> histogram(buckets, 0);

    int* temp_histogram = new int[buckets]();

    #pragma omp parallel for reduction(+: temp_histogram[:buckets])
    for (int i = 0; i < size; i++) {
        temp_histogram[input[i] - 1]++;
    }

    for (int j = 0; j < buckets; j++) {
        histogram[j] += temp_histogram[j];
    }

    delete[] temp_histogram; 
    return histogram;
}
