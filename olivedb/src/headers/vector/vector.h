#pragma once
#include <vector>

namespace olive
{
  
  template <typename T>
  class Vec: public std::vector<T>
  {
    public:
      Vec<T> operator+(const Vec<T> &other) const;
      Vec<T> operator-(const Vec<T> &other) const;
      Vec<T> operator*(const Vec<T> &other) const;
      Vec<T> operator/(const Vec<T> &other) const;
      Vec<T> operator%(const Vec<T> &other) const;
      Vec<T> operator+(const T &scalar) const;
      Vec<T> operator-(const T &scalar) const;
      Vec<T> operator*(const T &scalar) const;
      Vec<T> operator/(const T &scalar) const;
      Vec<T> operator%(const T &scalar) const;
      Vec<T> operator+=(const Vec<T> &other);
      Vec<T> operator-=(const Vec<T> &other);
      Vec<T> operator*=(const Vec<T> &other);
      Vec<T> operator/=(const Vec<T> &other);
      Vec<T> operator%=(const Vec<T> &other);
      Vec<T> operator+=(const T &scalar);
      Vec<T> operator-=(const T &scalar);
      Vec<T> operator*=(const T &scalar);
      Vec<T> operator/=(const T &scalar);
      Vec<T> operator%=(const T &scalar);
      Vec<T> operator==(const Vec<T> &other) const;
      Vec<T> operator!=(const Vec<T> &other) const;
      Vec<T> pow(const T &exponent) const;
      Vec<T> sqrt() const;
      Vec<T> abs() const;
      T sum() const;
      T dot(const Vec<T> &other) const;
      T norm() const;
      T mean() const;
      T median() const;
      T mode() const;
      T variance() const;
      T std() const;
      T min() const;
      T max() const;
      Vec<T> sort() const;
      Vec<T> unique() const;
      Vec<T> reverse() const;
      Vec<T> shuffle() const;
      Vec<T> slice(int start, int end) const;
      Vec<T> slice(int start) const;
      Vec<T> slice() const;
      Vec<T> append(const Vec<T> &other) const;
      Vec<T> append(const T &scalar) const;
      Vec<T> prepend(const Vec<T> &other) const;
      Vec<T> prepend(const T &scalar) const;
      Vec<T> insert(int index, const Vec<T> &other) const;
  };

} // namespace olive
