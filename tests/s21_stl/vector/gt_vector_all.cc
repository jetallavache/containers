#include "gt_vector.h"

TEST_F(VectorTest, TestAt) {
  int_vector.at(4) = 256;
  int_vector_std.at(4) = 256;
  ASSERT_EQ(int_vector.at(4), int_vector_std.at(4));
}

TEST_F(VectorTest, TestAtConst) {
  ASSERT_EQ(const_vector.at(4), const_vector_std.at(4));
}

TEST_F(VectorTest, TestReferenceOperator) {
  int_vector[3] = 123;
  int_vector_std[3] = 123;
  ASSERT_EQ(int_vector[3], int_vector_std[3]);
}

TEST_F(VectorTest, TestReferenceOperatorConst) {
  ASSERT_EQ(const_vector[3], const_vector_std[3]);
}

TEST_F(VectorTest, TestFront) {
  ASSERT_EQ(float_vector.front(), float_vector_std.front());
}

TEST_F(VectorTest, TestBack) {
  ASSERT_EQ(float_vector.back(), float_vector_std.back());
}

TEST_F(VectorTest, TestData) {
  s21::Vector<int>::iterator it;
  it = int_vector.begin();
  std::vector<int>::iterator it_std;
  it_std = int_vector_std.begin();
  ASSERT_EQ(it[3], it_std[3]);
}

TEST_F(VectorTest, TestBegin) {
  s21::Vector<int>::iterator it;
  it = int_vector.begin();
  std::vector<int>::iterator it_std;
  it_std = int_vector_std.begin();
  ASSERT_EQ(*it, *it_std);
}

TEST_F(VectorTest, TestBeginConst) {
  s21::Vector<int>::const_iterator it;
  it = const_vector.begin();
  std::vector<int>::const_iterator it_std;
  it_std = const_vector_std.begin();
  ASSERT_EQ(*it, *it_std);
}

TEST_F(VectorTest, TestEnd) {
  s21::Vector<int>::iterator it;
  it = int_vector.end() - 1;
  std::vector<int>::iterator it_std;
  it_std = int_vector_std.end() - 1;
  ASSERT_EQ(*it, *it_std);
}

TEST_F(VectorTest, TestEndConst) {
  s21::Vector<int>::const_iterator it;
  it = const_vector.end() - 1;
  std::vector<int>::const_iterator it_std;
  it_std = const_vector_std.end() - 1;
  ASSERT_EQ(*it, *it_std);
}

TEST_F(VectorTest, TestEmpty) { ASSERT_TRUE(empty_vector.empty()); }
TEST_F(VectorTest, TestEmpty2) { ASSERT_FALSE(string_vector.empty()); }
TEST_F(VectorTest, TestEmptyConst) { ASSERT_FALSE(const_vector.empty()); }
TEST_F(VectorTest, TestSize) {
  ASSERT_EQ(string_vector_std.size(), string_vector.size());
}

TEST_F(VectorTest, TestReserve) {
  double_vector.reserve(14);
  double_vector_std.reserve(14);
  ASSERT_EQ(double_vector.size(), double_vector_std.size());
  ASSERT_EQ(double_vector.capacity(), double_vector_std.capacity());
}
TEST_F(VectorTest, TestCapacity) {
  ASSERT_EQ(string_vector_std.capacity(), string_vector.capacity());
}
TEST_F(VectorTest, TestShrinkToFit) {
  double_vector.reserve(20);
  double_vector_std.reserve(20);
  double_vector.shrink_to_fit();
  double_vector_std.shrink_to_fit();
  ASSERT_EQ(double_vector.size(), double_vector_std.size());
  ASSERT_EQ(double_vector.capacity(), double_vector_std.capacity());
}

TEST_F(VectorTest, TestClear) {
  double_vector.clear();
  double_vector_std.clear();
  ASSERT_EQ(double_vector.size(), double_vector_std.size());
  ASSERT_EQ(double_vector.capacity(), double_vector_std.capacity());
}

TEST_F(VectorTest, TestInsert) {
  char_vector.insert(char_vector.end(), 't');
  char_vector_std.insert(char_vector_std.end(), 't');
  ASSERT_EQ(char_vector.back(), char_vector_std.back());
  ASSERT_EQ(char_vector.size(), char_vector_std.size());
  ASSERT_EQ(char_vector.capacity(), char_vector_std.capacity());
}

TEST_F(VectorTest, TestInsert2) {
  int_vector.insert(int_vector.begin() + 1, 444);
  int_vector_std.insert(int_vector_std.begin() + 1, 444);
  s21::Vector<int>::iterator it = int_vector.begin();
  std::vector<int>::iterator it_std = int_vector_std.begin();
  while (it != int_vector.end() || it_std != int_vector_std.end()) {
    ASSERT_EQ(*it, *it_std);
    ++it;
    ++it_std;
  }
  ASSERT_EQ(int_vector.size(), int_vector_std.size());
  ASSERT_EQ(int_vector.capacity(), int_vector_std.capacity());
}

TEST_F(VectorTest, TestErase) {
  char_vector.erase(char_vector.end() - 1);
  char_vector_std.erase(char_vector_std.end() - 1);
  ASSERT_EQ(char_vector.back(), char_vector_std.back());
  ASSERT_EQ(char_vector.size(), char_vector_std.size());
  ASSERT_EQ(char_vector.capacity(), char_vector_std.capacity());
}

