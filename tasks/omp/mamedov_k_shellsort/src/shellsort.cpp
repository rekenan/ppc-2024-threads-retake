// Copyright 2024 Mamedov Kenan
#include "omp/mamedov_k_shellsort/include/shellsort.hpp"

#include <omp.h>

#include <functional>
#include <iterator>
#include <thread>

using namespace std::chrono_literals;

std::vector<int> mamedov_k_shellsort_omp::getRandomVec(int n) {
  std::random_device dev;
  static std::mt19937 gen(dev());
  std::vector<int> vec(n);
  std::generate(vec.begin(), vec.end(), [] { return gen() % 100; });
  return vec;
}

bool mamedov_k_shellsort_omp::checkOrder(const std::vector<int>& vec) {
  for (auto iter = vec.begin(); iter != std::prev(vec.end()); ++iter) {
    if (*iter > *(iter + 1)) {
      return false;
    }
  }
  return true;
}

void insertionSort(std::vector<int>* vec, int start, int n, int stride) {
  for (int j = start + stride; j < n; j += stride) {
    int key = (*vec)[j];
    int i = j - stride;
    while (i >= start && (*vec)[i] > key) {
      (*vec)[i + stride] = (*vec)[i];
      i -= stride;
    }
    (*vec)[i + stride] = key;
  }
}

void shellSort(std::vector<int>* vec) {
  int n = vec->size();
  for (int m = n / 2; m > 0; m /= 2) {
    for (int i = 0; i < m; i++) {
      insertionSort(vec, i, n, m);
    }
  }
}

std::vector<int> mergeVecs(std::vector<int> arr1, std::vector<int> arr2) {
  int n1 = static_cast<int>(arr1.size());
  int n2 = static_cast<int>(arr2.size());

  int i = 0;
  int j = 0;
  int k = 0;

  std::vector<int> arr3(n1 + n2);

  while (i < n1 && j < n2) {
    if (arr1[i] < arr2[j])
      arr3[k++] = arr1[i++];
    else
      arr3[k++] = arr2[j++];
  }

  while (i < n1) arr3[k++] = arr1[i++];
  while (j < n2) arr3[k++] = arr2[j++];

  return arr3;
}

void mamedov_k_shellsort_omp::shellsortSimpleMerge(std::vector<int>* vec, int parts, bool parallel) {
  if (vec->empty() || parts <= 0) {
    return;
  }

  int size = static_cast<int>(vec->size());
  int grainsize = size / parts;

  // If parts is too large relative to vector size, fall back to regular quicksort
  if (grainsize < 1 || parts == 1) {
    shellSort(vec);
    return;
  }

  std::vector<std::vector<int>> vecs;
  vecs.reserve(parts);

  // Split into parts
  for (int i = 0; i < parts - 1; i++) {
    auto first = vec->begin() + grainsize * i;
    auto last = vec->begin() + grainsize * (i + 1);
    vecs.emplace_back(first, last);
  }
  // Handle the last part (may be larger due to remainder)
  vecs.emplace_back(vec->begin() + grainsize * (parts - 1), vec->end());

  // Sort each partition

  if (parallel) {
#pragma omp parallel for
    for (int i = 0; i < parts; i++) {
      shellSort(&vecs[i]);
    }
  } else {
    for (auto& partition : vecs) {
      shellSort(&partition);
    }
  }

  // Merge results
  *vec = vecs[0];
  for (size_t i = 1; i < vecs.size(); i++) {
    *vec = mergeVecs(*vec, vecs[i]);
  }
}

bool mamedov_k_shellsort_omp::ShellsortOMPTaskSequential::pre_processing() {
  internal_order_test();
  // Init value for input and output

  input_.reserve(taskData->inputs_count[0]);
  std::copy(reinterpret_cast<int*>(taskData->inputs[0]),
            reinterpret_cast<int*>(taskData->inputs[0]) + taskData->inputs_count[0], std::back_inserter(input_));

  return true;
}

bool mamedov_k_shellsort_omp::ShellsortOMPTaskSequential::validation() {
  internal_order_test();
  return taskData->inputs_count[0] == taskData->outputs_count[0];
}

bool mamedov_k_shellsort_omp::ShellsortOMPTaskSequential::run() {
  internal_order_test();
  shellsortSimpleMerge(&input_);
  return true;
}

bool mamedov_k_shellsort_omp::ShellsortOMPTaskSequential::post_processing() {
  internal_order_test();
  std::copy(input_.begin(), input_.end(), reinterpret_cast<int*>(taskData->outputs[0]));
  return true;
}

bool mamedov_k_shellsort_omp::ShellsortOMPTaskParallel::pre_processing() {
  internal_order_test();
  // Init value for input and output

  input_.reserve(taskData->inputs_count[0]);
  std::copy(reinterpret_cast<int*>(taskData->inputs[0]),
            reinterpret_cast<int*>(taskData->inputs[0]) + taskData->inputs_count[0], std::back_inserter(input_));

  return true;
}

bool mamedov_k_shellsort_omp::ShellsortOMPTaskParallel::validation() {
  internal_order_test();
  return taskData->inputs_count[0] == taskData->outputs_count[0];
}

bool mamedov_k_shellsort_omp::ShellsortOMPTaskParallel::run() {
  internal_order_test();
  shellsortSimpleMerge(&input_, omp_get_max_threads(), true);
  return true;
}

bool mamedov_k_shellsort_omp::ShellsortOMPTaskParallel::post_processing() {
  internal_order_test();
  std::copy(input_.begin(), input_.end(), reinterpret_cast<int*>(taskData->outputs[0]));
  return true;
}
