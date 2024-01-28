#include "gt_list.h"

TEST_F(TestList, Constructor_default) {
  s21::list<double> l;
  EXPECT_EQ(0, (int)l.size());
  EXPECT_EQ(l.head_, l.tail_);
}

TEST_F(TestList, Constructor_list_copy1) {
  s21::list<int> copy_s21{1, 2, 3, 4, 5};
  s21::list<int> copy_list(copy_s21);
  EXPECT_EQ(copy_s21.front(), copy_list.front());
  EXPECT_EQ(copy_s21.back(), copy_list.back());
  EXPECT_EQ(copy_s21.size(), copy_list.size());
}

TEST_F(TestList, Constructor_list_copy2) {
  s21::list<int> copy_s21(5);
  s21::list<int> copy_list(copy_s21);
  EXPECT_EQ(copy_s21.size(), copy_list.size());
}

TEST_F(TestList, With_parameter) {
  s21::list<double> l1(5);
  EXPECT_EQ((int)l1.size(), 5);
  EXPECT_EQ(l1.front(), 0);
}

TEST_F(TestList, Constructor_list_size) {
  s21::list<int> empty_s21;
  s21::list<int> list_s21{1, 2, 3};
  s21::list<int> list_s21_2{1, 2, 3, 21};
  ASSERT_EQ((int)empty_s21.size(), 0);
  ASSERT_EQ((int)list_s21.size(), 3);
  ASSERT_EQ((int)list_s21_2.size(), 4);
}

TEST_F(TestList, Constructor_list_move) {
  s21::list<int> list_s21{1, 2, 3, 21};
  s21::list<int> list_s21_2(std::move(list_s21));
  ASSERT_EQ((int)list_s21_2.size(), 4);
  EXPECT_EQ(list_s21_2.front(), 1);
  EXPECT_EQ(list_s21_2.back(), 21);
}

TEST_F(TestList, Constructor_list_move_empty) {
  s21::list<int> list_s21empty;
  s21::list<int> list_s21_2(std::move(list_s21empty));
  ASSERT_EQ((int)list_s21_2.size(), 0);
}

TEST_F(TestList, Push_back) {
  s21::list<int> list_s21;
  list_s21.push_back(2);
  list_s21.push_back(0);
  list_s21.push_back(2);
  list_s21.push_back(4);
  EXPECT_EQ((int)list_s21.size(), 4);
  EXPECT_EQ(list_s21.front(), 2);
  EXPECT_EQ(list_s21.back(), 4);
}

TEST_F(TestList, Push_front) {
  s21::list<int> list_s21;
  list_s21.push_front(2);
  list_s21.push_front(0);
  list_s21.push_front(2);
  list_s21.push_front(4);
  EXPECT_EQ((int)list_s21.size(), 4);
  EXPECT_EQ(list_s21.front(), 4);
  EXPECT_EQ(list_s21.back(), 2);
}

TEST_F(TestList, Pop_back) {
  s21::list<int> list_s21;
  list_s21.push_back(2);
  list_s21.push_back(0);
  list_s21.push_back(2);
  list_s21.push_back(4);
  list_s21.pop_back();
  EXPECT_EQ((int)list_s21.size(), 3);
  EXPECT_EQ(list_s21.front(), 2);
  EXPECT_EQ(list_s21.back(), 2);
}

TEST_F(TestList, Pop_front) {
  s21::list<int> list_s21;
  list_s21.push_back(2);
  list_s21.push_back(0);
  list_s21.push_back(2);
  list_s21.push_back(4);
  list_s21.pop_front();
  EXPECT_EQ((int)list_s21.size(), 3);
  EXPECT_EQ(list_s21.front(), 0);
  EXPECT_EQ(list_s21.back(), 4);
}

TEST_F(TestList, Erase) {
  s21::list<int> list_s21{21, 2, 21, 21, 2024};
  list_s21.erase(list_s21.begin());
  EXPECT_EQ(list_s21.front(), 2);
  EXPECT_EQ(list_s21.back(), 2024);
  EXPECT_EQ((int)list_s21.size(), 4);
}

