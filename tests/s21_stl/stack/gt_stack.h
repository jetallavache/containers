#ifndef SRC_TESTS_S21_STL_STACK_GT_STACK_H_
#define SRC_TESTS_S21_STL_STACK_GT_STACK_H_

#include <gtest/gtest.h>

#include <stack>

#include "../../../include/s21_containers.h"

class StackTest : public ::testing::Test {
 public:
  s21::Stack<int> empty_stack;
  std::stack<int> empty_stack_original;
  s21::Stack<int> *int_stack;
  std::stack<int> *int_stack_original;
  s21::Stack<int> *my_stack;
  std::stack<int> *original_stack;
  void SetUp() override {
    int_stack = new s21::Stack<int>;
    int_stack_original = new std::stack<int>;
    int_stack->push(324);
    int_stack->push(768678);
    int_stack->push(54342);
    int_stack->push(6563);
    int_stack_original->push(324);
    int_stack_original->push(768678);
    int_stack_original->push(54342);
    int_stack_original->push(6563);
    my_stack = new s21::Stack<int>;
    original_stack = new std::stack<int>;
    for (int i = 0; i <= 5; i++) {
      my_stack->push(i);
      original_stack->push(i);
    }
  }
  void TearDown() override {
    delete int_stack;
    delete int_stack_original;
    delete my_stack;
    delete original_stack;
  }
};

#endif  // SRC_TESTS_S21_STL_STACK_GT_STACK_H_