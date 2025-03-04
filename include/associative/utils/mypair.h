#ifndef SRC_INCLUDE_ASSOCIATIVE_UTILS_MYPAIR_H
#define SRC_INCLUDE_ASSOCIATIVE_UTILS_MYPAIR_H

#include <utility>

namespace my_stl {
template <class T1, class T2>
class mypair : public std::pair<T1, T2> {
 public:
  using _Mybase = std::pair<T1, T2>;
  using first_type = T1;
  using second_type = T2;

  mypair() : _Mybase() {}

  mypair(const T1& a, const T2& b) : _Mybase(a, b) {}

  template <class U1, class U2>
  constexpr mypair(const mypair<U1, U2>& p) : _Mybase(p) {}

  mypair(const mypair& other) : _Mybase(other) {}

  mypair(mypair&& other) : _Mybase(std::move(other)) {}

  ~mypair() = default;

  mypair& operator=(mypair&& other) {
    _Mybase::operator=(std::move(other));
    return *this;
  }
};

template <class T1, class T2>
bool operator==(const mypair<T1, T2>& x, const mypair<T1, T2>& y) {
  return x.first == y.first;
}

template <class T1, class T2>
bool operator!=(const mypair<T1, T2>& x, const mypair<T1, T2>& y) {
  return !(x.first == y.first);
}

template <class T1, class T2>
bool operator<(const mypair<T1, T2>& x, const mypair<T1, T2>& y) {
  return x.first < y.first;
}

template <class T1, class T2>
bool operator>(const mypair<T1, T2>& x, const mypair<T1, T2>& y) {
  return y.first < x.first;
}

template <class T1, class T2>
bool operator<=(const mypair<T1, T2>& x, const mypair<T1, T2>& y) {
  return !(y.first < x.first);
}

template <class T1, class T2>
bool operator>=(const mypair<T1, T2>& x, const mypair<T1, T2>& y) {
  return !(x.first < y.first);
}

template <class T1, class T2>
mypair<T1, T2> make_mypair(T1 x, T2 y) {
  typedef mypair<T1, T2> _Mypair_type;
  return _Mypair_type(x, y);
}
}  // namespace my_stl

#endif  // SRC_INCLUDE_ASSOCIATIVE_UTILS_MYPAIR_H