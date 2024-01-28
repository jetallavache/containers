#ifndef SRC_INCLUDE_SEQUENCE_S21_ARRAY_H
#define SRC_INCLUDE_SEQUENCE_S21_ARRAY_H

#include <initializer_list>
#include <stdexcept>
#include <utility>

namespace S21 {
template <class T, size_t n>
class Array {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  Array();
  Array(std::initializer_list<T> const &items);
  Array(const Array &a);
  Array(Array &&a) noexcept;
  ~Array();

  Array<T, n> &operator=(Array &&a);

  reference at(size_type pos) const;
  reference operator[](size_type pos) const;
  const_reference front() const;
  const_reference back() const;
  iterator data();

  iterator begin() const;
  iterator end() const;
  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  void swap(Array &other);
  void fill(const_reference value);

 private:
  T *array_;
  size_type size_;
  void ZeroArray();
  void MemoryAllocation(size_t size);
};

template <class T, size_t n>
Array<T, n>::Array() {
  ZeroArray();
}

template <class T, size_t n>
Array<T, n>::Array(std::initializer_list<T> const &items) {
  MemoryAllocation(items.size());
  std::copy(items.begin(), items.end(), array_);
}

template <class T, size_t n>
Array<T, n>::Array(const Array &a) {
  MemoryAllocation(a.size_);
  std::copy(a.array_, a.array_ + a.size_, array_);
}

template <class T, size_t n>
Array<T, n>::Array(Array &&a) noexcept {
  size_ = a.size_;
  array_ = a.array_;
  a.ZeroArray();
}

template <class T, size_t n>
Array<T, n>::~Array() {
  delete[] array_;
  ZeroArray();
}

template <class T, size_t n>
Array<T, n> &Array<T, n>::operator=(Array &&a) {
  if (this != &a) {
    throw std::logic_error("The sizes of arrays do not match");
  }
  for (int i = 0; i < size_; i++) {
    array_[i] = a.array_[i];
  }
  return *this;
}

template <class T, size_t n>
typename Array<T, n>::reference Array<T, n>::at(size_type pos) const {
  if (pos >= size_) {
    throw std::out_of_range("Index out of range");
  }
  return array_[pos];
}

template <class T, size_t n>
typename Array<T, n>::reference Array<T, n>::operator[](size_type pos) const {
  return array_[pos];
}

template <class T, size_t n>
typename Array<T, n>::const_reference Array<T, n>::front() const {
  return array_[0];
}

template <class T, size_t n>
typename Array<T, n>::const_reference Array<T, n>::back() const {
  return array_[size_ - 1];
}

template <class T, size_t n>
typename Array<T, n>::iterator Array<T, n>::data() {
  return array_;
}

template <class T, size_t n>
bool Array<T, n>::empty() const {
  return size_ == 0;
}

template <class T, size_t n>
size_t Array<T, n>::size() const {
  return size_;
}

template <class T, size_t n>
size_t Array<T, n>::max_size() const {
  return n;
}

template <class T, size_t n>
void Array<T, n>::swap(Array &other) {
  std::swap(array_, other.array_);
}
template <class T, size_t n>
void Array<T, n>::fill(const_reference value) {
  for (size_type i = 0; i < size_; i++) {
    array_[i] = value;
  }
}

template <class T, size_t n>
typename Array<T, n>::iterator Array<T, n>::begin() const {
  return array_;
}

template <class T, size_t n>
typename Array<T, n>::iterator Array<T, n>::end() const {
  return array_ + size_;
}

template <class T, size_t n>
void Array<T, n>::MemoryAllocation(size_t size) {
  size_ = size;
  array_ = new T[size_]{};
}

template <class T, size_t n>
void Array<T, n>::ZeroArray() {
  array_ = nullptr;
  size_ = 0;
}
}  // namespace S21

#endif
