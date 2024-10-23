#include "openmp_atomic.h"
#include <omp.h>
#include <atomic>

std::vector<int> OpenMPAtomic::calculate(const int* input, const int buckets, const int size) {
  std::vector<std::atomic<int>> histogram(buckets);

#pragma omp parallel for
  for (int idx = 0; idx < size; idx++) {
    histogram[input[idx] - 1]++;
  }
  
  return histogram;
}
