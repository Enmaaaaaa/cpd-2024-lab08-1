#ifndef OPENMP_LOCK_UNLOCK_H
#define OPENMP_LOCK_UNLOCK_H

#include <mutex>
#include <vector>
#include "histogram.h"

class OpenMPLockUnlock : public Histogram {
 public:
  std::vector<int> calculate(const int* input, const int buckets,
                             const int input_size) override;

 private:
  std::mutex mtx;
};

#endif  // OPENMP_LOCK_UNLOCK_H
