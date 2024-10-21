#include "openmp_ompatomic.h"
#include <omp.h>

std::vector<int> OpenMPOMPATOMIC::calculate(const int* input, const int buckets, const int size) {
  std::vector<int> histogram(buckets, 0);

#pragma omp parallel for
  for (int i = 0; i < size; i++) {
#pragma omp atomic
    histogram[input[i] - 1]++;
  }

  return histogram;
}