TEST_F(TestList, Erase2) {
  s21::list<int> list_s21{21, 1, 2, 3, 2024};
  auto r = ++list_s21.begin();
  list_s21.erase(r);
  EXPECT_EQ(list_s21.front(), 21);
  EXPECT_EQ(list_s21.back(), 2024);
  EXPECT_EQ((int)list_s21.size(), 4);
}

TEST_F(TestList, sort) {
  s21::list<int> list_s21{21, 1, 2, 3, 2024};
  list_s21.sort();
  EXPECT_EQ(list_s21.front(), 1);
  EXPECT_EQ(list_s21.back(), 2024);
  EXPECT_EQ((int)list_s21.size(), 5);
}

TEST_F(TestList, sort2) {
  s21::list<int> list_s21{2, 1, 2, 3, -2};
  list_s21.sort();
  EXPECT_EQ(list_s21.front(), -2);
  EXPECT_EQ(list_s21.back(), 3);
  EXPECT_EQ((int)list_s21.size(), 5);
}

TEST_F(TestList, unique1) {
  s21::list<int> list_s21{21, 22, 23, 22, 24, 25, 17, 17, 888, 1};
  list_s21.unique();
  EXPECT_EQ(list_s21.front(), 21);
  EXPECT_EQ(list_s21.back(), 1);
  EXPECT_EQ((int)list_s21.size(), 9);
}

TEST_F(TestList, unique2) {
  s21::list<int> list_s21{21, 1, 1, 1, 2024, 21};
  list_s21.unique();
  EXPECT_EQ(list_s21.front(), 21);
  EXPECT_EQ(list_s21.back(), 21);
  EXPECT_EQ((int)list_s21.size(), 4);
}

TEST_F(TestList, unique3) {
  s21::list<int> list_s21{1, 1, 3, 1, 2, 4, 2, 2024, 2024, 5};
  list_s21.unique();
  EXPECT_EQ(list_s21.front(), 1);
  EXPECT_EQ(list_s21.back(), 5);
  EXPECT_EQ((int)list_s21.size(), 8);
}

TEST_F(TestList, unique4) {
  s21::list<int> l1 = {0, 0, 1, 2, 4, 2, 0, 2, 21, 2};
  l1.sort();
  l1.unique();
  EXPECT_EQ(l1.front(), 0);
  EXPECT_EQ(l1.back(), 21);
  EXPECT_EQ((int)l1.size(), 5);
}

TEST_F(TestList, unique5) {
  s21::list<int> l1 = {0, 2, 4, 6, 4, 2, 0};
  l1.unique();
  EXPECT_EQ(l1.front(), 0);
  EXPECT_EQ(l1.back(), 0);
  EXPECT_EQ((int)l1.size(), 7);
}

TEST_F(TestList, reverse) {
  s21::list<int> list_s21{21, 1, 2, 3, 2024};
  list_s21.reverse();
  EXPECT_EQ(list_s21.front(), 2024);
  EXPECT_EQ(list_s21.back(), 21);
  EXPECT_EQ((int)list_s21.size(), 5);
}

TEST_F(TestList, reverse2) {
  s21::list<int> list_s21{1, 2, 3, 4, 5};
  list_s21.reverse();
  EXPECT_EQ(list_s21.front(), 5);
  EXPECT_EQ(list_s21.back(), 1);
  EXPECT_EQ((int)list_s21.size(), 5);
}

TEST_F(TestList, clear) {
  s21::list<int> list_s21{21, 1, 2, 3, 2024};
  list_s21.clear();
  EXPECT_EQ((int)list_s21.size(), 0);
  EXPECT_EQ(list_s21.empty(), true);
}

TEST_F(TestList, empty) {
  s21::list<int> list_s21{21, 1, 2, 3, 2024};
  EXPECT_EQ(list_s21.empty(), false);
  list_s21.clear();
  EXPECT_EQ(list_s21.empty(), true);
}

TEST_F(TestList, size) {
  s21::list<int> list_s21{21, 1, 2, 3, 2024};
  EXPECT_EQ((int)list_s21.size(), 5);
  list_s21.clear();
  EXPECT_EQ((int)list_s21.size(), 0);
}

TEST_F(TestList, front) {
  s21::list<int> list_s21{21, 1, 2, 3, 2024};
  EXPECT_EQ(list_s21.front(), 21);
}

