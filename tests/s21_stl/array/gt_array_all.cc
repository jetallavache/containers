#include "gt_array.h"

TEST_F(ArrayTest, At) {
  ASSERT_EQ(s21_int_array.at(0), 9);
  ASSERT_EQ(s21_int_array.at(5), 9);
  ASSERT_EQ(s21_int_array.at(8), 3);
}
TEST_F(ArrayTest, At1) {
  s21_int_array.at(4) = 17;
  int_array_std.at(4) = 17;
  ASSERT_EQ(s21_int_array.at(4), int_array_std.at(4));
}

TEST_F(ArrayTest, At2) {
  EXPECT_THROW(s21_int_array.at(23), std::out_of_range);
}

TEST_F(ArrayTest, OperatorBrackets) {
  ASSERT_EQ(s21_int_array[0], 9);
  ASSERT_EQ(s21_int_array[5], 9);
  ASSERT_EQ(s21_int_array[8], 3);
}

TEST_F(ArrayTest, CopyOperator) {
  S21::Array<int, 5> arr = {0, 9, 8, 7, 6};
  S21::Array<int, 5> copy_arr = arr;
  ASSERT_EQ(copy_arr[0], 0);
  ASSERT_EQ(copy_arr[1], 9);
  ASSERT_EQ(copy_arr[4], 6);
}

TEST_F(ArrayTest, Front) {
  ASSERT_EQ(s21_double_array.front(), double_array_std.front());
}

TEST_F(ArrayTest, Back) {
  ASSERT_EQ(s21_float_array.back(), float_array_std.back());
}

TEST_F(ArrayTest, Data) {
  S21::Array<char, 5> s21_array = {'a', 'b', 'c', 'd', 'e'};
  std::array<char, 5> array_std = {'a', 'b', 'c', 'd', 'e'};
  auto ptr = s21_array.data();
  auto ptr_std = array_std.data();
  ASSERT_EQ(ptr[3], ptr_std[3]);
}

TEST_F(ArrayTest, Begin) {
  S21::Array<int, 5> s21_array = {0, 9, 8, 7, 6};
  std::array<int, 5> array_std = {0, 9, 8, 7, 6};
  auto ptr = s21_array.begin();
  auto ptr_std = array_std.begin();
  ASSERT_EQ(ptr[0], ptr_std[0]);
}

TEST_F(ArrayTest, End) {
  S21::Array<int, 5> s21_array = {7, 3, 7, 4, 1};
  std::array<int, 5> array_std = {7, 3, 7, 4, 1};
  auto ptr = s21_array.end();
  auto ptr_std = array_std.end();
  ASSERT_EQ(ptr[-1], ptr_std[-1]);
}

TEST_F(ArrayTest, Empty1) {
  S21::Array<int, 5> s21_array = {0, 9, 8, 7, 6};
  ASSERT_FALSE(s21_array.empty());
}
TEST_F(ArrayTest, Empty2) {
  S21::Array<int, 0> s21_array = {};
  ASSERT_TRUE(s21_array.empty());
}

TEST_F(ArrayTest, Size) { ASSERT_EQ((int)s21_float_array.size(), 9); }

TEST_F(ArrayTest, MaxSize) { ASSERT_EQ((int)s21_string_array.max_size(), 5); }

TEST_F(ArrayTest, Swap) {
  S21::Array<std::string, 5> s21_array_01 = {"cat", "dog", "pig", "cow",
                                             "sheep"};
  S21::Array<std::string, 5> s21_array_02 = {"Tom", "Alice", "Kate", "Bob",
                                             "Sam"};
  s21_array_01.swap(s21_array_02);
  ASSERT_EQ(s21_array_01[0], "Tom");
  ASSERT_EQ(s21_array_02[2], "pig");
}

TEST_F(ArrayTest, Fill) {
  S21::Array<int, 5> s21_array = {0, 9, 8, 7, 6};
  s21_array.fill(1);
  ASSERT_EQ(s21_array.at(0), 1);
  ASSERT_EQ(s21_array.at(3), 1);
}
