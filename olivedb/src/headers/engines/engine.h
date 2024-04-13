#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <map>
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
    public:
      inline virtual float similarity(const Vec<float> &query, const Vec<float> &data) = 0;
  };

  class SearchEngine
  {
    protected:
      virtual std::unique_ptr<Query> query_type() = 0;
      virtual Vec<Vec<float>> loaded_data() = 0;
    public:
      std::map<Vec<float>, float> search(const Vec<float> &query, int num_results);
  };

  class Storage
  {
    public:
      virtual void persist(const Vec<Vec<float>> &data) = 0;
      virtual Vec<Vec<float>> load_by_id(const Vec<int> &ids) = 0;
      virtual Vec<Vec<float>> load_by_index(const Vec<int> &indexes) = 0; //! Change argument type when figure out how to index data
  };

  class StorageEngine
  {
    protected:
      virtual std::unique_ptr<Indexer> indexer_type() = 0;
      virtual std::unique_ptr<Storage> storage_type() = 0;
    public:
      void persist(const Vec<Vec<float>> &data);
      Vec<Vec<float>> load_by_id(const Vec<int> &ids);

      // Vec<Vec<float>> load_by_index(const Vec<int> &indexes){
      //   return storage_type()->load_by_index(indexes);
      // }

      // Vec<Vec<float>> load_by_proximity(const Vec<float> &query){
      //   look for data with similar index to query, the load_by_index (don't know how to implement this yet)
      // }
  };

} // namespace olive