#include "gt_queue.h"

TEST_F(QueueTest, TestDefaultConstructor) {
  s21::queue<int> my_queue;
  std::queue<int> original_queue;
  ASSERT_EQ(my_queue.empty(), original_queue.empty());
}

TEST_F(QueueTest, TestCopyConstructor) {
  s21::queue<int> my_queue_copy{1, 2, 3, 4, 5, 6};
  EXPECT_EQ((int)my_queue_copy.size(), 6);
  EXPECT_EQ(my_queue_copy.front(), 1);
  EXPECT_EQ(my_queue_copy.back(), 6);
  s21::queue<int> my_queue_copy_2(my_queue_copy);
  EXPECT_EQ((int)my_queue_copy_2.size(), 6);
  EXPECT_EQ(my_queue_copy_2.front(), 1);
  EXPECT_EQ(my_queue_copy_2.back(), 6);
}

TEST_F(QueueTest, TestMoveConstructor) {
  s21::queue<int> my_queue_copy{21, 1, 2, 3, 4, 22};
  EXPECT_EQ((int)my_queue_copy.size(), 6);
  EXPECT_EQ(my_queue_copy.front(), 21);
  EXPECT_EQ(my_queue_copy.back(), 22);
  s21::queue<int> my_queue_copy_2(std::move(my_queue_copy));
  EXPECT_EQ((int)my_queue_copy_2.size(), 6);
  EXPECT_EQ(my_queue_copy_2.front(), 21);
  EXPECT_EQ(my_queue_copy_2.back(), 22);
}

TEST_F(QueueTest, TestPush) {
  s21::queue<int> my_queue;
  my_queue.push(1);
  my_queue.push(2);
  my_queue.push(3);
  EXPECT_EQ((int)my_queue.size(), 3);
  EXPECT_EQ(my_queue.front(), 1);
  EXPECT_EQ(my_queue.back(), 3);
}

TEST_F(QueueTest, TestPop) {
  s21::queue<int> my_queue{1, 2, 3, 4, 5, 6};
  my_queue.pop();
  EXPECT_EQ((int)my_queue.size(), 5);
  EXPECT_EQ(my_queue.front(), 2);
  EXPECT_EQ(my_queue.back(), 6);
}

TEST_F(QueueTest, TestEmpty) {
  s21::queue<int> my_queue{1, 2, 3, 4, 5, 6};
  EXPECT_EQ(my_queue.empty(), false);
  my_queue.pop();
  EXPECT_EQ(my_queue.empty(), false);
  my_queue.pop();
  my_queue.pop();
  my_queue.pop();
  my_queue.pop();
  my_queue.pop();
  EXPECT_EQ(my_queue.empty(), true);
}

TEST_F(QueueTest, TestSize) {
  s21::queue<int> my_queue{1, 2, 3, 4, 5, 6};
  EXPECT_EQ((int)my_queue.size(), 6);
}

TEST_F(QueueTest, TestFront) {
  s21::queue<int> my_queue{1, 2, 3, 4, 5, 6};
  EXPECT_EQ(my_queue.front(), 1);
}

TEST_F(QueueTest, TestBack) {
  s21::queue<int> my_queue{1, 2, 3, 4, 5, 6};
  EXPECT_EQ(my_queue.back(), 6);
}

TEST_F(QueueTest, TestInsert_many) {
  s21::queue<int> my_queue{12, 21, 13, 31, 14, 41, 15, 51, 16, 61};
  my_queue.insert_many_back(1, 5);
  EXPECT_EQ((int)my_queue.size(), 12);
  EXPECT_EQ(my_queue.front(), 12);
  EXPECT_EQ(my_queue.back(), 5);
}

TEST_F(QueueTest, TestSwap) {
  s21::queue<int> my_queue{1, 2, 3, 4, 5, 6};
  s21::queue<int> my_queue_2{21, 22, 23, 24, 25, 26};
  my_queue.swap(my_queue_2);
  EXPECT_EQ((int)my_queue.size(), 6);
  EXPECT_EQ(my_queue.front(), 21);
  EXPECT_EQ(my_queue.back(), 26);
  EXPECT_EQ((int)my_queue_2.size(), 6);
  EXPECT_EQ(my_queue_2.front(), 1);
  EXPECT_EQ(my_queue_2.back(), 6);
}
