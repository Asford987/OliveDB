#pragma once
#include <vector>
#include <type_traits>
#include <cstdint>
#include <indexer/indexer.h>
#include <metadata/modifier.h>
#include <metadata/metadata.h>

namespace olive
{
  
  template <typename T>
  class Vec: public std::vector<T>
  {

    friend class MetadataModifier;
    private:
      Metadata meta;
    public:
      using std::vector<T>::vector;

      Metadata metadata();

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
      Vec<Vec<T>> unsqueeze() const;
      T squeeze(size_t idx) const;
      Vec<T> flatten() const;
      
  };

} // namespace olive
