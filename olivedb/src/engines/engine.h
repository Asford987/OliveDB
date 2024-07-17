#pragma once
#include <iostream>
#include <vector>
#include <cstdint>
#include <memory>
#include <map>
#include <functional>
#include "query/query.h"
#include "indexer/indexer.h"
#include "storage/storage.h"
#include "vector/vec.h"

namespace olive
{

  class SearchEngine
  {
    protected:
      virtual Query* query_type() = 0;
      virtual Vec<Vec<float>> load_data_by_queries(const Vec<Vec<float>> &query) = 0;

    public:
      std::map<std::pair<uint64_t, uint64_t>, float> search(Vec<Vec<float>> &query, int num_results = 0);
  };

  class StorageEngine
  {
    protected:
      virtual Storage* storage_type() = 0;
    public:
      bool activate();
      bool deactivate();
      void persist(Vec<Vec<float>> &data);
      Vec<Vec<float>> load_by_id(Vec<uint64_t> &ids);
      Vec<Vec<float>> load_by_index(Vec<uint64_t> &indexes);

  };

  class IndexerEngine{
    public:
      virtual Indexer* indexer_type() = 0;
      virtual Vec<uint64_t> get_indexes(const Vec<Vec<float>> &data);
      virtual void set_index(Vec<Vec<float>> &data);
  };

} // namespace olive