TEST_F(VectorTest, TestErase2) {
  int_vector.erase(int_vector.begin() + 1);
  int_vector_std.erase(int_vector_std.begin() + 1);
  s21::Vector<int>::iterator it = int_vector.begin();
  std::vector<int>::iterator it_std = int_vector_std.begin();
  while (it != int_vector.end() || it_std != int_vector_std.end()) {
    ASSERT_EQ(*it, *it_std);
    ++it;
    ++it_std;
  }
  ASSERT_EQ(int_vector.size(), int_vector_std.size());
  ASSERT_EQ(int_vector.capacity(), int_vector_std.capacity());
}

TEST_F(VectorTest, TestPushBack) {
  int_vector.push_back(481223);
  int_vector_std.push_back(481223);
  ASSERT_EQ(int_vector.back(), int_vector_std.back());
  ASSERT_EQ(int_vector.size(), int_vector_std.size());
  ASSERT_EQ(int_vector.capacity(), int_vector_std.capacity());
}

TEST_F(VectorTest, TestPushBack2) {
  int_vector.reserve(20);
  int_vector_std.reserve(20);
  int_vector.push_back(20);
  int_vector_std.push_back(20);
  ASSERT_EQ(int_vector.size(), int_vector_std.size());
  ASSERT_EQ(int_vector.capacity(), int_vector_std.capacity());
  ASSERT_EQ(int_vector.back(), int_vector_std.back());
}

TEST_F(VectorTest, Testpop_back) {
  int_vector.pop_back();
  int_vector_std.pop_back();
  ASSERT_EQ(int_vector.back(), int_vector_std.back());
  ASSERT_EQ(int_vector.size(), int_vector_std.size());
  ASSERT_EQ(int_vector.capacity(), int_vector_std.capacity());
}

TEST_F(VectorTest, TestSwap) {
  int_vector.swap(empty_vector);
  int_vector_std.swap(empty_vector_std);
  ASSERT_EQ(int_vector.size(), int_vector_std.size());
  ASSERT_EQ(int_vector.capacity(), int_vector_std.capacity());
  ASSERT_EQ(empty_vector.size(), empty_vector_std.size());
  ASSERT_EQ(empty_vector.capacity(), empty_vector_std.capacity());
  while (!empty_vector.empty() && !empty_vector_std.empty()) {
    ASSERT_EQ(empty_vector.back(), empty_vector_std.back());
    empty_vector.pop_back();
    empty_vector_std.pop_back();
  }
  ASSERT_EQ(int_vector.empty(), int_vector_std.empty());
  ASSERT_TRUE(int_vector.empty());
}

TEST_F(VectorTest, TestInsertMany) {
  int_vector.insert_many(int_vector.begin() + 1, 162342);
  int_vector_std.emplace(int_vector_std.begin() + 1, 162342);
  ASSERT_EQ(int_vector.size(), int_vector_std.size());
  ASSERT_EQ(int_vector.capacity(), int_vector_std.capacity());
  while (!int_vector.empty() && !int_vector_std.empty()) {
    ASSERT_EQ(int_vector.back(), int_vector_std.back());
    int_vector.pop_back();
    int_vector_std.pop_back();
  }
}

TEST_F(VectorTest, TestInsertMany2) {
  int_vector.insert_many(int_vector.begin() + 1, 4234, 23423, 234234, 432,
                         2423423, 234242, 4234234, 4234234, 4324234, 42342342,
                         2342342, 234234, 234234, 234, 23, 2, 11);
  s21::Vector<int> result{1,      4234,    23423,   234234,  432,      2423423,
                          234242, 4234234, 4234234, 4324234, 42342342, 2342342,
                          234234, 234234,  234,     23,      2,        11,
                          2,      3,       4,       5,       6};
  s21::Vector<int>::iterator it = int_vector.begin();
  s21::Vector<int>::iterator it_res = result.begin();
  while (it != int_vector.end() || it_res != result.end()) {
    ASSERT_EQ(*it, *it_res);
    ++it;
    ++it_res;
  }
}

TEST_F(VectorTest, TestInsertManyBack) {
  int_vector.insert_many_back(162342);
  int_vector_std.emplace_back(162342);
  ASSERT_EQ(int_vector.size(), int_vector_std.size());
  ASSERT_EQ(int_vector.capacity(), int_vector_std.capacity());
  while (!int_vector.empty() && !int_vector_std.empty()) {
    ASSERT_EQ(int_vector.back(), int_vector_std.back());
    int_vector.pop_back();
    int_vector_std.pop_back();
  }
}

TEST_F(VectorTest, TestInsertManyBack2) {
  int_vector.insert_many_back(1, 2, 3, 4, 5, 6, 7, 8);
  for (int i = 1; i <= 8; i++) {
    int_vector_std.push_back(i);
  }
  ASSERT_EQ(int_vector.size(), int_vector_std.size());
  ASSERT_EQ(int_vector.capacity(), int_vector_std.capacity());
  while (!int_vector.empty() && !int_vector_std.empty()) {
    ASSERT_EQ(int_vector.back(), int_vector_std.back());
    int_vector.pop_back();
    int_vector_std.pop_back();
  }
}
