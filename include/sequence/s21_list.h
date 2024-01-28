#ifndef SRC_INCLUDE_SEQUENCE_S21_LIST_H
#define SRC_INCLUDE_SEQUENCE_S21_LIST_H

#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <utility>

namespace s21 {
template <class T>
class list {
 public:
  template <class value_type>
  class Node {
   public:
    Node *next, *prev;
    value_type data;

    explicit Node(value_type data = value_type(), Node *prev = nullptr,
         Node *next = nullptr) {
      this->data = data;
      this->prev = prev;
      this->next = next;
    }
  };

  using A = class std::allocator<T>;
  using node_allocator =
      typename std::allocator_traits<A>::template rebind_alloc<list>;
  node_allocator allocator;

 public:
  template <class>
  class listIterator {
   public:
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using iterator = listIterator<T>;

    listIterator() { iter_ = nullptr; }

    explicit listIterator(int) : listIterator() {}

    listIterator(Node<value_type> *node) { iter_ = node; }

    listIterator(const listIterator &other) : iter_(other.iter_) {}

    ~listIterator() {}

    Node<value_type> *getIter() { return iter_; }
    listIterator operator++(int) {
      listIterator tmp(*this);
      iter_ = iter_->next;
      return tmp;
    }

    listIterator &operator++() {
      iter_ = iter_->next;
      return *this;
    }

    listIterator &operator+(int pos) {
      listIterator::iterator cur = getIter();
      int tmp = 0;
      while (tmp != pos) {
        tmp++;
        cur = cur.getIter()->next;
      }
      return cur;
    }

    listIterator operator--(int) {
      listIterator tmp = *this;
      --(*this);
      return tmp;
    }

    listIterator &operator--() {
      iter_ = iter_->prev;
      return *this;
    }

    reference operator*() {
      if (iter_) {
        return this->iter_->data;
      } else {
        return throw std::invalid_argument("null");
      }
    }

    bool operator==(const listIterator &other) const {
      return this->iter_ == other.iter_;
    }

    bool operator!=(const listIterator &other) const {
      return this->iter_ != other.iter_;
    }

    listIterator operator[](const value_type index) { return *(iter_ + index); }

   private:
    Node<value_type> *iter_;
    friend class list<value_type>;
  };

  template <class>
  class listConstIterator {
   public:
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using const_iterator = listConstIterator<T>;

    listConstIterator() { iter_ = nullptr; }

    explicit listConstIterator(int) : listConstIterator() {}

    listConstIterator(Node<value_type> *node) : listConstIterator() {
      iter_ = node;
    }

    listConstIterator(const listConstIterator &other) : iter_(other.iter_) {}

    ~listConstIterator() {}

    Node<value_type> *getIter() { return iter_; }
    listConstIterator operator++(int) {
      listConstIterator tmp(*this);
      iter_ = iter_->next;
      return tmp;
    }

    listConstIterator &operator++() {
      iter_ = iter_->next;
      return *this;
    }

    listConstIterator &operator+(int pos) {
      const_iterator cur = getIter();
      int tmp = 0;
      while (tmp != pos) {
        tmp++;
        cur = cur.getIter()->next;
      }
      return cur;
    }

    listConstIterator operator--(int) {
      listConstIterator tmp = *this;
      --(*this);
      return tmp;
    }

    listConstIterator &operator--() {
      iter_ = iter_->prev;
      return *this;
    }

    reference operator*() const {
      if (iter_)
        return this->iter_->data;
      else
        return throw std::invalid_argument("null");
    }

    listConstIterator &operator==(const listConstIterator &other) {
      return this->iter_ == other.iter_;
    }

    listConstIterator &operator!=(const listConstIterator &other) {
      return this->iter_ != other.iter_;
    }

    listConstIterator operator[](const value_type index) {
      return *(iter_ + index);
    }

   private:
    Node<value_type> *iter_;
    friend class list<value_type>;
  };

 public:
  using value_type = T;
  using size_type = size_t;
  using reference = T &;
  using const_reference = const T &;
  using iterator = listIterator<list>;
  using const_iterator = listConstIterator<list>;

  list();

  explicit list(size_type n);

  list(std::initializer_list<value_type> const &items);

  list(const list &l);

  list(list &&l) noexcept;

  ~list();

  Node<value_type> *head_, *tail_;
  size_type size_;

  const_reference front() const { return this->head_->data; }

  const_reference back() const { return this->tail_->prev->data; }

  iterator begin() const { return iterator(this->head_); }

  iterator end() const { return iterator(this->tail_); }

  bool empty() const { return size() == 0; }

  size_type size() const { return size_; }

  size_type max_size() { return allocator.max_size(); }

  void clear();
  void insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list &other);
  void merge(list &other);
  void splice(iterator pos, list &other);
  void reverse();
  void unique();
  void sort();

  template <typename... Args>
  iterator insert_many(iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);
  template <typename... Args>
  void insert_many_front(Args &&...args);
};

template <typename value_type>
list<value_type>::list() {
  tail_ = new Node<value_type>;
  head_ = tail_;
  size_ = 0;
}

template <typename value_type>
list<value_type>::list(size_type n) : list() {
  for (size_type i = 0; i < n; i++) {
    push_back(value_type());
  }
}

template <typename value_type>
list<value_type>::list(std::initializer_list<value_type> const &items)
    : list() {
  for (const auto &i : items) {
    push_back(i);
  }
}

template <typename value_type>
list<value_type>::list(const list &l) : list() {
  clear();
  iterator tmp = l.begin();
  while (tmp != l.end()) {
    this->push_back(tmp.getIter()->data);
    tmp++;
  }
}

