#ifndef SRC_ASSOCIATIVE_MULTISET_H
#define SRC_ASSOCIATIVE_MULTISET_H

#include "utils/rb_tree.h"

namespace my_stl {
template <class _Key, class _Alloc = std::allocator<_Key>>
class Multiset : public Tree<_Key, true, _Alloc> {
 public:
  using _Mybase = Tree<_Key, true, _Alloc>;

  using node_pointer = typename _Mybase::node_pointer;

  using key_type = _Key;
  using value_type = typename _Mybase::value_type;
  using reference = value_type&;
  using const_reference = const value_type&;

  using allocator_type = typename _Mybase::allocator_type;

  using size_type = typename _Mybase::size_type;

  using iterator = typename _Mybase::iterator;
  using const_iterator = typename _Mybase::const_iterator;

  Multiset() : _Mybase() {}

  explicit Multiset(const allocator_type& alloc) : _Mybase(alloc) {}

  Multiset(std::initializer_list<value_type> ilist) : Multiset() {
    _Mybase::insert(ilist);
  }

  Multiset(std::initializer_list<value_type> ilist, const allocator_type& alloc)
      : Multiset(alloc) {
    _Mybase::insert(ilist);
  }

  Multiset(const Multiset& multiset) : _Mybase(multiset) {}

  Multiset(Multiset&& multiset) noexcept : _Mybase(std::move(multiset)) {}

  ~Multiset() = default;

  Multiset& operator=(Multiset&& multiset) noexcept {
    _Mybase::operator=(std::move(multiset));
    return *this;
  }

  Multiset& operator=(std::initializer_list<value_type> ilist) {
    _Mybase::clear();
    _Mybase::insert(ilist);
    return *this;
  }

  iterator insert(const value_type& value) {
    return _Mybase::insert(value).first;
  }

  void insert(std::initializer_list<value_type> ilist) {
    _Mybase::insert(ilist.begin(), ilist.end());
  }

  template <class InputIt>
  void insert(InputIt first, InputIt last) {
    for (; first != last; ++first) _Mybase::insert(*first);
  }

  void erase(iterator pos) { _Mybase::erase(pos); }

  void swap(Multiset& right) { _Mybase::swap(right); }

  size_type count(const key_type& key) const {
    size_type count = 0;
    auto range = equal_range(key);
    for (auto it = range.first; it != range.second; ++it) {
      count++;
    }
    return count;
  }

  size_type count(const key_type& key) {
    size_type count = 0;
    auto range = equal_range(key);
    for (auto it = range.first; it != range.second; ++it) {
      count++;
    }
    return count;
  }

  std::pair<iterator, iterator> equal_range(const key_type& key) {
    auto lower = lower_bound(key);
    auto upper = upper_bound(key);
    return std::make_pair(lower, upper);
  }

  std::pair<const_iterator, const_iterator> equal_range(
      const key_type& key) const {
    const auto lower = lower_bound(key);
    const auto upper = upper_bound(key);
    return std::make_pair(lower, upper);
  }

  iterator lower_bound(const key_type& key) {
    auto it = _Mybase::begin();
    while (it != _Mybase::end() && key > *it) {
      ++it;
    }
    return it;
  }

  iterator upper_bound(const key_type& key) {
    auto it = _Mybase::begin();
    while (it != _Mybase::end() && key >= *it) {
      ++it;
    }
    return it;
  }

  const_iterator lower_bound(const key_type& key) const {
    auto it = _Mybase::begin();
    while (it != _Mybase::end() && key > *it) {
      ++it;
    }
    return it;
  }

  const_iterator upper_bound(const key_type& key) const {
    auto it = _Mybase::begin();
    while (it != _Mybase::end() && key >= *it) {
      ++it;
    }
    return it;
  }
};
}  // namespace my_stl

#endif  // SRC_ASSOCIATIVE_MULTISET_H
