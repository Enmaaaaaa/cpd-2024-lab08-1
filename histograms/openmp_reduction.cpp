#include "openmp_reduction.h"
#include <omp.h>

std::vector<int> OpenMPReduction::calculate(const int* input, const int buckets, const int size) {
  std::vector<int> histogram(buckets, 0);

#pragma omp parallel for reduction(+ : histogram[:buckets])
  for (int i = 0; i < size; i++) {
    histogram[input[i] - 1]++;
  }

  return histogram;
}
