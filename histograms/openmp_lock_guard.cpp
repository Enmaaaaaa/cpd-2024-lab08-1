#include "openmp_lock_guard.h"
#include <omp.h>
#include <mutex>

std::vector<int> OpenMPLockGuard::calculate(const int* input, const int buckets, const int size) {
  std::vector<int> histogram(buckets, 0);
  std::mutex mtx;

#pragma omp parallel for
  for (int i = 0; i < size; i++) {
    std::lock_guard<std::mutex> lock(mtx);
    histogram[input[i] - 1]++;
  }

  return histogram;
}
