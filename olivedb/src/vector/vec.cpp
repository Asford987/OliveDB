#include "vector/vec.h"

namespace olive
{

  template <typename T>
  Metadata Vec<T>::metadata()
  {
    return meta; 
  }

  template <typename T>
  Vec<T> Vec<T>::operator+(const Vec<T> &other) const
  {
    Vec<T> result;
    for (int i = 0; i < this->size(); i++)
    {
      result.push_back(this->at(i) + other.at(i));
    }
    return result;
  }

  template <typename T>
  Vec<T> Vec<T>::operator-(const Vec<T> &other) const
  {
    Vec<T> result;
    for (int i = 0; i < this->size(); i++)
    {
      result.push_back(this->at(i) - other.at(i));
    }
    return result;
  }

  template <typename T>
  Vec<T> Vec<T>::operator*(const Vec<T> &other) const
  {
    Vec<T> result;
    for (int i = 0; i < this->size(); i++)
    {
      result.push_back(this->at(i) * other.at(i));
    }
    return result;
  }

  template <typename T>
  Vec<T> Vec<T>::operator/(const Vec<T> &other) const
  {
    Vec<T> result;
    for (int i = 0; i < this->size(); i++)
    {
      result.push_back(this->at(i) / other.at(i));
    }
    return result;
  }

  template <typename T>
  Vec<T> Vec<T>::operator%(const Vec<T> &other) const
  {
    Vec<T> result;
    for (int i = 0; i < this->size(); i++)
    {
      result.push_back(this->at(i) % other.at(i));
    }
    return result;
  }

  template <typename T>
  Vec<T> Vec<T>::operator+(const T &scalar) const
  {
    Vec<T> result;
    for (int i = 0; i < this->size(); i++)
    {
      result.push_back(this->at(i) + scalar);
    }
    return result;
  }

  template <typename T>
  Vec<T> Vec<T>::operator-(const T &scalar) const
  {
    Vec<T> result;
    for (int i = 0; i < this->size(); i++)
    {
      result.push_back(this->at(i) - scalar);
    }
    return result;
  }

  template <typename T>
  Vec<T> Vec<T>::operator*(const T &scalar) const
  {
    Vec<T> result;
    for (int i = 0; i < this->size(); i++)
    {
      result.push_back(this->at(i) * scalar);
    }
    return result;
  }

  template <typename T>
  Vec<T> Vec<T>::operator/(const T &scalar) const
  {
    Vec<T> result;
    for (int i = 0; i < this->size(); i++)
    {
      result.push_back(this->at(i) / scalar);
    }
    return result;
  }

  template <typename T>
  Vec<T> Vec<T>::operator%(const T &scalar) const
  {
    Vec<T> result;
    for (int i = 0; i < this->size(); i++)
    {
      result.push_back(this->at(i) % scalar);
    }
    return result;
  }

  template <typename T>
  Vec<T> Vec<T>::operator+=(const Vec<T> &other)
  {
    for (int i = 0; i < this->size(); i++)
    {
      this->at(i) += other.at(i);
    }
    return *this;
  }

  template <typename T>
  Vec<T> Vec<T>::operator-=(const Vec<T> &other)
  {
    for (int i = 0; i < this->size(); i++)
    {
      this->at(i) -= other.at(i);
    }
    return *this;
  }

  template <typename T>
  Vec<T> Vec<T>::operator*=(const Vec<T> &other)
  {
    for (int i = 0; i < this->size(); i++)
    {
      this->at(i) *= other.at(i);
    }
    return *this;
  }

  template <typename T>
  Vec<T> Vec<T>::operator/=(const Vec<T> &other)
  {
    for (int i = 0; i < this->size(); i++)
    {
      this->at(i) /= other.at(i);
    }
    return *this;
  }

  template <typename T>
  Vec<T> Vec<T>::operator%=(const Vec<T> &other)
  {
    for (int i = 0; i < this->size(); i++)
    {
      this->at(i) %= other.at(i);
    }
    return *this;
  }

  template <typename T>
  Vec<T> Vec<T>::operator+=(const T &scalar)
  {
    for (int i = 0; i < this->size(); i++)
    {
      this->at(i) += scalar;
    }
    return *this;
  }

  template <typename T>
  Vec<T> Vec<T>::operator-=(const T &scalar)
  {
    for (int i = 0; i < this->size(); i++)
    {
      this->at(i) -= scalar;
    }
    return *this;
  }

  template <typename T>
  Vec<T> Vec<T>::operator*=(const T &scalar)
  {
    for (int i = 0; i < this->size(); i++)
    {
      this->at(i) *= scalar;
    }
    return *this;
  }

  template <typename T>
  Vec<T> Vec<T>::operator/=(const T &scalar)
  {
    for (int i = 0; i < this->size(); i++)
    {
      this->at(i) /= scalar;
    }
    return *this;
  }

