#ifndef SRC_INCLUDE_ASSOCIATIVE_UTILS_S21_TREE_H
#define SRC_INCLUDE_ASSOCIATIVE_UTILS_S21_TREE_H

#include <stddef.h>

#include <initializer_list>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <utility>
#include <vector>

#include "rb_tree_iter.h"
#include "rb_tree_node.h"

/*
  1. Каждый узел либо красный, либо черный.
  2. Корень черный.
  3. Каждый лист (NIL) черный.
  4. Если узел красный, то оба его потомка черные.
  5. Для каждого узла все простые пути от узла до листьев-потомков содержат
  такое же количество черных узлов.
*/

namespace s21 {
template <class _Val, bool _Multi, class _Alloc = std::allocator<_Val>>
class Tree {
 public:
  using value_type = _Val;
  using const_value_type = const value_type;
  using value_pointer = value_type *;
  using const_value_pointer = const value_type *;
  using value_reference = value_type &;
  using const_value_reference = const value_type &;

  using size_type = size_t;

  using node_type = TreeNode<value_type>;
  using node_pointer = node_type *;
  using const_node_pointer = const node_type *;

  using iterator = TreeIterator<Tree>;
  using const_iterator = TreeConstIterator<Tree>;

  using allocator_type = typename _Alloc::template rebind<node_type>::other;

 protected:
  node_pointer _root;
  node_pointer _nil;

  size_type _size;
  allocator_type _alloc;

  static constexpr bool _multi = _Multi;

 public:
  Tree() : _size(0), _alloc(allocator_type()) {
    alloc_nil();
    _root = _nil;
  }

  explicit Tree(const allocator_type &alloc) : _size(0), _alloc(alloc) {
    alloc_nil();
    _root = _nil;
  }

  Tree(const Tree &other) : Tree() { *this = other; }

  Tree(Tree &&other) : Tree() {
    *this = other;
    other.clear();
  }

  virtual ~Tree() {
    clear();
    _alloc.destroy(_nil);
    _alloc.deallocate(_nil, 1);
  }

  Tree &operator=(const Tree &other) noexcept {
    if (this != &other) {
      clear();
      _alloc = other._alloc;
      _size = other._size;
      _root = copy_tree(other._root, _nil, other._nil);
    }
    return *this;
  }

  Tree &operator=(Tree &&other) noexcept {
    if (this != &other) {
      *this = other;
      other.clear();
    }
    return *this;
  }

  iterator begin() noexcept { return iterator(min(_root)); }

  const_iterator begin() const noexcept { return const_iterator(min(_root)); }

  iterator end() noexcept { return iterator(_nil); }

  const_iterator end() const noexcept { return const_iterator(_nil); }

  size_type size() const noexcept { return _size; }

  size_type max_size() const noexcept { return _alloc.max_size(); }

  bool empty() const noexcept { return _root == _nil; }

  allocator_type get_allocator() noexcept { return _alloc; }

  template <class InputIt>
  void insert(InputIt first, InputIt last) {
    for (; first != last; ++first) insert(*first);
  }

  template <class... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    std::vector<std::pair<iterator, bool>> vec;

    /* Рассмотрите возможность использования алгоритма std::transform вместо необработанного цикла */
    for (auto arg : {std::forward<Args>(args)...}) {
      vec.push_back(insert(arg));
    }
    return vec;
  }

  void insert(std::initializer_list<value_type> ilist) {
    insert(ilist.begin(), ilist.end());
  }

  std::pair<iterator, bool> insert(const_value_reference value) {
    try {
      node_pointer move = _root, parent = _root;
      node_type node(value, nullptr, _nil);

      while (move != _nil) {
        if (*move->_value == value && !_multi)
          return (std::make_pair(find(value), false));
        parent = move;
        move = *move->_value < value ? move->_right : move->_left;
      }

      move = _alloc.allocate(1);
      _alloc.construct(move, node);

      if (_root == _nil)
        _root = move;
      else
        (parent != _nil && (*parent->_value < value)) ? parent->_right = move
                                                      : parent->_left = move;

      move->set_parent(parent);
      emplace(move);
      ++_size;

      if (move == max(_root)) _nil->_parent = move;

      return (std::make_pair(find(value), true));

    } catch (std::invalid_argument &e) {
      std::cerr << e.what() << std::endl;
      return std::make_pair(find(value), false);
    }
  }

