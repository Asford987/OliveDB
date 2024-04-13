#pragma once
#include <iostream>
#include <vector>
#include <cstdint>
#include <memory>
#include <map>
#include <functional>
#include "vector/vec.h"
#include "engines/storage/storage.h"
#include "engines/query/query.h"
#include "vector/vec.h"
#include "engines/indexer/indexer.h"

namespace olive
{

  class Preprocessor
  {
    private:
      std::vector<std::string> preprocess_order;
      std::map<std::string, std::function<Vec<Vec<float>>>> preprocess_functions;
    public:
      friend std::ostream &operator<<(std::ostream &os, const Preprocessor &preprocessor);
      Preprocessor& add_preprocess_function(const std::string &name, std::function<Vec<Vec<float>>> func);
      Vec<Vec<float>> apply();
      Preprocessor();
      Preprocessor(const std::vector<std::string> &preprocess_order, const std::map<std::string, std::function<Vec<Vec<float>>>> &preprocess_functions);
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