#include "openmp_critical.h"
#include <omp.h>

std::vector<int> OpenMPCritical::calculate(const int* input, const int buckets, const int size) {
  std::vector<int> histogram(buckets, 0);

#pragma omp parallel for
  for (int i = 0; i < size; i++) {
#pragma omp critical
    histogram[input[i] - 1]++;
  }

  return histogram;
}
