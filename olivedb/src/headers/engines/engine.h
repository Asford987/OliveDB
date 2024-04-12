#pragma once
#include <iostream>
#include <vector>

namespace olive
{

  class Preprocessor
  {

  public:
    friend std::ostream &operator<<(std::ostream &os, const Preprocessor &preprocessor);
  };

  class Indexer
  {
  };

  class Query
  {
    public:
      virtual std::vector<float> _search(const std::vector<float> &query, int num_results)=0;
  };

  template <typename Derived>
  class SearchEngine: public Query
  {
    public:
      std::vector<float> search(const std::vector<float> &query, int num_results){
        return static_cast<Derived*>(this)->_search(query, num_results);
      }
  };

  class Storage
  {
    public:
      virtual void _persist(const std::vector<float> &data) = 0;
      virtual std::vector<float> _load() = 0;
  };

  template <typename Derived>
  class StorageEngine: public Storage
  {
    public:
      void persist(const std::vector<float> &data){
        static_cast<Derived*>(this)->_persist(data);
      }

      std::vector<float> load(){
        return static_cast<Derived*>(this)->_load();
      }
  };

} // namespace olive