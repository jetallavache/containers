#ifndef SRC_INCLUDE_ASSOCIATIVE_UTILS_S21_TREE_ITER_H
#define SRC_INCLUDE_ASSOCIATIVE_UTILS_S21_TREE_ITER_H

#include "rb_tree_node.h"

namespace s21 {
template <class _Mytree>
class TreeConstIterator {
 public:
  using node_pointer = typename _Mytree::node_pointer;
  using value_type = typename _Mytree::value_type;
  using pointer = const value_type *;
  using reference = const value_type &;

  TreeConstIterator() noexcept : _ptr(nullptr) {}

  explicit TreeConstIterator(node_pointer ptr) noexcept : _ptr(ptr) {}

  bool operator==(const TreeConstIterator &rvalue) const noexcept {
    return _ptr == rvalue._ptr;
  }

  bool operator!=(const TreeConstIterator &rvalue) const noexcept {
    return !(*this == rvalue);
  }

  reference operator*() const noexcept { return *_ptr->_value; }

  pointer operator->() const noexcept {
    return std::pointer_traits<pointer>::pointer_to(**this);
  }

  TreeConstIterator &operator++() noexcept {
    if (_ptr->_right == nullptr) {
      _ptr = _ptr->_parent;

    } else if (!_ptr->_right->_is_nil) {
      _ptr = _Mytree::min(_ptr->_right);

    } else {
      while (!_ptr->_is_nil && !_ptr->_parent->_is_nil &&
             _ptr == _ptr->_parent->_right) {
        _ptr = _ptr->_parent;
        if (_ptr->_parent == nullptr) {
          _ptr = _Mytree::max(_ptr);
          _ptr = _ptr->_right;
          return *this;
        }
      }
      _ptr = _ptr->_parent;
    }
    return *this;
  }

  TreeConstIterator operator++(int) noexcept {
    TreeConstIterator tmp = *this;
    ++*this;
    return tmp;
  }

  TreeConstIterator &operator--() noexcept {
    if (_ptr->_left == nullptr) {
      _ptr = _ptr->_parent;

    } else if (!_ptr->_left->_is_nil) {
      _ptr = _Mytree::max(_ptr->_left);
    } else {
      while (!_ptr->_is_nil && !_ptr->_parent->_is_nil &&
             _ptr == _ptr->_parent->_left) {
        _ptr = _ptr->_parent;
        if (_ptr->_parent == nullptr) {
          _ptr = _Mytree::min(_ptr);
          return *this;
        }
      }
      _ptr = _ptr->_parent;
    }

    return *this;
  }

  TreeConstIterator operator--(int) noexcept {
    TreeConstIterator tmp = *this;
    --*this;
    return tmp;
  }

  node_pointer _ptr;
};

template <class _Mytree>
class TreeIterator : public TreeConstIterator<_Mytree> {
 public:
  using _Mybase = TreeConstIterator<_Mytree>;

  using node_pointer = typename _Mytree::node_pointer;
  using value_type = typename _Mytree::value_type;
  using pointer = value_type *;
  using reference = value_type &;

  using _Mybase::_Mybase;

  reference operator*() const noexcept {
    return const_cast<reference>(_Mybase::operator*());
  }

  pointer operator->() const noexcept {
    return std::pointer_traits<pointer>::pointer_to(**this);
  }

  TreeIterator &operator++() noexcept {
    _Mybase::operator++();
    return *this;
  }

  TreeIterator operator++(int) noexcept {
    TreeIterator tmp = *this;
    _Mybase::operator++();
    return tmp;
  }

  TreeIterator &operator--() noexcept {
    _Mybase::operator--();
    return *this;
  }

  TreeIterator operator--(int) noexcept {
    TreeIterator tmp = *this;
    _Mybase::operator--();
    return tmp;
  }
};
}  // namespace s21

#endif  // SRC_INCLUDE_ASSOCIATIVE_UTILS_S21_TREE_ITER_H