#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "vector/vector.h"

namespace olive
{

  class Preprocessor
  {

  public:
    friend std::ostream &operator<<(std::ostream &os, const Preprocessor &preprocessor);
  };

  class Indexer
  {
    public:
      // get_index(const Vec<float> &data);
      // set_index(const Vec<float> &data);
  };

  class Query
  {
    protected:
      virtual float similarity(const Vec<float> &query, const Vec<float> &data) = 0;
    public:
      virtual Vec<float> search(const Vec<float> &query, int num_results);
  };

  class SearchEngine
  {
    protected:
      virtual std::unique_ptr<Query> query_type() = 0;
    public:
      Vec<float> search(const Vec<float> &query, int num_results){
        return query_type()->search(query, num_results);
      }
  };

  class Storage
  {
    public:
      virtual void persist(const Vec<float> &data) = 0;
      virtual Vec<float> load() = 0;
  };

  class StorageEngine
  {
    protected:
      virtual std::unique_ptr<Storage> storage_type() = 0;
    public:
      void persist(const Vec<float> &data){
        storage_type()->persist(data);
      }
      Vec<float> load(){
        return storage_type()->load();
      }
  };

} // namespace olive