#include "estandar_reduction.h"
#include <thread>
#include <vector>

void calcular_local_histograma(const int* input, std::vector<int>& local_histogram, int start, int end) {
    for (int i = start; i < end; i++) {
        local_histogram[input[i] - 1]++;
    }
}

std::vector<int> EstandarReduction::calculate(const int* input, const int buckets, const int size) {
    std::vector<int> histogram(buckets, 0);
    int num_threads = std::thread::hardware_concurrency();
    std::vector<std::vector<int>> local_histograms(num_threads, std::vector<int>(buckets, 0));

    std::vector<std::thread> threads(num_threads);
    int chunk = size / num_threads;

    for (int t = 0; t < num_threads; t++) {
        int start = t * chunk;
        int end = (t == num_threads - 1) ? size : (t + 1) * chunk;
        threads[t] = std::thread(calcular_local_histograma, input, std::ref(local_histograms[t]), start, end);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    for (const auto& local_histogram : local_histograms) {
        for (int i = 0; i < buckets; i++) {
            histogram[i] += local_histogram[i];
        }
    }

    return histogram;
}
