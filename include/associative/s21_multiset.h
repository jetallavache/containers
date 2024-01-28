#ifndef SRC_S21_ASSOCIATIVE_S21_MULTISET_H
#define SRC_S21_ASSOCIATIVE_S21_MULTISET_H

#include "utils/rb_tree.h"

namespace s21 {
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

  explicit  Multiset(const allocator_type& alloc) : _Mybase(alloc) {}

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

  iterator begin() { return _Mybase::begin(); }
  const_iterator begin() const { return _Mybase::begin(); }
  iterator end() { return _Mybase::end(); }
  const_iterator end() const { return _Mybase::end(); }

  bool empty() const { return _Mybase::empty(); }
  size_type size() const { return _Mybase::size(); }
  size_type max_size() const { return _Mybase::max_size(); }

  void clear() { _Mybase::clear(); }

  iterator insert(const value_type& value) {
    return _Mybase::insert(value).first;
  }

  void erase(iterator pos) { _Mybase::erase(pos); }

  void swap(Multiset& right) { _Mybase::swap(right); }

  void merge(Multiset& other) {
    _Mybase::insert(other.begin(), other.end());
    other.clear();
  }

  iterator find(const key_type& key) {
    auto it = _Mybase::find(key);
    return it;
  }

  bool contains(const key_type& key) { return find(key) != end(); }

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

  iterator lower_bound(const key_type& key) {
    auto it = begin();
    while (it != end() && key > *it) {
      ++it;
    }
    return it;
  }

  iterator upper_bound(const key_type& key) {
    auto it = begin();
    while (it != end() && key >= *it) {
      ++it;
    }
    return it;
  }
  const_iterator lower_bound(const key_type& key) const {
    auto it = begin();
    while (it != end() && key > *it) {
      ++it;
    }
    return it;
  }

  const_iterator upper_bound(const key_type& key) const {
    auto it = begin();
    while (it != end() && key >= *it) {
      ++it;
    }
    return it;
  }
};
}  // namespace s21

#endif  // SRC_S21_ASSOCIATIVE_S21_MULTISET_H
