#include "engine.h"

namespace olive
{
  std::map<size_t, float> SearchEngine::search(const Vec<float> &query, int num_results)
  {
    Vec<Vec<float>> data = loaded_data();
    std::map<size_t, float> results; //! Temporary solution for Vec metadata: using size_t as id
    for(auto &d : data)
    {
      // results[d] = query_type()->similarity(query, d); // Make it results[id] = similarity
    }
    return results;
  }

  void StorageEngine::persist(const Vec<Vec<float>> &data)
  {
    storage_type()->persist(data);
  }

  Vec<Vec<float>> StorageEngine::load_by_id(const Vec<int> &ids)
  {
    return storage_type()->load_by_id(ids);
  }
} // namespace olive
