#ifndef SRC_TESTS_S21_STL__VECTOR_GT_VECTOR_H_
#define SRC_TESTS_S21_STL__VECTOR_GT_VECTOR_H_

#include <gtest/gtest.h>

#include <vector>

#include "../../../include/s21_containers.h"

class VectorTest : public ::testing::Test {
 public:
  s21::Vector<int> int_vector = {1, 2, 3, 4, 5, 6};
  s21::Vector<int> const const_vector = {1, 2, 3, 4, 5, 6};
  s21::Vector<float> float_vector = {1.342, 2.123, 3.978, 4.43, 5.3, 0};
  s21::Vector<double> double_vector = {4.34, 42.1123, 23.123, 6.43, 5.31, 0.02};
  s21::Vector<char> char_vector = {'a', 'b', 'c', 'd'};
  s21::Vector<std::string> string_vector = {"one", "two", "three"};
  s21::Vector<int> empty_vector;

  std::vector<int> int_vector_std = {1, 2, 3, 4, 5, 6};
  std::vector<int> const const_vector_std = {1, 2, 3, 4, 5, 6};
  std::vector<float> float_vector_std = {1.342, 2.123, 3.978, 4.43, 5.3, 0};
  std::vector<double> double_vector_std = {4.34, 42.1123, 23.123,
                                           6.43, 5.31,    0.02};
  std::vector<char> char_vector_std = {'a', 'b', 'c', 'd'};
  std::vector<std::string> string_vector_std = {"one", "two", "three"};
  std::vector<int> empty_vector_std;
};

#endif  // SRC_TESTS_S21_STL__VECTOR_GT_VECTOR_H_