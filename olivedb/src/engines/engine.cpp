#include <map>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include "engines/engine.h"

namespace olive
{
  std::map<uint64_t, float> SearchEngine::search(const Vec<float> &query, int num_results)
  {
    Vec<Vec<float>> data = loaded_data();
    std::map<uint64_t, float> results; 
    for(auto &d : data)
    {
      results[d.metadata().id] = query_type()->similarity(query, d);
    }
    return results;
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

} // namespace olive
