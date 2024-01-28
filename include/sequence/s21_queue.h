#ifndef SRC_INCLUDE_SEQUENCE_S21_QUEUE_H
#define SRC_INCLUDE_SEQUENCE_S21_QUEUE_H

#include <initializer_list>
#include <utility>

#include "s21_list.h"

namespace s21 {
template <class T, class Container = s21::list<T>>
class queue {
 public:
  using value_type = typename Container::value_type;
  using reference = typename Container::reference;
  using const_reference = typename Container::const_reference;
  using size_type = typename Container::size_type;

  queue() : base_class_(){};

  queue(std::initializer_list<T> const &items) : base_class_(items){};

  queue(const queue &s) : base_class_(s.base_class_){};

  queue(queue &&s) noexcept : base_class_(std::move(s.base_class_)){};

  queue &operator=(queue &&s) noexcept {
    base_class_ = std::move(s.base_class_);
    return *this;
  };

  queue &operator=(const queue &s) {
    base_class_ = (s.base_class_);
    return *this;
  };

  ~queue(){};

  const_reference front() const { return base_class_.front(); };

  const_reference back() const { return base_class_.back(); };

  bool empty() const { return base_class_.empty(); };

  size_type size() const { return base_class_.size(); };

  void push(const_reference value) { base_class_.push_back(value); };

  void pop() { base_class_.pop_front(); };

  void swap(queue &other) { base_class_.swap(other.base_class_); };

  template <class... Args>
  void insert_many_back(Args &&...args) {
    for (auto i : {args...}) {
      push(i);
    }
  }

 private:
  Container base_class_;
};
}  // namespace s21

#endif  //  SRC_INCLUDE_SEQUENCE_S21_QUEUE_H
