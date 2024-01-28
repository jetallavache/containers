#include "gt_stack.h"

TEST_F(StackTest, TestDefaultConstructor) {
  ASSERT_EQ(empty_stack.size(), empty_stack_original.size());
}

TEST_F(StackTest, TestCopyConstructor) {
  s21::Stack<int> my_stack_copy(*my_stack);
  std::stack<int> original_stack_copy(*original_stack);
  while (!my_stack_copy.empty() && !original_stack_copy.empty()) {
    ASSERT_EQ(my_stack_copy.top(), original_stack_copy.top());
    my_stack_copy.pop();
    original_stack_copy.pop();
  }
  ASSERT_EQ(my_stack_copy.empty(), original_stack_copy.empty());
}

TEST_F(StackTest, TestMoveConstructor) {
  s21::Stack<int> my_stack_copy(std::move(*my_stack));
  std::stack<int> original_stack_copy(std::move(*original_stack));
  while (!my_stack_copy.empty() && !original_stack_copy.empty()) {
    ASSERT_EQ(my_stack_copy.top(), original_stack_copy.top());
    my_stack_copy.pop();
    original_stack_copy.pop();
  }
  ASSERT_EQ(my_stack_copy.empty(), original_stack_copy.empty());
}

TEST_F(StackTest, TestCopyOperator) {
  s21::Stack<int> my_stack_copy = *my_stack;
  std::stack<int> original_stack_copy = *original_stack;
  while (!my_stack_copy.empty() && !original_stack_copy.empty()) {
    ASSERT_EQ(my_stack_copy.top(), original_stack_copy.top());
    my_stack_copy.pop();
    original_stack_copy.pop();
  }
  ASSERT_EQ(my_stack_copy.empty(), original_stack_copy.empty());
}

TEST_F(StackTest, TestMoveOperator) {
  s21::Stack<int> my_stack_copy = std::move(*my_stack);
  std::stack<int> original_stack_copy = std::move(*original_stack);
  while (!my_stack_copy.empty() && !original_stack_copy.empty()) {
    ASSERT_EQ(my_stack_copy.top(), original_stack_copy.top());
    my_stack_copy.pop();
    original_stack_copy.pop();
  }
  ASSERT_EQ(my_stack_copy.empty(), original_stack_copy.empty());
}

TEST_F(StackTest, TestTop) {
  ASSERT_EQ(my_stack->top(), original_stack->top());
}

TEST_F(StackTest, TestSize) {
  ASSERT_EQ(my_stack->size(), original_stack->size());
}

TEST_F(StackTest, TestSwap) {
  int_stack->swap(empty_stack);
  int_stack_original->swap(empty_stack_original);
  while (!int_stack->empty() && !int_stack_original->empty()) {
    ASSERT_EQ(int_stack->top(), int_stack_original->top());
    int_stack->pop();
    int_stack_original->pop();
  }
  ASSERT_EQ(int_stack->empty(), int_stack_original->empty());
}

TEST_F(StackTest, TestEmplaceFront) {
  int_stack->insert_many_front(481223);
  int_stack_original->emplace(481223);
  while (!int_stack->empty() && !int_stack_original->empty()) {
    ASSERT_EQ(int_stack->top(), int_stack_original->top());
    int_stack->pop();
    int_stack_original->pop();
  }
  ASSERT_EQ(int_stack->empty(), int_stack_original->empty());
}