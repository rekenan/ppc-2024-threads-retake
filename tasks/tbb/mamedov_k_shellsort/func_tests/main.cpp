// Copyright 2024 Mamedov Kenan
#include <gtest/gtest.h>

#include <chrono>
#include <vector>

#include "tbb/mamedov_k_shellsort/include/shellsort.hpp"

TEST(mamedov_k_shellsort_tbb, Sort_Vec_10) {
  const int count = 10;

  // Create data
  std::vector<int> in = mamedov_k_shellsort_tbb::getRandomVec(count);
  std::vector<int> seq_out(count, 0);
  std::vector<int> par_out(count, 0);

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(in.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(seq_out.data()));
  taskDataSeq->outputs_count.emplace_back(seq_out.size());

  // Create Task
  mamedov_k_shellsort_tbb::ShellsortTBBTaskSequential testTaskSequential(taskDataSeq);
  ASSERT_EQ(testTaskSequential.validation(), true);
  testTaskSequential.pre_processing();
  testTaskSequential.run();
  testTaskSequential.post_processing();

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataPar = std::make_shared<ppc::core::TaskData>();
  taskDataPar->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataPar->inputs_count.emplace_back(in.size());
  taskDataPar->outputs.emplace_back(reinterpret_cast<uint8_t *>(seq_out.data()));
  taskDataPar->outputs_count.emplace_back(seq_out.size());

  // Create Task
  mamedov_k_shellsort_tbb::ShellsortTBBTaskParallel testTaskParallel(taskDataPar);
  ASSERT_EQ(testTaskParallel.validation(), true);
  testTaskParallel.pre_processing();
  testTaskParallel.run();
  testTaskParallel.post_processing();

  ASSERT_TRUE(mamedov_k_shellsort_tbb::checkOrder(seq_out));
  ASSERT_TRUE(mamedov_k_shellsort_tbb::checkOrder(par_out));
}

TEST(mamedov_k_shellsort_tbb, Sort_Vec_100) {
  const int count = 100;

  // Create data
  std::vector<int> in = mamedov_k_shellsort_tbb::getRandomVec(count);
  std::vector<int> seq_out(count, 0);
  std::vector<int> par_out(count, 0);

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(in.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(seq_out.data()));
  taskDataSeq->outputs_count.emplace_back(seq_out.size());

  // Create Task
  mamedov_k_shellsort_tbb::ShellsortTBBTaskSequential testTaskSequential(taskDataSeq);
  ASSERT_EQ(testTaskSequential.validation(), true);
  testTaskSequential.pre_processing();
  testTaskSequential.run();
  testTaskSequential.post_processing();

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataPar = std::make_shared<ppc::core::TaskData>();
  taskDataPar->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataPar->inputs_count.emplace_back(in.size());
  taskDataPar->outputs.emplace_back(reinterpret_cast<uint8_t *>(seq_out.data()));
  taskDataPar->outputs_count.emplace_back(seq_out.size());

  // Create Task
  mamedov_k_shellsort_tbb::ShellsortTBBTaskParallel testTaskParallel(taskDataPar);
  ASSERT_EQ(testTaskParallel.validation(), true);
  testTaskParallel.pre_processing();
  testTaskParallel.run();
  testTaskParallel.post_processing();

  ASSERT_TRUE(mamedov_k_shellsort_tbb::checkOrder(seq_out));
  ASSERT_TRUE(mamedov_k_shellsort_tbb::checkOrder(par_out));
}

TEST(mamedov_k_shellsort_tbb, Sort_Vec_1000) {
  const int count = 1000;

  // Create data
  std::vector<int> in = mamedov_k_shellsort_tbb::getRandomVec(count);
  std::vector<int> seq_out(count, 0);
  std::vector<int> par_out(count, 0);

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(in.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(seq_out.data()));
  taskDataSeq->outputs_count.emplace_back(seq_out.size());

  // Create Task
  mamedov_k_shellsort_tbb::ShellsortTBBTaskSequential testTaskSequential(taskDataSeq);
  ASSERT_EQ(testTaskSequential.validation(), true);
  testTaskSequential.pre_processing();
  testTaskSequential.run();
  testTaskSequential.post_processing();

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataPar = std::make_shared<ppc::core::TaskData>();
  taskDataPar->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataPar->inputs_count.emplace_back(in.size());
  taskDataPar->outputs.emplace_back(reinterpret_cast<uint8_t *>(seq_out.data()));
  taskDataPar->outputs_count.emplace_back(seq_out.size());

  // Create Task
  mamedov_k_shellsort_tbb::ShellsortTBBTaskParallel testTaskParallel(taskDataPar);
  ASSERT_EQ(testTaskParallel.validation(), true);
  testTaskParallel.pre_processing();
  testTaskParallel.run();
  testTaskParallel.post_processing();

  ASSERT_TRUE(mamedov_k_shellsort_tbb::checkOrder(seq_out));
  ASSERT_TRUE(mamedov_k_shellsort_tbb::checkOrder(par_out));
}