template <typename value_type>
list<value_type>::list(list &&l) noexcept : list() {
  std::swap(head_, l.head_);
  std::swap(tail_, l.tail_);
  size_ = l.size_;
  l.size_ = 0;
}

template <typename value_type>
list<value_type>::~list() {
  while (head_ != nullptr) {
    pop_front();
  }
}

template <typename value_type>
void list<value_type>::clear() {
  while (!empty()) {
    erase(begin());
  }
}

template <typename value_type>
void list<value_type>::insert(iterator pos, const_reference value) {
  Node<value_type> *tmp = new Node<value_type>(value);
  iterator posNode_ = pos.iter_;
  if (posNode_ == begin()) {
    tmp->next = posNode_.getIter();
    posNode_.getIter()->prev = tmp;
    head_ = tmp;
  } else {
    tmp->next = posNode_.getIter();
    tmp->prev = posNode_.getIter()->prev;
    posNode_.getIter()->prev->next = tmp;
    posNode_.getIter()->prev = tmp;
  }
  size_++;
}

template <typename value_type>
void list<value_type>::erase(iterator pos) {
  if (pos == begin()) {
    pop_front();
    return;
  }
  if (pos == end()) {
    return;
  }
  for (auto i = head_; i != tail_; i = i->next) {
    if (i->next == pos.getIter()) {
      i->next = pos.getIter()->next;
      delete pos.getIter();
      size_--;
      return;
    }
  }
}

template <typename value_type>
void list<value_type>::push_back(const_reference value) {
  Node<value_type> *tmp = new Node<value_type>(value);
  tmp->next = tail_;
  if (size_ != 0) {
    tail_->prev->next = tmp;
    tmp->prev = tail_->prev;
  }
  tail_->prev = tmp;
  if (size_ == 0) {
    head_ = tmp;
  }
  size_++;
}

template <typename value_type>
void list<value_type>::pop_back() {
  if (head_ == nullptr) return;
  Node<value_type> *tmp = tail_->prev;
  if (tmp != nullptr) {
    tmp->next = nullptr;
  } else {
    head_ = nullptr;
  }
  delete tail_;
  tail_ = tmp;
  size_--;
}

template <typename value_type>
void list<value_type>::push_front(const_reference value) {
  Node<value_type> *tmp = new Node<value_type>(value);
  tmp->next = head_;
  if (size_ != 0) {
    head_->prev = tmp;
  }
  if (size_ == 0) {
    head_ = tmp;
    tmp->next = tail_;
    tail_->prev = tmp;
  }
  head_ = tmp;
  tmp->prev = nullptr;
  size_++;
}

template <typename value_type>
void list<value_type>::pop_front() {
  if (head_ == nullptr) return;
  Node<value_type> *tmp = head_->next;
  if (tmp == nullptr) {
    tail_ = nullptr;
  } else {
    tmp->prev = nullptr;
  }
  delete head_;
  head_ = tmp;
  size_--;
}

template <typename value_type>
void list<value_type>::swap(list &other) {
  std::swap(this->head_, other.head_);
  std::swap(this->tail_, other.tail_);
  std::swap(this->size_, other.size_);
}

template <typename value_type>
void list<value_type>::merge(list &other) {
  if (other.empty()) {
    return;
  }
  tail_->next = other.head_;
  other.head_->prev = tail_;
  tail_ = other.tail_;
  size_ = size_ + other.size_;
  other.head_ = nullptr;
  other.tail_ = nullptr;
  other.size_ = 0;
}

template <typename value_type>
void list<value_type>::splice(iterator pos, list &other) {
  if (this != &other && !other.empty() && pos.getIter()) {
    while (other.size_ != 0) {
      insert(pos, other.begin().getIter()->data);
      other.pop_front();
    }
  }
}

template <typename value_type>
void list<value_type>::reverse() {
  if (head_ == nullptr || tail_ == nullptr) {
    return;
  }
  Node<value_type> *tmp;
  Node<value_type> *cur = head_;
  while (cur->next != nullptr) {
    tmp = cur->next;
    cur->next = cur->prev;
    cur->prev = tmp;
    cur = tmp;
  }
  cur = head_;
  head_ = tail_->prev;
  tail_->prev = cur;
  cur->next = tail_;
}

template <typename value_type>
void list<value_type>::unique() {
  if (head_ == nullptr || head_->next == nullptr) {
    return;
  }
  Node<value_type> *cur = head_;
  while (cur->next != tail_) {
    if (cur->data == cur->next->data) {
      erase(cur->next);
    } else {
      cur = cur->next;
    }
  }
}

template <typename value_type>
void list<value_type>::sort() {
  if (head_ == nullptr) {
    return;
  }
  bool swapped;
  do {
    swapped = false;
    Node<value_type> *cur = head_;
    while (cur->next != tail_) {
      if (cur->data > cur->next->data) {
        std::swap(cur->data, cur->next->data);
        swapped = true;
      }
      cur = cur->next;
    }
    tail_->prev = cur;
  } while (swapped);
}

template <typename value_type>
template <typename... Args>
typename list<value_type>::iterator list<value_type>::insert_many(
    iterator pos, Args &&...args) {
  iterator tmp = pos.iter_;
  for (auto &arg : {args...}) {
    insert(tmp, arg);
  }
  return tmp;
}

template <typename value_type>
template <typename... Args>
void list<value_type>::insert_many_back(Args &&...args) {
  for (auto &arg : {args...}) {
    push_back(arg);
  }
}

template <typename value_type>
template <typename... Args>
void list<value_type>::insert_many_front(Args &&...args) {
  for (auto &arg : {args...}) {
    push_front(arg);
  }
}
}  // namespace s21

#endif  // SRC_INCLUDE_SEQUENCE_S21_LIST_H
