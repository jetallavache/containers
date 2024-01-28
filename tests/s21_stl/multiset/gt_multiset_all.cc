#include "gt_multiset.h"

TEST_F(TestMultiset, DefaultConstructor) {
  s21::Multiset<int> ms;
  std::multiset<int> stdMs;
  ASSERT_EQ(stdMs.size(), ms.size());
}

TEST_F(TestMultiset, CopyConstructor) {
  s21::Multiset<int> ms1{1, 2, 2, 3, 3, 3};
  s21::Multiset<int> ms2(ms1);
  std::multiset<int> stdMs1{1, 2, 2, 3, 3, 3};
  std::multiset<int> stdMs2(stdMs1);
  ASSERT_EQ(stdMs2.size(), ms2.size());
}

TEST_F(TestMultiset, MoveConstructor) {
  s21::Multiset<int> ms1{1, 2, 2, 3, 3, 3};
  s21::Multiset<int> ms2(std::move(ms1));
  std::multiset<int> stdMs1{1, 2, 2, 3, 3, 3};
  std::multiset<int> stdMs2(std::move(stdMs1));
  ASSERT_EQ(stdMs2.size(), ms2.size());
}

TEST_F(TestMultiset, InitializerListConstructor) {
  s21::Multiset<int> ms{1, 2, 2, 3, 3, 3};
  std::multiset<int> stdMs{1, 2, 2, 3, 3, 3};
  ASSERT_EQ(stdMs.size(), ms.size());
}

TEST_F(TestMultiset, Destructor) {
  s21::Multiset<int>* ms = new s21::Multiset<int>{1, 2, 2, 3, 3, 3};
  delete ms;
}

TEST_F(TestMultiset, Insert) {
  s21::Multiset<int> ms;
  std::multiset<int> stdMs;

  ms.insert(1);
  stdMs.insert(1);
  ms.insert(2);
  stdMs.insert(2);
  ms.insert(2);
  stdMs.insert(2);

  ASSERT_EQ(stdMs.count(1), ms.count(1));
  ASSERT_EQ(stdMs.count(2), ms.count(2));
}

TEST_F(TestMultiset, Erase) {
  s21::Multiset<int> ms{1, 2, 2, 3, 3, 3};
  std::multiset<int> stdMs{1, 2, 2, 3, 3, 3};

  ms.erase(ms.find(2));
  stdMs.erase(stdMs.find(2));

  ASSERT_EQ(stdMs.size(), ms.size());
}

TEST_F(TestMultiset, LowerBound) {
  s21::Multiset<int> ms{1, 2, 3, 4, 5};
  auto it = ms.lower_bound(3);
  ASSERT_EQ(*it, 3);
}

TEST_F(TestMultiset, UpperBound) {
  s21::Multiset<int> ms{1, 2, 3, 4, 5};
  auto it = ms.upper_bound(3);
  ASSERT_EQ(*it, 4);
}

TEST_F(TestMultiset, Count) {
  s21::Multiset<int> ms{1, 2, 2, 3, 3, 3};
  ASSERT_EQ(ms.count(1), 1);
  ASSERT_EQ(ms.count(2), 2);
  ASSERT_EQ(ms.count(3), 3);
  ASSERT_EQ(ms.count(4), 0);
}

TEST_F(TestMultiset, Merge) {
  s21::Multiset<int> ms1{1, 2, 3};
  s21::Multiset<int> ms2{4, 5, 6};
  ms1.merge(ms2);
  ASSERT_EQ((int)ms1.size(), 6);
  ASSERT_EQ((int)ms2.size(), 0);
}

TEST_F(TestMultiset, Swap) {
  s21::Multiset<int> ms1{1, 2, 3};
  s21::Multiset<int> ms2{4, 5, 6};
  ms1.swap(ms2);
  ASSERT_EQ((int)ms1.size(), 3);
  ASSERT_EQ((int)ms2.size(), 3);
}

