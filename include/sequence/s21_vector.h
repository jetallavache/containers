#ifndef SRC_INCLUDE_SEQUENCE_S21_VECTOR_H
#define SRC_INCLUDE_SEQUENCE_S21_VECTOR_H

#include <initializer_list>
#include <stdexcept>
#include <utility>

namespace s21 {

template <class T>
class Vector {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;
  using difference_type = std::ptrdiff_t;

  Vector();
  explicit Vector(size_type n);
  Vector(std::initializer_list<T> const &items);
  Vector(const Vector &v);
  Vector(Vector &&v) noexcept;
  ~Vector();

  Vector<T> &operator=(Vector &&v) noexcept;
  Vector<T> &operator=(const Vector &v);

  reference at(size_type pos);
  const_reference at(size_type pos) const;
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  const_reference front() const;
  const_reference back() const;
  iterator data();

  iterator begin() const;
  iterator end() const;

  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  void reserve(size_type size);
  size_type capacity() const;
  void shrink_to_fit();

  void clear();
  iterator insert(const_iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(Vector &other);

  template <class... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <class... Args>
  void insert_many_back(Args &&...args);

 private:
  T *vector_;
  size_type size_;
  size_type capacity_;
  void zero_vector();
  void memory_allocation(size_t n);
  void change_capacity(size_t n);
};

template <class T>
Vector<T>::Vector() {
  zero_vector();
}

template <class T>
Vector<T>::Vector(size_t n) {
  memory_allocation(n);
}

template <class T>
Vector<T>::Vector(std::initializer_list<T> const &items) {
  memory_allocation(items.size());
  std::copy(items.begin(), items.end(), vector_);
}

template <class T>
Vector<T>::Vector(const Vector &v) {
  memory_allocation(v.size_);
  std::copy(v.vector_, v.vector_ + v.size_, vector_);
}

template <class T>
Vector<T>::Vector(Vector &&v) noexcept
    : vector_(v.vector_), size_(v.size_), capacity_(v.capacity_) {
  v.zero_vector();
}

template <class T>
Vector<T>::~Vector() {
  delete[] vector_;
  zero_vector();
}

template <class T>
Vector<T> &Vector<T>::operator=(Vector &&v) noexcept {
  if (this != &v) {
    delete[] vector_;
    size_ = v.size_;
    capacity_ = v.capacity_;
    vector_ = v.vector_;
    v.zero_vector();
  }
  return *this;
}

template <class T>
Vector<T> &Vector<T>::operator=(const Vector &v) {
  if (this != &v) {
    delete[] vector_;
    vector_ = new T[v.capacity_];
    std::copy(v.vector_, v.vector_ + v.size_, vector_);
    size_ = v.size_;
    capacity_ = v.capacity_;
  }
  return *this;
}

template <class T>
typename Vector<T>::reference Vector<T>::at(size_type pos) {
  if (pos >= size_) {
    throw std::out_of_range("range check pos >= size_");
  }
  return vector_[pos];
}

template <class T>
typename Vector<T>::const_reference Vector<T>::at(size_type pos) const {
  if (pos >= size_) {
    throw std::out_of_range("range check pos >= size_");
  }
  return vector_[pos];
}

template <class T>
typename Vector<T>::reference Vector<T>::operator[](size_type pos) {
  return vector_[pos];
}

template <class T>
typename Vector<T>::const_reference Vector<T>::operator[](size_type pos) const {
  return vector_[pos];
}

template <class T>
typename Vector<T>::const_reference Vector<T>::front() const {
  return vector_[0];
}

template <class T>
typename Vector<T>::const_reference Vector<T>::back() const {
  return vector_[size_ - 1];
}

template <class T>
typename Vector<T>::iterator Vector<T>::data() {
  return vector_;
}

template <class T>
typename Vector<T>::iterator Vector<T>::begin() const {
  return vector_;
}

template <class T>
typename Vector<T>::iterator Vector<T>::end() const {
  return vector_ + size_;
}

template <class T>
bool Vector<T>::empty() const {
  return size_ == 0;
}
template <class T>
size_t Vector<T>::size() const {
  return size_;
}
template <class T>
size_t Vector<T>::max_size() const {
  return SIZE_MAX / sizeof(T);
}
template <class T>
void Vector<T>::reserve(size_type size) {
  if (size > capacity_) {
    change_capacity(size);
  }
}
template <class T>
size_t Vector<T>::capacity() const {
  return capacity_;
}

template <class T>
void Vector<T>::shrink_to_fit() {
  if (capacity_ > size_) {
    change_capacity(size_);
  }
}

template <class T>
void Vector<T>::clear() {
  size_ = 0;
  delete[] vector_;
  vector_ = nullptr;
}

template <class T>
typename Vector<T>::iterator Vector<T>::insert(const_iterator pos,
                                               const_reference value) {
  if (pos < begin() || pos > end()) {
    throw std::out_of_range("range check pos >= size_");
  }
  size_t position = pos - begin();
  push_back(value);
  for (size_t i = size_ - 1; i > position; i--) {
    std::swap(vector_[i], vector_[i - 1]);
  }
  return vector_ + position;
}

template <class T>
void Vector<T>::erase(iterator pos) {
  if (pos < begin() || pos > end()) {
    throw std::out_of_range("range check pos >= size_");
  }
  size_t position = pos - begin();
  for (size_t i = position; i < size_ - 1; i++) {
    std::swap(vector_[i], vector_[i + 1]);
  }
  size_ -= 1;
}

template <class T>
void Vector<T>::push_back(const_reference value) {
  if (size_ + 1 > capacity_) {
    reserve(size_ * 2);
  }
  vector_[size_] = value;
  size_ += 1;
}

template <class T>
void Vector<T>::pop_back() {
  size_ = size_ > 0 ? size_ - 1 : 0;
}

template <class T>
void Vector<T>::swap(Vector &other) {
  if (this != &other) {
    std::swap(vector_, other.vector_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
  }
}

template <class T>
template <class... Args>
typename Vector<T>::iterator Vector<T>::insert_many(const_iterator pos,
                                                    Args &&...args) {
  size_t position = pos - begin();
  for (auto i : {args...}) {
    insert(begin() + position, i);
    position++;
  }
  return begin() + position;
}

template <class T>
template <class... Args>
void Vector<T>::insert_many_back(Args &&...args) {
  for (auto i : {args...}) {
    push_back(i);
  }
}

template <class T>
void Vector<T>::zero_vector() {
  vector_ = nullptr;
  size_ = 0;
  capacity_ = 0;
}

template <class T>
void Vector<T>::memory_allocation(size_t n) {
  size_ = n;
  capacity_ = size_;
  vector_ = new T[size_]{};
}

template <class T>
void Vector<T>::change_capacity(size_t n) {
  T *tmp_vector = new T[n];
  std::copy(vector_, end(), tmp_vector);
  delete[] vector_;
  vector_ = tmp_vector;
  capacity_ = n;
}
}  // namespace s21

#endif  // SRC_INCLUDE_SEQUENCE_S21_VECTOR_H
