#include "vector/vector.h"

namespace olive
{
    
    template <typename T>
    inline Vec<T> Vec<T>::operator+(const Vec<T> &other) const
    {
      return *this;
    }
  
    template <typename T>
    inline Vec<T> Vec<T>::operator-(const Vec<T> &other) const
    {
      return *this;
    }
  
    template <typename T>
    inline Vec<T> Vec<T>::operator*(const Vec<T> &other) const
    {
      return *this;
    }
  
    template <typename T>
    inline Vec<T> Vec<T>::operator/(const Vec<T> &other) const
    {
      return *this;
    }
  
    template <typename T>
    inline Vec<T> Vec<T>::operator%(const Vec<T> &other) const
    {
      return *this;
    }
  
    template <typename T>
    inline Vec<T> Vec<T>::operator+(const T &scalar) const
    {
      return *this;
    }
  
    template <typename T>
    inline Vec<T> Vec<T>::operator-(const T &scalar) const
    {
      return *this;
    }
  
    template <typename T>
    inline Vec<T> Vec<T>::operator*(const T &scalar) const
    {
      return *this;
    }
  
    template <typename T>
    inline Vec<T> Vec<T>::operator/(const T &scalar) const
    {
      return *this;
    }
  
    template <typename T>
    inline Vec<T> Vec<T>::operator%(const T &scalar) const
    {
      return *this;
    }
  
    template <typename T>
    inline Vec<T> Vec<T>::operator+=(const Vec<T> &other)
    {
      return *this;
    }
  
    template <typename T>
    inline Vec<T> Vec<T>::operator-=(const Vec<T> &other)
    {
      return *this;
    }
  
    template <typename T>
    inline Vec<T> Vec<T>::operator*=(const Vec<T> &other)
    {
      return *this;
    }
  
    template <typename T>
    inline Vec<T> Vec<T>::operator/=(const Vec<T> &other)
    {
      return *this;
    }
  
    template <typename T>
    inline Vec<T> Vec<T>::operator%=(const Vec<T> &other)
    {
      return *this;
    }
  
    template <typename T>
    inline Vec<T> Vec<T>::operator+=(const T &scalar)
    {
      return *this;
    }

    template <typename T>
    inline Vec<T> Vec<T>::operator-=(const T &scalar)
    {
      return *this;
    }

    template <typename T>
    inline Vec<T> Vec<T>::operator*=(const T &scalar)
    {
      return *this;
    }

    template <typename T>
    inline Vec<T> Vec<T>::operator/=(const T &scalar)
    {
      return *this;
    }

    template <typename T>
    inline Vec<T> Vec<T>::operator%=(const T &scalar)
    {
      return *this;
    }

    template <typename T>
    inline Vec<T> Vec<T>::operator==(const Vec<T> &other) const
    {
      return *this;
    }

    template <typename T>
    inline Vec<T> Vec<T>::operator!=(const Vec<T> &other) const
    {
      return *this;
    }

    template <typename T>
    inline Vec<T> Vec<T>::pow(const T &exponent) const
    {
      return *this;
    }

    template <typename T>
    inline Vec<T> Vec<T>::sqrt() const
    {
      return *this;
    }

    template <typename T>
    inline Vec<T> Vec<T>::abs() const
    {
      return *this;
    }

    template <typename T>
    T Vec<T>::sum() const
    {
      return *this;
    }

    template <typename T>
    T Vec<T>::dot(const Vec<T> &other) const
    {
      return *this;
    }

    template <typename T>
    T Vec<T>::norm() const
    {
      return *this;
    }

    template <typename T>
    T Vec<T>::mean() const
    {
      return *this;
    }

    template <typename T>
    T Vec<T>::min() const
    {
      return *this;
    }

    template <typename T>
    size_t Vec<T>::argmin() const
    {
      return 0;
    }

    template <typename T>
    T Vec<T>::max() const
    {
      return *this;
    }

    template <typename T>
    size_t Vec<T>::argmax() const
    {
      return 0;
    }

    template <typename T>
    inline Vec<T> Vec<T>::slice(int start, int end) const
    {
      return *this;
    }

    template <typename T>
    inline Vec<T> Vec<T>::slice(int start) const
    {
      return *this;
    }

    template <typename T>
    inline Vec<T> Vec<T>::slice() const
    {
      return *this;
    }

    template <typename T>
    inline Vec<T> Vec<T>::append(const Vec<T> &other) const
    {
      return *this;
    }

    template <typename T>
    inline Vec<T> Vec<T>::prepend(const Vec<T> &other) const
    {
      return *this;
    }

} // namespace olive
