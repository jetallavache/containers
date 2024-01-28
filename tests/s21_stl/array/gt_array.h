#ifndef SRC_TESTS_S21_STL_ARRAY_GT_ARRAY_H_
#define SRC_TESTS_S21_STL_ARRAY_GT_ARRAY_H_

#include <gtest/gtest.h>

#include <array>

#include "../../../include/s21_containersplus.h"

class ArrayTest : public ::testing::Test {
 public:
  void SetUp() override {}
  void TearDown() override {}

  S21::Array<int, 9> s21_int_array = {9, 12, 3, 0, 6, 9, 15, 132, 3};
  S21::Array<double, 9> s21_double_array = {
      9.12, 12.98, 15.456, 3.64, 132.6543, 0.825, 6.296, 9.74, 3.897};
  S21::Array<float, 9> s21_float_array = {5.567, 0.578, 5.534, 5.8, 5.5678,
                                          1.467, 2.915, 8.1,   2.97};
  S21::Array<char, 5> s21_char_array = {'a', 'b', 'c', 'd', 'e'};
  S21::Array<std::string, 5> s21_string_array = {"Tom", "Alice", "Kate", "Bob",
                                                 "Sam"};

  std::array<int, 9> int_array_std = {9, 12, 3, 0, 6, 9, 15, 132, 3};
  std::array<double, 9> double_array_std = {
      9.12, 12.98, 15.456, 3.64, 132.6543, 0.825, 6.296, 9.74, 3.897};
  std::array<float, 9> float_array_std = {5.567, 0.578, 5.534, 5.8, 5.5678,
                                          1.467, 2.915, 8.1,   2.97};
  std::array<char, 5> char_array_std = {'a', 'b', 'c', 'd', 'e'};
  std::array<std::string, 5> string_array_std = {"Tom", "Alice", "Kate", "Bob",
                                                 "Sam"};
};

#endif  // SRC_TESTS_S21_STL_ARRAY_GT_ARRAY_H_
