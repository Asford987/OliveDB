#pragma once
#include <iostream>
#include <vector>
#include <cstdint>
#include <memory>
#include <map>
#include <functional>
#include <vector/vec.h>
#include <storage/storage.h>
#include <query/query.h>
#include <indexer/indexer.h>

namespace olive
{

  class SearchEngine
  {
    protected:
      virtual std::unique_ptr<Query> query_type() = 0;
      virtual Vec<Vec<float>> load_data_by_queries(const Vec<Vec<float>> &query) = 0;

    public:
      std::map<std::pair<uint64_t, uint64_t>, float> search(Vec<Vec<float>> &query, int num_results);
  };

  class StorageEngine
  {
    protected:
      virtual std::unique_ptr<Storage> storage_type() = 0;
    public:
      bool activate();
      bool deactivate();
      void persist(const Vec<Vec<float>> &data);
      Vec<Vec<float>> load_by_id(const Vec<uint64_t> &ids);
      Vec<Vec<float>> load_by_index(const Vec<uint64_t> &indexes);

  };

  class IndexerEngine{
    public:
      virtual std::unique_ptr<Indexer> indexer_type() = 0;
      virtual Vec<uint64_t> get_indexes(const Vec<Vec<float>> &data);
      virtual void set_index(const Vec<Vec<float>> &data);
  };

} // namespace olive