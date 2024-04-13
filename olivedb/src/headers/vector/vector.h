#pragma once
#include <vector>

namespace olive
{
  
  template <typename T>
  class Vec: public std::vector<T>
  {
    public:
      inline Vec<T> operator+(const Vec<T> &other) const;
      inline Vec<T> operator-(const Vec<T> &other) const;
      inline Vec<T> operator*(const Vec<T> &other) const;
      inline Vec<T> operator/(const Vec<T> &other) const;
      inline Vec<T> operator%(const Vec<T> &other) const;
      inline Vec<T> operator+(const T &scalar) const;
      inline Vec<T> operator-(const T &scalar) const;
      inline Vec<T> operator*(const T &scalar) const;
      inline Vec<T> operator/(const T &scalar) const;
      inline Vec<T> operator%(const T &scalar) const;
      inline Vec<T> operator+=(const Vec<T> &other);
      inline Vec<T> operator-=(const Vec<T> &other);
      inline Vec<T> operator*=(const Vec<T> &other);
      inline Vec<T> operator/=(const Vec<T> &other);
      inline Vec<T> operator%=(const Vec<T> &other);
      inline Vec<T> operator+=(const T &scalar);
      inline Vec<T> operator-=(const T &scalar);
      inline Vec<T> operator*=(const T &scalar);
      inline Vec<T> operator/=(const T &scalar);
      inline Vec<T> operator%=(const T &scalar);
      inline Vec<T> operator==(const Vec<T> &other) const;
      inline Vec<T> operator!=(const Vec<T> &other) const;
      inline Vec<T> pow(const T &exponent) const;
      inline Vec<T> sqrt() const;
      inline Vec<T> abs() const;
      inline T sum() const;
      inline T dot(const Vec<T> &other) const;
      inline T norm() const;
      inline T mean() const;
      inline T min() const;
      inline size_t argmin() const;
      inline T max() const;
      inline size_t argmax() const;
      Vec<T> slice(int start, int end) const;
      Vec<T> slice(int start) const;
      Vec<T> slice() const;
      Vec<T> append(const Vec<T> &other) const;
      Vec<T> prepend(const Vec<T> &other) const;
  };

} // namespace olive
