#pragma once
#include <iostream>
#include <vector>
#include <cstdint>
#include <memory>
#include <map>
#include <functional>
#include "vector/vec.h"
#include "storage/storage.h"
#include "query/query.h"
#include "indexer/indexer.h"

namespace olive
{

  class Preprocessor
  {
    private:
      std::function<Vec<Vec<float>>(std::vector<std::string>)> preprocess_function;

    public:
      friend std::ostream &operator<<(std::ostream &os, const Preprocessor &preprocessor);
      Vec<Vec<float>> apply(std::vector<std::string> &sentence){ return preprocess_function(sentence);}
      
      Preprocessor& operator=(const Preprocessor &preprocessor){ 
        preprocess_function = preprocessor.preprocess_function;
        return *this;
      }

      Preprocessor &add_preprocess_function(std::function<Vec<Vec<float>>(std::vector<std::string>)> &preprocess_function)
      {
        this->preprocess_function = preprocess_function;
        return *this;
      }

      Preprocessor(): preprocess_function([](std::vector<std::string> sentence){ return Vec<Vec<float>>(); }) {}
      Preprocessor(std::function<Vec<Vec<float>>(std::vector<std::string>)> &preprocess_function) : preprocess_function(preprocess_function) {}
  };

  class SearchEngine
  {
    protected:
      virtual std::unique_ptr<Query> query_type() = 0;
      virtual Vec<Vec<float>> loaded_data() = 0;
    public:
      std::map<uint64_t, float> search(const Vec<float> &query, int num_results);
  };

  class StorageEngine
  {
    protected:
      virtual std::unique_ptr<Storage> storage_type() = 0;
      virtual std::string storage_path() = 0;
    public:
      bool activate() { return storage_type()->activate(storage_path()); }
      bool deactivate() { return storage_type()->deactivate(); }
      void persist(const Vec<Vec<float>> &data);
      Vec<Vec<float>> load_by_id(const Vec<uint64_t> &ids);

      Vec<Vec<float>> load_by_index(const Vec<uint64_t> &indexes); //{
      //   return storage_type()->load_by_index(indexes);
      // }

  };

  class IndexerEngine{

  };

} // namespace olive