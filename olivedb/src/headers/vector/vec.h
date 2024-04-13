#pragma once
#include <vector>

namespace olive
{
  
  template <typename T>
  class Vec: public std::vector<T>
  {
    public:
      using std::vector<T>::vector;
      size_t id=0;
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
      T min() const;
      size_t argmin() const;
      T max() const;
      size_t argmax() const;
      Vec<T> slice(int start, int end) const;
      Vec<T> slice(int start) const;
      Vec<T> append(const Vec<T> &other) const;
      Vec<T> prepend(const Vec<T> &other) const;
  };

} // namespace olive
