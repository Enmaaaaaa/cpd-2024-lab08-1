#ifndef ESTANDAR_H
#define ESTANDAR_H

#include "histogram.h"
#include <mutex>
#include <vector>

class Estandar : public Histogram {
 public:
  std::vector<int> calculate(const int* input, const int buckets,
                             const int input_size) override;

 private:
  void calcular_histograma(const int* input, int* histograma, int inicio, int fin);
  std::mutex mtx_estandar;
};

#endif  // ESTANDAR_H
