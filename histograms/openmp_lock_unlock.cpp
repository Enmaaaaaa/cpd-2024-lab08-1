#include "openmp_lock_unlock.h"
#include <omp.h>

std::vector<int> OpenMPLockUnlock::calculate(const int* input, const int buckets,
                                             const int input_size) {
  std::vector<int> histograma(buckets, 0);

  #pragma omp parallel for
  for(int idx = 0; idx < input_size; idx++) {
    mtx.lock();  
    histograma[input[idx] - 1]++;
    mtx.unlock();  
  }

  return histograma;
}
