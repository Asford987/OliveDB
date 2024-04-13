#include "engine.h"

namespace olive
{
  std::map<Vec<float>, float> SearchEngine::search(const Vec<float> &query, int num_results)
  {
    Vec<Vec<float>> data = loaded_data();
    // compute similarities between query and data and order the results
    return std::map<Vec<float>, float>();
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
