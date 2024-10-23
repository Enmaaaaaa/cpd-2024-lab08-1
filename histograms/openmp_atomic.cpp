#include "openmp_atomic.h"
#include <omp.h>
#include <atomic>

std::vector<int> OpenMPAtomic::calculate(const int* input, const int buckets, const int size) {
  std::vector<std::atomic<int>> histogram(buckets);

#pragma omp parallel for
  for (int i = 0; i < size; i++) {
    histogram[input[i] - 1]++;
  }

  std::vector<int> result(buckets);
  for (int i = 0; i < buckets; i++) {
    result[i] = histogram[i];
  }

  return result;
}
