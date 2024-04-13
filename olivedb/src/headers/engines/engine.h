#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include "vector/vec.h"

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
      std::map<size_t, float> search(const Vec<float> &query, int num_results);
  };

  class Storage
  {
    public:
      virtual void persist(const Vec<Vec<float>> &data) = 0;
      virtual Vec<Vec<float>> load_by_id(const Vec<uint64_t> &ids) = 0;
      virtual Vec<Vec<float>> load_by_index(const Vec<uint64_t> &indexes) = 0; //! Change argument type when figure out how to index data
      virtual bool activate() = 0;
      virtual bool deactivate() = 0;
  };

  class StorageEngine
  {
    protected:
      virtual std::unique_ptr<Indexer> indexer_type() = 0;
      virtual std::unique_ptr<Storage> storage_type() = 0;
    public:
      bool activate(){ return storage_type()->activate(); }
      bool deactivate(){ return storage_type()->deactivate(); }
      void persist(const Vec<Vec<float>> &data);
      Vec<Vec<float>> load_by_id(const Vec<uint64_t> &ids);

      // Vec<Vec<float>> load_by_index(const Vec<int> &indexes){
      //   return storage_type()->load_by_index(indexes);
      // }

      // Vec<Vec<float>> load_by_proximity(const Vec<float> &query){
      //   look for data with similar index to query, the load_by_index (don't know how to implement this yet)
      // }
  };

} // namespace olive