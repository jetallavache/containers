#ifndef SRC_INCLUDE_ASSOCIATIVE_UTILS_S21_TREE_NODE_H
#define SRC_INCLUDE_ASSOCIATIVE_UTILS_S21_TREE_NODE_H

#include <memory>

namespace s21 {
enum ColorLeaf { Black_, Red_ };

template <class _Val, class _Alloc = std::allocator<_Val>>
class TreeNode {
 public:
  using value_type = _Val;
  using value_pointer = _Val *;
  using node_type = TreeNode<value_type>;
  using node_pointer = TreeNode<value_type> *;
  using allocator_type = _Alloc;

  value_pointer _value;
  char _color;
  char _is_nil;
  node_pointer _parent;
  node_pointer _left;
  node_pointer _right;
  allocator_type _alloc;

  TreeNode()
      : _color(Black_),
        _is_nil(true),
        _parent(nullptr),
        _left(nullptr),
        _right(nullptr),
        _alloc(std::allocator<value_type>()) {
    _value = _alloc.allocate(1);
    _alloc.construct(_value, value_type());
  }

  explicit TreeNode(const value_type &value)
      : _color(Black_),
        _is_nil(true),
        _parent(nullptr),
        _left(nullptr),
        _right(nullptr),
        _alloc(std::allocator<value_type>()) {
    _value = _alloc.allocate(1);
    _alloc.construct(_value, value);
  }

  explicit TreeNode(const value_type &value, node_pointer parent,
           const node_pointer nil) /**/
      : _color(Red_),
        _is_nil(false),
        _parent(parent),
        _left(nil),
        _right(nil),
        _alloc(std::allocator<value_type>()) {
    _value = _alloc.allocate(1);
    _alloc.construct(_value, value);
  }

  explicit TreeNode(const value_type &value, node_pointer parent, const node_pointer nil,
           char color)
      : _color(color),
        _is_nil(false),
        _parent(parent),
        _left(nil),
        _right(nil),
        _alloc(std::allocator<value_type>()) {
    _value = _alloc.allocate(1);
    _alloc.construct(_value, value);
  }

  TreeNode(const TreeNode &other) : _value(nullptr) { *this = other; }

  virtual ~TreeNode() {
    _alloc.destroy(_value);
    _alloc.deallocate(_value, 1);
  }

  node_type &operator=(node_type &other) noexcept {
    if (this != &other) {
      if (_value) _alloc.deallocate(_value, 1);
      _alloc = other._alloc;
      _value = _alloc.allocate(1);
      _alloc.construct(_value, other.get_value());
      _color = other._color;
      _parent = other._parent;
      _right = other._right;
      _left = other._left;
      _is_nil = other._is_nil;
    }
    return *this;
  }

  node_type &operator=(const node_type &other) noexcept {
    if (this != &other) {
      if (_value) _alloc.deallocate(_value, 1);
      _alloc = other._alloc;
      _value = _alloc.allocate(1);
      _alloc.construct(_value, other.get_value());
      _color = other._color;
      _parent = other._parent;
      _right = other._right;
      _left = other._left;
      _is_nil = other._is_nil;
    }
    return *this;
  }

  value_type get_value() const noexcept { return *this->_value; }

  char get_color() const noexcept { return this->_color; }

  void set_parent(node_pointer parent) noexcept { _parent = parent; }

  void set_is_nil(bool is_nil) noexcept { _is_nil = is_nil; }

  void set_color(char color) noexcept { _color = color; }
};
}  // namespace s21

#endif  // SRC_INCLUDE_ASSOCIATIVE_UTILS_S21_TREE_NODE_H