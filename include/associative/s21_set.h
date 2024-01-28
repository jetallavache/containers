#ifndef SRC_S21_ASSOCIATIVE_S21_SET_H
#define SRC_S21_ASSOCIATIVE_S21_SET_H

#include "utils/rb_tree.h"

namespace s21 {
template <class _Key, class _Alloc = std::allocator<_Key>>
class Set : public Tree<_Key, false, _Alloc> {
 public:
  using _Mybase = Tree<_Key, false, _Alloc>;

  using node_pointer = typename _Mybase::node_pointer;

  using key_type = _Key;
  using value_type = typename _Mybase::value_type;
  using reference = value_type&;
  using const_reference = const value_type&;

  using allocator_type = typename _Mybase::allocator_type;

  using size_type = typename _Mybase::size_type;

  using iterator = typename _Mybase::iterator;
  using const_iterator = typename _Mybase::const_iterator;

  Set() : _Mybase() {}

  explicit Set(const allocator_type& alloc) : _Mybase(alloc) {}

  Set(std::initializer_list<value_type> ilist) : Set() {
    _Mybase::insert(ilist);
  }

  Set(std::initializer_list<value_type> ilist, const allocator_type& alloc)
      : Set(alloc) {
    _Mybase::insert(ilist);
  }

  Set(const Set& set) : _Mybase(set) {}

  Set(Set&& set) noexcept : _Mybase(std::move(set)) {}

  ~Set() = default;

  Set& operator=(Set&& set) noexcept {
    _Mybase::operator=(std::move(set));
    return *this;
  }

  Set& operator=(std::initializer_list<value_type> ilist) {
    _Mybase::clear();
    _Mybase::insert(ilist);
    return *this;
  }

  void swap(Set& right) { _Mybase::swap(right); }

  void merge(Set& other) { _Mybase::merge(other); }
};
}  // namespace s21

#endif  // SRC_S21_ASSOCIATIVE_S21_SET_H
