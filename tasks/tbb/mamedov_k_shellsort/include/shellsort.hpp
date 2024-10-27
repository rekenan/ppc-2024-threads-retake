// Copyright 2024 Mamedov Kenan
#pragma once

#include <algorithm>
#include <random>
#include <string>
#include <vector>

#include "core/task/include/task.hpp"

namespace mamedov_k_shellsort_tbb {

std::vector<int> getRandomVec(int n);
bool checkOrder(const std::vector<int>& vec);
void shellsortSimpleMerge(std::vector<int>* vec, int parts = 1, bool parallel = false);

class ShellsortTBBTaskSequential : public ppc::core::Task {
 public:
  explicit ShellsortTBBTaskSequential(std::shared_ptr<ppc::core::TaskData> taskData_) : Task(std::move(taskData_)) {}
  bool pre_processing() override;
  bool validation() override;
  bool run() override;
  bool post_processing() override;

 private:
  std::vector<int> input_{};
};

class ShellsortTBBTaskParallel : public ppc::core::Task {
 public:
  explicit ShellsortTBBTaskParallel(std::shared_ptr<ppc::core::TaskData> taskData_) : Task(std::move(taskData_)) {}
  bool pre_processing() override;
  bool validation() override;
  bool run() override;
  bool post_processing() override;

 private:
  std::vector<int> input_{};
};

}  // namespace mamedov_k_shellsort_tbb