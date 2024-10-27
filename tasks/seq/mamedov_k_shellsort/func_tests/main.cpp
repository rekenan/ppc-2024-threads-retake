// Copyright 2024 Mamedov Kenan
#include <gtest/gtest.h>

#include <vector>

#include "seq/mamedov_k_shellsort/include/shellsort.hpp"

TEST(mamedov_k_shellsort_seq, Sort_Vec_10) {
  const int count = 10;

  // Create data
  std::vector<int> in = mamedov_k_shellsort_seq::getRandomVec(count);
  std::vector<int> out(count, 0);

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(in.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  // Create Task
  mamedov_k_shellsort_seq::ShellsortSequential taskSequential(taskDataSeq);
  ASSERT_EQ(taskSequential.validation(), true);
  taskSequential.pre_processing();
  taskSequential.run();
  taskSequential.post_processing();

  ASSERT_TRUE(mamedov_k_shellsort_seq::checkOrder(out));
}

TEST(mamedov_k_shellsort_seq, Sort_Vec_20) {
  const int count = 20;

  // Create data
  std::vector<int> in = mamedov_k_shellsort_seq::getRandomVec(count);
  std::vector<int> out(count, 0);

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(in.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  // Create Task
  mamedov_k_shellsort_seq::ShellsortSequential taskSequential(taskDataSeq);
  ASSERT_EQ(taskSequential.validation(), true);
  taskSequential.pre_processing();
  taskSequential.run();
  taskSequential.post_processing();

  ASSERT_TRUE(mamedov_k_shellsort_seq::checkOrder(out));
}

TEST(mamedov_k_shellsort_seq, Sort_Vec_100) {
  const int count = 100;

  // Create data
  std::vector<int> in = mamedov_k_shellsort_seq::getRandomVec(count);
  std::vector<int> out(count, 0);

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(in.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  // Create Task
  mamedov_k_shellsort_seq::ShellsortSequential taskSequential(taskDataSeq);
  ASSERT_EQ(taskSequential.validation(), true);
  taskSequential.pre_processing();
  taskSequential.run();
  taskSequential.post_processing();

  ASSERT_TRUE(mamedov_k_shellsort_seq::checkOrder(out));
}

TEST(mamedov_k_shellsort_seq, Sort_Vec_500) {
  const int count = 500;

  // Create data
  std::vector<int> in = mamedov_k_shellsort_seq::getRandomVec(count);
  std::vector<int> out(count, 0);

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(in.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  // Create Task
  mamedov_k_shellsort_seq::ShellsortSequential taskSequential(taskDataSeq);
  ASSERT_EQ(taskSequential.validation(), true);
  taskSequential.pre_processing();
  taskSequential.run();
  taskSequential.post_processing();

  ASSERT_TRUE(mamedov_k_shellsort_seq::checkOrder(out));
}

TEST(mamedov_k_shellsort_seq, Sort_Vec_1000) {
  const int count = 1000;

  // Create data
  std::vector<int> in = mamedov_k_shellsort_seq::getRandomVec(count);
  std::vector<int> out(count, 0);

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(in.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  // Create Task
  mamedov_k_shellsort_seq::ShellsortSequential taskSequential(taskDataSeq);
  ASSERT_EQ(taskSequential.validation(), true);
  taskSequential.pre_processing();
  taskSequential.run();
  taskSequential.post_processing();

  ASSERT_TRUE(mamedov_k_shellsort_seq::checkOrder(out));
}
