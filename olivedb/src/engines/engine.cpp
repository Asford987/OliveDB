#include <map>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include "engines/engine.h"

namespace olive
{
  std::map<std::pair<uint64_t, uint64_t>, float> SearchEngine::search(Vec<Vec<float>> &query, int num_results)
  {
    Vec<Vec<float>> data = load_data_by_queries(query);
    std::map<std::pair<uint64_t, uint64_t>, float> results; 
    for(auto &d : data)
    {
      for(auto &q : query){
        auto pair = std::make_pair(d.metadata().id, q.metadata().id);
        results[pair] = query_type()->similarity(d, q);
      }
    }
    return results;
  }

  bool StorageEngine::activate()
  {
    return storage_type()->activate();
  }
  
  bool StorageEngine::deactivate()
  { 
    return storage_type()->deactivate(); 
  }

  void StorageEngine::persist(const Vec<Vec<float>> &data)
  {
    storage_type()->persist(data);
  }

  Vec<Vec<float>> StorageEngine::load_by_id(const Vec<uint64_t> &ids)
  {
    return storage_type()->load_by_id(ids);
  }

  Vec<Vec<float>> StorageEngine::load_by_index(const Vec<uint64_t> &indexes){
    return storage_type()->load_by_index(indexes);
  }

  Vec<uint64_t> IndexerEngine::get_indexes(const Vec<Vec<float>> &data)
  {
    return indexer_type()->get_indexes(data);
  }

  void IndexerEngine::set_index(const Vec<Vec<float>> &data)
  {

  }

} // namespace olive
