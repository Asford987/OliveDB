#pragma once
#include <vector>
#include <type_traits>
#include <cstdint>
#include "engines/indexer/indexer.h"

namespace olive
{

  class Metadata
  {
    public:
      uint64_t id=0;
  };
  
  template <typename T>
  class Vec: public std::vector<T>
  {

  friend class MetadataModifier;

  private:
    Metadata meta;

  public:
    using std::vector<T>::vector;

    // metadata for Vec. Temporary solution: using size_t as id. Will be created a new class for metadata
    Metadata metadata()
    {
      return meta;
      }

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