TEST_F(TestList, back) {
  s21::list<int> list_s21{21, 1, 2, 3, 2024};
  EXPECT_EQ(list_s21.back(), 2024);
}

TEST_F(TestList, insert) {
  s21::list<int> list_s21{21, 1, 2, 3, 2024};
  list_s21.insert(list_s21.begin(), 888);
  EXPECT_EQ(list_s21.front(), 888);
  EXPECT_EQ(list_s21.back(), 2024);
  EXPECT_EQ((int)list_s21.size(), 6);
}

TEST_F(TestList, insert2) {
  s21::list<int> list_s21{21, 1, 2, 3, 2024};
  list_s21.insert(list_s21.end(), 888);
  EXPECT_EQ(list_s21.front(), 21);
  EXPECT_EQ(list_s21.back(), 888);
  EXPECT_EQ((int)list_s21.size(), 6);
}

TEST_F(TestList, merge) {
  s21::list<int> list_s21{21, 1, 2, 3, 2024};
  s21::list<int> list_s21_2{888, 8888, 88888, 888888, 8888888};
  list_s21.merge(list_s21_2);
  EXPECT_EQ(list_s21.front(), 21);
  EXPECT_EQ(list_s21.back(), 8888888);
  EXPECT_EQ((int)list_s21.size(), 10);
}

TEST_F(TestList, splice) {
  s21::list<int> list_s21{21, 1, 2, 2024};
  s21::list<int> list_s21_2{1, 5, 6, 42};
  auto it = list_s21.begin();
  list_s21.splice(it, list_s21_2);
  EXPECT_EQ(list_s21.front(), 1);
  EXPECT_EQ(list_s21.back(), 2024);
  EXPECT_EQ((int)list_s21.size(), 8);
}

TEST_F(TestList, erase2) {
  std::list<int> l1 = {1, 2, 3, 4, 5};
  s21::list<int> l2 = {1, 2, 3, 4, 5};
  auto iter1 = ++l1.begin();
  auto iter2 = ++l2.begin();
  l1.erase(iter1);
  l2.erase(iter2);
  EXPECT_EQ(l1.front(), l2.front());
  EXPECT_EQ(l1.size(), l2.size());
}

TEST_F(TestList, splice2) {
  s21::list<int> b1 = {1, 2};
  s21::list<int> b2 = {3, 4, 5};
  b1.splice(b1.end(), b2);
  EXPECT_EQ(1, b1.front());
  EXPECT_EQ(5, b1.back());
  EXPECT_EQ(5, (int)b1.size());
}

TEST_F(TestList, swap) {
  std::list<int> a1 = {1, 2, 3};
  std::list<int> a2 = {3, 4, 5, 6};
  a1.swap(a2);
  s21::list<int> b1 = {1, 2, 3};
  s21::list<int> b2 = {3, 4, 5, 6};
  b1.swap(b2);
  EXPECT_EQ(a1.front(), b1.front());
  EXPECT_EQ(a1.back(), b1.back());
  EXPECT_EQ(a1.size(), b1.size());
}

TEST_F(TestList, string) {
  s21::list<std::string> list_s21{"Hello", "World", "!"};
  EXPECT_EQ((int)list_s21.size(), 3);
  EXPECT_EQ(list_s21.front(), "Hello");
  EXPECT_EQ(list_s21.back(), "!");
  list_s21.insert(list_s21.end(), " s21");
  EXPECT_EQ((int)list_s21.size(), 4);
  EXPECT_EQ(list_s21.back(), " s21");
  list_s21.pop_front();
  EXPECT_EQ((int)list_s21.size(), 3);
  EXPECT_EQ(list_s21.front(), "World");
  EXPECT_EQ(list_s21.back(), " s21");
}

// bonus
TEST_F(TestList, insert_many_test1) {
  s21::list<int> list_s21{21, 1, 2, 3, 2024};
  auto r = list_s21.insert_many(list_s21.begin(), 888, 8888, 88888);
  EXPECT_EQ(list_s21.front(), 888);
  EXPECT_EQ(list_s21.back(), 2024);
  EXPECT_EQ((int)list_s21.size(), 8);
}

