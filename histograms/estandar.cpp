#include "estandar.h"
#include <thread>

void Estandar::calcular_histograma(const int* input, int* histograma, int inicio, int fin) {
  for (int idx = inicio; idx < fin; ++idx) {
    std::lock_guard<std::mutex> lock(mtx_estandar);
    histograma[input[idx] - 1]++;
  }
}

std::vector<int> Estandar::calculate(const int* input, const int buckets,
                                     const int input_size) {
  std::vector<int> histograma(buckets, 0);
  const int num_hilos = std::thread::hardware_concurrency();
  std::vector<std::thread> hilos(num_hilos);
  int chunk = input_size / num_hilos;

  for (int idx = 0; idx < num_hilos; idx++) {
    int inicio = chunk * idx;
    int fin = (idx == num_hilos - 1) ? input_size : (idx + 1) * chunk;
    hilos[idx] = std::thread(&Estandar::calcular_histograma, this, input,
                             histograma.data(), inicio, fin);
  }

  for (auto& hilo : hilos) {
    hilo.join();
  }

  return histograma;
}
