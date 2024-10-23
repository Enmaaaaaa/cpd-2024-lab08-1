#include "estandar_reduction.h"
#include <thread>

std::vector<int> EstandarReduction::calculate(const int* input, const int buckets, const int size) {
  std::vector<int> histogram(buckets, 0);

  const int num_hilos = std::thread::hardware_concurrency();
  int local_histograma[num_hilos][size] = {0};
  std::vector<std::thread> hilos(num_hilos);
  int chunk = size / num_hilos;

  for(int idx = 0; idx < num_hilos; idx++) {
    int inicio = chunk * idx;
    int fin = (idx == num_hilos - 1) ? size : idx * chunk;
    hilos[idx] = std::thread(calcular_local_histograma,
                             std::ref(local_histograma[idx]), inicio, fin);
  }

  for(auto& hilo : hilos) {
    hilo.join();
  }

  for(int idx = 0; idx < num_hilos; idx++) {
    for(int idy = 0; idy < size; idy++) {
      histograma[idy] += local_histograma[idx][idy];
    }
  }
  return histogram;
}