TEST_F(TestList, insert_many_test2) {
  s21::list<int> list_s21{1, 2, 3, 4, 5, 6};
  auto it = list_s21.begin();
  it++;
  it++;
  it++;
  auto r = list_s21.insert_many(it, 21, 21, 21);
  EXPECT_EQ(list_s21.front(), 1);
  EXPECT_EQ(list_s21.back(), 6);
  EXPECT_EQ((int)list_s21.size(), 9);
  list_s21.sort();
  EXPECT_EQ(list_s21.front(), 1);
  EXPECT_EQ(list_s21.back(), 21);
  EXPECT_EQ((int)list_s21.size(), 9);
  list_s21.pop_back();
  EXPECT_EQ(list_s21.back(), 21);
  EXPECT_EQ((int)list_s21.size(), 8);
  list_s21.pop_back();
  EXPECT_EQ(list_s21.back(), 21);
  EXPECT_EQ((int)list_s21.size(), 7);
  list_s21.pop_back();
  EXPECT_EQ(list_s21.back(), 6);
  EXPECT_EQ((int)list_s21.size(), 6);
}

TEST_F(TestList, insert_many_test3) {
  s21::list<int> list_s21{1, 1, 2, 4, 5, 6};
  auto it = list_s21.begin();
  it++;
  it++;
  it++;
  auto r = list_s21.insert_many(it, 21, 21, 21);
  EXPECT_EQ(list_s21.front(), 1);
  EXPECT_EQ(list_s21.back(), 6);
  EXPECT_EQ((int)list_s21.size(), 9);
  list_s21.unique();
  EXPECT_EQ(list_s21.front(), 1);
  EXPECT_EQ(list_s21.back(), 6);
  EXPECT_EQ((int)list_s21.size(), 6);
}

TEST_F(TestList, insert_many_test4) {
  s21::list<int> list_s21{1, 1, 2, 4, 5, 6};
  auto it = list_s21.begin();
  it++;
  it++;
  it++;
  auto r = list_s21.insert_many(it, 21, 21, 1);
  EXPECT_EQ(list_s21.front(), 1);
  EXPECT_EQ(list_s21.back(), 6);
  EXPECT_EQ((int)list_s21.size(), 9);
  list_s21.unique();
  EXPECT_EQ(list_s21.front(), 1);
  EXPECT_EQ(list_s21.back(), 6);
  EXPECT_EQ((int)list_s21.size(), 7);
}

TEST_F(TestList, insert_many_front1) {
  s21::list<int> list_s21{1, 2, 3, 4, 5, 6};
  list_s21.insert_many_front(21, 21, 21);
  EXPECT_EQ(list_s21.front(), 21);
  EXPECT_EQ(list_s21.back(), 6);
  EXPECT_EQ((int)list_s21.size(), 9);
  list_s21.sort();
  EXPECT_EQ(list_s21.back(), 21);
}

TEST_F(TestList, insert_many_front2) {
  s21::list<int> list_s21{21, 3, 4, 5, 6};
  list_s21.insert_many_front(21, 21, 21);
  EXPECT_EQ(list_s21.front(), 21);
  EXPECT_EQ(list_s21.back(), 6);
  EXPECT_EQ((int)list_s21.size(), 8);
  list_s21.unique();
  EXPECT_EQ(list_s21.front(), 21);
  EXPECT_EQ(list_s21.back(), 6);
  EXPECT_EQ((int)list_s21.size(), 5);
}

TEST_F(TestList, insert_many_back1) {
  s21::list<int> list_s21{1, 2, 3, 4, 5, 6};
  list_s21.insert_many_back(21, 21, 21);
  EXPECT_EQ(list_s21.front(), 1);
  EXPECT_EQ(list_s21.back(), 21);
  EXPECT_EQ((int)list_s21.size(), 9);
}

TEST_F(TestList, insert_many_back2) {
  s21::list<int> list_s21{1, 2, 3, 4, 5, 6};
  list_s21.insert_many_back(6, 7, 8, 9);
  EXPECT_EQ(list_s21.front(), 1);
  EXPECT_EQ(list_s21.back(), 9);
  EXPECT_EQ((int)list_s21.size(), 10);
  list_s21.pop_back();
  EXPECT_EQ(list_s21.back(), 8);
  list_s21.pop_back();
  EXPECT_EQ(list_s21.back(), 7);
}