TEST_F(TestMultiset, Find) {
  s21::Multiset<int> ms{1, 2, 2, 3, 3, 3};
  auto it = ms.find(2);
  ASSERT_NE(it, ms.end());
  ASSERT_EQ(*it, 2);
}

TEST_F(TestMultiset, EqualRange) {
  s21::Multiset<int> ms{1, 2, 2, 3, 3, 3};
  auto range = ms.equal_range(3);
  int count = 0;
  for (auto it = range.first; it != range.second; ++it) {
    count++;
  }
  ASSERT_EQ(count, 3);
}

TEST_F(TestMultiset, MoveAssignment) {
  s21::Multiset<int> ms1{1, 2, 2, 3, 3, 3};
  s21::Multiset<int> ms2{4, 5, 6};
  ms2 = std::move(ms1);
  ASSERT_EQ((int)ms2.size(), 6);
  ASSERT_EQ((int)ms1.size(), 0);
}

TEST_F(TestMultiset, InitializerListAssignment) {
  s21::Multiset<int> ms;
  ms = {1, 2, 3, 4, 5};
  ASSERT_EQ((int)ms.size(), 5);
}

TEST_F(TestMultiset, Empty) {
  s21::Multiset<int> ms;
  ASSERT_TRUE(ms.empty());

  ms.insert(1);
  ASSERT_FALSE(ms.empty());

  ms.clear();
  ASSERT_TRUE(ms.empty());
}

TEST_F(TestMultiset, Contains) {
  s21::Multiset<int> ms{1, 2, 2, 3, 3, 3};
  ASSERT_TRUE(ms.contains(2));
  ASSERT_FALSE(ms.contains(4));
}

TEST_F(TestMultiset, Size) {
  s21::Multiset<int> ms{1, 2, 2, 3, 3, 3};
  ASSERT_EQ((int)ms.size(), 6);

  ms.erase(ms.find(1));
  ASSERT_EQ((int)ms.size(), 5);
}

TEST_F(TestMultiset, Iterator) {
  s21::Multiset<int> ms{1, 2, 3, 4, 5};
  std::vector<int> values;
  for (auto it = ms.begin(); it != ms.end(); ++it) {
    values.push_back(*it);
  }

  std::vector<int> expected_values{1, 2, 3, 4, 5};
  ASSERT_EQ(values, expected_values);
}

TEST_F(TestMultiset, MultiSetMoveAssignment) {
  s21::Multiset<int> ms1{1, 2, 3, 4, 5};
  s21::Multiset<int> ms2{6, 7, 8, 9, 10};
  ms1 = std::move(ms2);
  ASSERT_EQ((int)ms1.size(), 5);
  ASSERT_TRUE(ms2.empty());
}

TEST_F(TestMultiset, Clear) {
  s21::Multiset<int> ms{1, 2, 2, 3, 3, 3};
  ms.clear();
  ASSERT_TRUE(ms.empty());
}

TEST_F(TestMultiset, InitializerListConstructorDifferentType) {
  s21::Multiset<std::string> ms{"apple", "banana", "cherry"};
  ASSERT_EQ((int)ms.size(), 3);
}

TEST_F(TestMultiset, MultiSetFind) {
  s21::Multiset<int> ms{1, 2, 2, 3, 3, 3};
  auto it = ms.find(2);
  ASSERT_NE(it, ms.end());
  ASSERT_EQ(*it, 2);
}

TEST_F(TestMultiset, InsertionAndCount) {
  s21::Multiset<double> ms{1.1, 1.2, 1.3, 1.2, 1.3, 1.3};
  ms.insert(1.2);
  ms.insert(1.4);
  ASSERT_EQ(ms.count(1.2), 3);
  ASSERT_EQ(ms.count(1.3), 3);
  ASSERT_EQ(ms.count(1.4), 1);
}

