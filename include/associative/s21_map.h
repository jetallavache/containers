#ifndef SRC_S21_ASSOCIATIVE_S21_MAP_H
#define SRC_S21_ASSOCIATIVE_S21_MAP_H

#include "utils/mypair.h"
#include "utils/rb_tree.h"

namespace s21 {
template <class _Key, class _Mapped,
          class _Alloc = std::allocator<mypair<const _Key, _Mapped>>>
class Map : public Tree<mypair<const _Key, _Mapped>, false, _Alloc> {
 public:
  using _Mybase = Tree<mypair<const _Key, _Mapped>, false, _Alloc>;

  using key_type = _Key;
  using mapped_type = _Mapped;

  using value_type = mypair<const key_type, mapped_type>;

  using allocator_type = typename _Mybase::allocator_type;

  using size_type = typename _Mybase::size_type;

  using iterator = typename _Mybase::iterator;
  using const_iterator = typename _Mybase::const_iterator;

  Map() : _Mybase() {}

  explicit Map(const allocator_type& alloc) : _Mybase(alloc) {}

  Map(std::initializer_list<value_type> ilist) : Map() {
    _Mybase::insert(ilist);
  }

  Map(std::initializer_list<value_type> ilist, const allocator_type& alloc)
      : Map(alloc) {
    _Mybase::insert(ilist);
  }

  Map(const Map& map) : _Mybase(map) {}

  Map(Map&& map) : _Mybase(std::move(map)) {}

  ~Map() = default;

  Map& operator=(std::initializer_list<value_type> ilist) noexcept {
    _Mybase::clear();
    _Mybase::insert(ilist);
    return *this;
  }

  Map& operator=(Map&& map) noexcept {
    _Mybase::operator=(std::move(map));
    return *this;
  }

  mapped_type& at(const key_type& key) {
    iterator it = _Mybase::find(make_mypair(key, mapped_type()));

    if (it == _Mybase::end()) {
      throw std::out_of_range("s21::Map  at(): \"key\": not found");
    }

    return (*it).second;
  }

  const mapped_type& at(const key_type& key) const {
    const_iterator it = _Mybase::find(make_mypair(key, mapped_type()));

    if (it == _Mybase::end()) {
      throw std::out_of_range("s21::Map  at(): \"key\": not found");
    }

    return (*it).second;
  }

  mapped_type& operator[](const key_type& key) {
    return (_Mybase::insert(make_mypair(key, mapped_type())).first)->second;
  }

  std::pair<iterator, bool> insert(const value_type& value) {
    return _Mybase::insert(value);
  }

  std::pair<iterator, bool> insert(const key_type& key,
                                   const mapped_type& obj) {
    return _Mybase::insert(make_mypair(key, obj));
  }

  void insert(std::initializer_list<value_type> ilist) {
    return _Mybase::insert(ilist);
  }

  std::pair<iterator, bool> insert_or_assign(const key_type& key,
                                             const mapped_type& obj) {
    auto p = _Mybase::insert(make_mypair(key, obj));
    if (!p.second) {
      p.first->second = obj;
    }
    return p;
  }

  void swap(Map& right) { _Mybase::swap(right); }

  void merge(Map& other) { _Mybase::merge(other); }

  bool contains(const key_type& key) {
    return _Mybase::find(make_mypair(key, mapped_type())) == _Mybase::end()
               ? false
               : true;
  }
};
}  // namespace s21

#endif  // SRC_S21_ASSOCIATIVE_S21_MAP_H