  template <typename T>
  Vec<T> Vec<T>::operator%=(const T &scalar)
  {
    for (int i = 0; i < this->size(); i++)
    {
      this->at(i) %= scalar;
    }
    return *this;
  }

  template <typename T>
  Vec<T> Vec<T>::operator==(const Vec<T> &other) const
  {
    Vec<T> result;
    for (int i = 0; i < this->size(); i++)
    {
      result.push_back(static_cast<T>(this->at(i) == other.at(i)));
    }
    return result;
  }

  template <typename T>
  Vec<T> Vec<T>::operator!=(const Vec<T> &other) const
  {
    Vec<T> result;
    for (int i = 0; i < this->size(); i++)
    {
      result.push_back(static_cast<T>(this->at(i) != other.at(i)));
    }
    return result;
  }

  template <typename T>
  Vec<T> Vec<T>::pow(const T &exponent) const
  {
    Vec<T> result;
    for (int i = 0; i < this->size(); i++)
    {
      result.push_back(std::pow(this->at(i), exponent));
    }
    return result;
  }

  template <typename T>
  Vec<T> Vec<T>::sqrt() const
  {
    Vec<T> result;
    for (int i = 0; i < this->size(); i++)
    {
      result.push_back(std::sqrt(this->at(i)));
    }
    return result;
  }

  template <typename T>
  Vec<T> Vec<T>::abs() const
  {
    Vec<T> result;
    for (int i = 0; i < this->size(); i++)
    {
      result.push_back(std::abs(this->at(i)));
    }
    return result;
  }

  template <typename T>
  T Vec<T>::sum() const
  {
    T result = 0;
    for (int i = 0; i < this->size(); i++)
    {
      result += this->at(i);
    }
    return result;
  }

  template <typename T>
  T Vec<T>::dot(const Vec<T> &other) const
  {
    auto partial = *this * other;
    return partial.sum();
  }

  template <typename T>
  T Vec<T>::norm() const 
  {
    return std::sqrt(this -> dot(*this));
  }

  template <typename T>
  T Vec<T>::mean() const 
  {
    return this -> sum() / this -> size();
  }

  template <typename T>
  T Vec<T>::min() const
  {
    return this->at(argmin());
  }

  template <typename T>
  size_t Vec<T>::argmin() const 
  {
    size_t pos = 0;
    for(int i = 1; i < this->size(); i++)
    {
      if(this->at(i) < this->at(pos))
      {
        pos = i;
      }
    }
    return pos;
  }

  template <typename T>
  T Vec<T>::max() const
  {
    return this->argmax();
  }

  template <typename T>
  size_t Vec<T>::argmax() const 
  {
    size_t pos = 0;
    for(int i = 1; i < this->size(); i++)
    {
      if(this->at(i) > this->at(pos))
      {
        pos = i;
      }
    }
    return pos;
  }

  template <typename T>
  Vec<T> Vec<T>::slice(int start, int end) const 
  {
    Vec<T> result;
    for(int i = start; i < end; i++)
    {
      result.push_back(this->at(i));
    }
  }

  template <typename T>
  Vec<T> Vec<T>::slice(int start) const 
  {
    Vec<T> result;
    for(int i = start; i < this->size(); i++)
    {
      result.push_back(this->at(i));
    }
    return result;
  }

  template <typename T>
  Vec<T> Vec<T>::append(const Vec<T> &other) const 
  {
    Vec<T> result;
    for(auto i : *this)
    {
      result.push_back(i);
    }
    for(auto i : other)
    {
      result.push_back(i);
    }
    return result;
  }

  template <typename T>
  Vec<T> Vec<T>::prepend(const Vec<T> &other) const 
  {
    Vec<T> result;
    for(auto i : other)
    {
      result.push_back(i);
    }
    for(auto i : *this)
    {
      result.push_back(i);
    }
    return result;
  }

  template <typename T>
  Vec<Vec<T>> Vec<T>::unsqueeze() const 
  {
    Vec<Vec<T>> result = { *this };
    return result;
  }

  template <typename T>
  T Vec<T>::squeeze(size_t idx) const 
  {
    return this->at(idx);
  }

  template <typename T>
  Vec<T> Vec<T>::flatten() const
  {
    Vec<T> flat;
    for (auto &v : *this)
    {
      for (auto &e : v)
      {
        flat.push_back(e);
      }
    }
    return flat;
  }

  template <typename T>
  bool Vec<T>::is_empty() const
  {
    return this->size() == 0;
  }

  template <typename T>
  bool Vec<T>::all() const
  {
    for (auto &v : *this)
    {
      if (!v)
      {
        return false;
      }
    }
    return true;
  }

  template <typename T>
  bool Vec<T>::any() const
  {
    for (auto &v : *this)
    {
      if (v)
      {
        return true;
      }
    }
    return false;
  }

  template <typename T>
  Vec<T>::operator bool() const
  {
    return this->all();
  } 

} // namespace olive