TEST_F(TestMultiset, CopyConstructorDifferentType) {
  s21::Multiset<char> ms{'a', 'b', 'b', 'c', 'c', 'c'};
  s21::Multiset<char> ms_copy(ms);
  ASSERT_EQ(ms.size(), ms_copy.size());
}

TEST_F(TestMultiset, MultiSetLowerBound) {
  s21::Multiset<int> ms{1, 2, 4, 5, 6};
  auto it = ms.lower_bound(3);
  ASSERT_EQ(*it, 4);
}

TEST_F(TestMultiset, MultiSetUpperBound) {
  s21::Multiset<int> ms{1, 2, 4, 5, 6};
  auto it = ms.upper_bound(3);
  ASSERT_EQ(*it, 4);
}

TEST_F(TestMultiset, InsertionAndCount1) {
  s21::Multiset<double> ms{1, 2, 3, 4};
  ms.insert(0);
  ASSERT_EQ((int)ms.size(), 5);
}

TEST_F(TestMultiset, InsertionAndCount2) {
  s21::Multiset<double> ms{1, 2, 3, 4};
  ms.insert(1);
  ASSERT_EQ((int)ms.size(), 5);
}

TEST_F(TestMultiset, EmptyMultiset) {
  s21::Multiset<int> ms;
  ASSERT_TRUE(ms.empty());
  ms.insert(1);
  ASSERT_FALSE(ms.empty());
}

TEST_F(TestMultiset, Count2) {
  s21::Multiset<int> ms{1, 2, 2, 3, 3, 3};
  ASSERT_EQ(ms.count(2), 2);
  ASSERT_EQ(ms.count(3), 3);
  ASSERT_EQ(ms.count(4), 0);
}

TEST_F(TestMultiset, Erase2) {
  s21::Multiset<int> ms{1, 2, 3, 4, 4, 5};
  ms.erase(ms.find(4));
  ASSERT_EQ(ms.count(4), 1);
  ms.erase(ms.find(4));
  ASSERT_EQ(ms.count(4), 0);
}

TEST_F(TestMultiset, Iterator2) {
  s21::Multiset<int> ms{1, 2, 3, 4, 4, 5};
  std::vector<int> expected = {1, 2, 3, 4, 4, 5};
  std::vector<int> actual;

  for (auto it = ms.begin(); it != ms.end(); ++it) {
    actual.push_back(*it);
  }

  ASSERT_EQ(expected, actual);
}

TEST_F(TestMultiset, Clear2) {
  s21::Multiset<int> ms{1, 2, 3, 4, 4, 5};
  ms.clear();
  ASSERT_TRUE(ms.empty());
}

TEST_F(TestMultiset, EqualRange2) {
  s21::Multiset<int> ms{1, 2, 2, 3, 3, 3};
  auto pair = ms.equal_range(2);
  size_t count = 0;
  for (auto it = pair.first; it != pair.second; ++it) {
    ++count;
  }
  ASSERT_EQ(count, 2);
}

TEST_F(TestMultiset, LowerBound2) {
  s21::Multiset<int> ms{1, 2, 3, 5, 5, 5};
  auto it = ms.lower_bound(4);
  ASSERT_EQ(*it, 5);
}

TEST_F(TestMultiset, UpperBound2) {
  s21::Multiset<int> ms{1, 2, 3, 5, 5, 5};
  auto it = ms.upper_bound(4);
  ASSERT_EQ(*it, 5);
}

TEST_F(TestMultiset, Initialization) {
  s21::Multiset<int> ms1;
  ASSERT_TRUE(ms1.empty());
  s21::Multiset<int> ms2{1, 2, 3, 3, 4, 4, 5};
  ASSERT_EQ((int)ms2.size(), 7);
}

TEST_F(TestMultiset, CopyConstructor2) {
  s21::Multiset<int> ms1{1, 2, 3, 3, 4, 4, 5};
  s21::Multiset<int> ms2(ms1);
  ASSERT_EQ(ms1.size(), ms2.size());
}
