#ifndef SRC_INCLUDE_SEQUENCE_S21_STACK_H
#define SRC_INCLUDE_SEQUENCE_S21_STACK_H

#include <initializer_list>
#include <utility>

#include "s21_list.h"

namespace s21 {
template <class T, class Container = s21::list<T>>
class Stack {
 public:
  using value_type = typename Container::value_type;
  using reference = typename Container::reference;
  using const_reference = typename Container::const_reference;
  using size_type = typename Container::size_type;

  Stack() : base_class_(){};

  Stack(std::initializer_list<T> const &items) : base_class_(items){};

  Stack(const Stack &s) : base_class_(s.base_class_){};

  Stack(Stack &&s) noexcept : base_class_(std::move(s.base_class_)){};

  Stack &operator=(Stack &&s) noexcept {
    base_class_ = std::move(s.base_class_);
    return *this;
  };

  Stack &operator=(const Stack &s) {
    base_class_ = (s.base_class_);
    return *this;
  };

  ~Stack(){};

  const_reference top() const { return base_class_.back(); };

  bool empty() const { return base_class_.empty(); };

  size_type size() const { return base_class_.size(); };

  void push(const_reference value) { base_class_.push_back(value); };

  void pop() { base_class_.pop_back(); };

  void swap(Stack &other) { base_class_.swap(other.base_class_); };

  template <class... Args>
  void insert_many_front(Args &&...args) {
    for (auto i : {args...}) {
      push(i);
    }
  }

 private:
  Container base_class_;
};
}  // namespace s21

#endif  //  SRC_INCLUDE_SEQUENCE_S21_STACK_H