  void erase(const_iterator pos) {
    try {
      if (pos == end()) return;

      node_pointer z = pos._ptr;
      node_pointer y = z;
      node_pointer x;
      char original_color = y->get_color();
      if (z->_left == _nil) {
        x = z->_right;
        node_swap(z, x);
      } else if (z->_right == _nil) {
        x = z->_left;
        node_swap(z, x);
      } else {
        y = min(z->_right);
        original_color = y->get_color();
        x = y->_right;
        if (y->_parent == z) {
          x->_parent = y;
        } else {
          node_swap(y, y->_right);
          y->_right = z->_right;
          y->_right->_parent = y;
        }
        node_swap(z, y);

        y->_left = z->_left;
        y->_left->_parent = y;
        y->_color = z->_color;
      }
      delete_node(z);
      if (original_color == Black_) {
        extract(x);
      }
      _root->_parent = nullptr;
      _nil->_parent = max(_root);
      --_size;

      if (_root == _root->_parent) {
        _root->_parent = nullptr;
        _nil->_parent = nullptr;
        _root = _nil;
      }
    } catch (std::invalid_argument &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  iterator find(const_value_reference key) noexcept {
    auto move = _root;
    while (move && move != _nil) {
      if (*move->_value < key)
        move = move->_right;
      else if (key < *move->_value)
        move = move->_left;
      else
        return (iterator(move));
    }
    return end();
  }

  const_iterator find(const_value_reference key) const noexcept {
    auto move = _root;
    while (move && move != _nil) {
      if (move->_value < key)
        move = move->_right;
      else if (key < move->_value)
        move = move->_left;
      else
        return (const_iterator(move));
    }
    return end();
  }

  bool contains(const_value_reference key) noexcept {
    return find(key) == end() ? false : true;
  }

  void swap(Tree &other) noexcept {
    std::swap(_alloc, other._alloc);
    std::swap(_size, other._size);
    std::swap(_root, other._root);
    std::swap(_nil, other._nil);
  }

  void merge(Tree &other) noexcept { insert(other.begin(), other.end()); }

  static node_pointer min(node_pointer node) noexcept {
    if (node->_left) {
      while (!node->_left->_is_nil) {
        node = node->_left;
      }
    }
    return node;
  }

  static node_pointer max(node_pointer node) noexcept {
    if (node->_right) {
      while (!node->_right->_is_nil) {
        node = node->_right;
      }
    }
    return node;
  }

  void clear() noexcept {
    clear_tree(_root);
    _root = _nil;
    _size = 0;
  }

 private:
  void emplace(node_pointer n) {
    if ((!n->_parent && !n->_left && !n->_right) || !n) {
      throw std::invalid_argument(
          "s21::Tree  emplace(): \"x\": an undeclared identifier");
    }

    while (n != _root && n->_parent->_color == Red_) {
      if (n->_parent->_parent->_right == n->_parent) {
        if (n->_parent->_parent->_left != _nil &&
            n->_parent->_parent->_left->_color == Red_) {
          n->_parent->_parent->_left->set_color(Black_);
          n->_parent->set_color(Black_);
          n->_parent->_parent->set_color(Red_);
          n = n->_parent->_parent;
        } else {
          if (n->_parent->_left == n) {
            n = n->_parent;
            right_rotate(n);
          }
          n->_parent->set_color(Black_);
          n->_parent->_parent->set_color(Red_);
          left_rotate(n->_parent->_parent);
        }
      } else {
        if (n->_parent->_parent->_right != _nil &&
            n->_parent->_parent->_right->_color == Red_) {
          n->_parent->_parent->_right->set_color(Black_);
          n->_parent->set_color(Black_);
          n->_parent->_parent->set_color(Red_);
          n = n->_parent->_parent;
        } else {
          if (n->_parent->_right == n) {
            n = n->_parent;
            left_rotate(n);
          }
          n->_parent->set_color(Black_);
          n->_parent->_parent->set_color(Red_);
          right_rotate(n->_parent->_parent);
        }
      }
    }
    _root->_color = Black_;
    _root->_parent = nullptr;
  }

  void extract(node_pointer x) {
    if ((!x->_parent && !x->_left && !x->_right) || !x) {
      throw std::invalid_argument(
          "s21::Tree  extract(): \"x\": an undeclared identifier");
    }

    node_pointer w;
    while (x != _root && x->get_color() == Black_) {
      if (x == x->_parent->_left) {
        w = x->_parent->_right;

        if (w->get_color() == Red_) {
          w->set_color(Black_);
          x->_parent->set_color(Red_);
          left_rotate(x->_parent);
          w = x->_parent->_right;
        }

        if (w->_left->get_color() == Black_ &&
            w->_right->get_color() == Black_) {
          w->set_color(Red_);
          x = x->_parent;

        } else {
          if (w->_right->get_color() == Black_) {
            w->_left->set_color(Black_);
            w->set_color(Red_);
            right_rotate(w);
            w = x->_parent->_right;
          }
          w->set_color(x->_parent->_color);
          x->_parent->set_color(Black_);
          w->_right->set_color(Black_);
          left_rotate(x->_parent);
          x = _root;
        }
      } else {
        w = x->_parent->_left;

        if (w->get_color() == Red_) {
          w->set_color(Black_);
          x->_parent->set_color(Red_);
          right_rotate(x->_parent);
          w = x->_parent->_left;
        }

        if (w->_right->get_color() == Black_ &&
            w->_left->get_color() == Black_) {
          w->set_color(Red_);
          x = x->_parent;

        } else {
          if (w->_left->get_color() == Black_) {
            w->_right->set_color(Black_);
            w->set_color(Red_);
            left_rotate(w);
            w = x->_parent->_left;
          }
          w->set_color(x->_parent->_color);
          x->_parent->set_color(Black_);
          w->_left->set_color(Black_);
          right_rotate(x->_parent);
          x = _root;
          x->_parent = nullptr;
        }
      }
    }
    x->_color = Black_;
  }

  void node_swap(node_pointer u, node_pointer v) {
    if ((!u->_parent && !u->_left && !u->_right) || !u) {
      throw std::invalid_argument(
          "s21::Tree  node_swap(): \"u\": an undeclared identifier");
    }

    if (u->_parent) {
      if (u->_parent == _nil)
        _root = v;
      else if (u == u->_parent->_left)
        u->_parent->_left = v;
      else
        u->_parent->_right = v;

      v->_parent = u->_parent;
    } else {
      _root = v;
    }
  }

  void right_rotate(node_pointer x) {
    if ((!x->_parent && !x->_left && !x->_right) || !x) {
      throw std::invalid_argument(
          "s21::Tree  right_rotate(): \"x\": an undeclared identifier");
    }

    auto y = x->_left;

    x->_left = y->_right;

    if (y->_right != _nil) y->_right->_parent = x;

    y->_right = x;
    y->_parent = x->_parent;
    x->_parent = y;

    if (_root == x) {
      _root = y;
      return;
    }

    if (y->_parent->_left == x)
      y->_parent->_left = y;
    else
      y->_parent->_right = y;
  }

  void left_rotate(node_pointer x) {
    if ((!x->_parent && !x->_left && !x->_right) || !x) {
      throw std::invalid_argument(
          "s21::Tree  left_rotate(): \"x\": an undeclared identifier");
    }

    auto y = x->_right;

    x->_right = y->_left;

    if (y->_left != _nil) y->_left->_parent = x;

    y->_left = x;
    y->_parent = x->_parent;
    x->_parent = y;

    if (_root == x) {
      _root = y;
      return;
    }

    if (y->_parent->_left == x)
      y->_parent->_left = y;
    else
      y->_parent->_right = y;
  }

  void alloc_nil() noexcept {
    node_type end_node;

    _nil = _alloc.allocate(1);
    _alloc.construct(_nil, end_node);
    _nil->_left = nullptr;
    _nil->_right = nullptr;
  }

  node_pointer allocate_node(node_pointer src, node_pointer parent) noexcept {
    node_pointer node = _alloc.allocate(1);

    node_type set_node(*src->_value, parent, _nil, src->get_color());
    _alloc.construct(node, set_node);
    node->set_is_nil(false);
    return (node);
  }

  void delete_node(node_pointer node) noexcept {
    _alloc.destroy(node);
    _alloc.deallocate(node, 1);
  }

  node_pointer copy_tree(node_pointer node, node_pointer parent,
                         node_pointer nil) noexcept {
    if (node == nil) return _nil;

    node_pointer new_node = allocate_node(node, parent);
    new_node->_left = copy_tree(node->_left, new_node, nil);
    new_node->_right = copy_tree(node->_right, new_node, nil);
    return new_node;
  }

  void clear_tree(node_pointer node) noexcept {
    if (node == _nil || node == nullptr || node == node->_left ||
        node == node->_right)
      return;
    clear_tree(node->_right);
    clear_tree(node->_left);
    delete_node(node);
  }
};
}  // namespace s21

#endif  // SRC_INCLUDE_ASSOCIATIVE_UTILS_S21_TREE_H
