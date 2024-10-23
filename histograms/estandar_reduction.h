#ifndef ESTANDAR_REDUCTION_H
#define ESTANDAR_REDUCTION_H

#include "histogram.h"

class EstandarReduction : Histogram {
 public:
  std::vector<int> calculate(const int*, const int, const int) override;
};

#endif  // ESTANDAR_REDUCTION_H