TEST(mamedov_k_shellsort_tbb, Sort_Vec_10000) {
  const int count = 10000;

  // Create data
  std::vector<int> in = mamedov_k_shellsort_tbb::getRandomVec(count);
  std::vector<int> seq_out(count, 0);
  std::vector<int> par_out(count, 0);

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(in.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(seq_out.data()));
  taskDataSeq->outputs_count.emplace_back(seq_out.size());

  // Create Task
  mamedov_k_shellsort_tbb::ShellsortTBBTaskSequential testTaskSequential(taskDataSeq);
  ASSERT_EQ(testTaskSequential.validation(), true);
  testTaskSequential.pre_processing();
  testTaskSequential.run();
  testTaskSequential.post_processing();

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataPar = std::make_shared<ppc::core::TaskData>();
  taskDataPar->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataPar->inputs_count.emplace_back(in.size());
  taskDataPar->outputs.emplace_back(reinterpret_cast<uint8_t *>(seq_out.data()));
  taskDataPar->outputs_count.emplace_back(seq_out.size());

  // Create Task
  mamedov_k_shellsort_tbb::ShellsortTBBTaskParallel testTaskParallel(taskDataPar);
  ASSERT_EQ(testTaskParallel.validation(), true);
  testTaskParallel.pre_processing();
  testTaskParallel.run();
  testTaskParallel.post_processing();

  ASSERT_TRUE(mamedov_k_shellsort_tbb::checkOrder(seq_out));
  ASSERT_TRUE(mamedov_k_shellsort_tbb::checkOrder(par_out));
}

TEST(mamedov_k_shellsort_tbb, Sort_Vec_50000) {
  const int count = 50000;

  // Create data
  std::vector<int> in = mamedov_k_shellsort_tbb::getRandomVec(count);
  std::vector<int> seq_out(count, 0);
  std::vector<int> par_out(count, 0);

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataSeq->inputs_count.emplace_back(in.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(seq_out.data()));
  taskDataSeq->outputs_count.emplace_back(seq_out.size());

  // Create Task
  mamedov_k_shellsort_tbb::ShellsortTBBTaskSequential testTaskSequential(taskDataSeq);
  ASSERT_EQ(testTaskSequential.validation(), true);
  testTaskSequential.pre_processing();

  std::chrono::steady_clock::time_point begin_seq = std::chrono::steady_clock::now();
  testTaskSequential.run();
  std::chrono::steady_clock::time_point end_seq = std::chrono::steady_clock::now();

  testTaskSequential.post_processing();

  // Create TaskData
  std::shared_ptr<ppc::core::TaskData> taskDataPar = std::make_shared<ppc::core::TaskData>();
  taskDataPar->inputs.emplace_back(reinterpret_cast<uint8_t *>(in.data()));
  taskDataPar->inputs_count.emplace_back(in.size());
  taskDataPar->outputs.emplace_back(reinterpret_cast<uint8_t *>(seq_out.data()));
  taskDataPar->outputs_count.emplace_back(seq_out.size());

  // Create Task
  mamedov_k_shellsort_tbb::ShellsortTBBTaskParallel testTaskParallel(taskDataPar);
  ASSERT_EQ(testTaskParallel.validation(), true);
  testTaskParallel.pre_processing();

  std::chrono::steady_clock::time_point begin_par = std::chrono::steady_clock::now();
  testTaskParallel.run();
  std::chrono::steady_clock::time_point end_par = std::chrono::steady_clock::now();

  testTaskParallel.post_processing();

  ASSERT_TRUE(mamedov_k_shellsort_tbb::checkOrder(seq_out));
  ASSERT_TRUE(mamedov_k_shellsort_tbb::checkOrder(par_out));

  std::cout << "Seq    time [µs]: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end_seq - begin_seq).count() << std::endl;
  std::cout << "TBB    time [µs]: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end_par - begin_par).count() << std::endl;
}
