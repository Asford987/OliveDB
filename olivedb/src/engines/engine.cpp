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
    if(num_results==0) return results;
    else {
      std::map<std::pair<uint64_t, uint64_t>, float> top_results;
      for(int i=0; i<num_results; i++){
        float max = 0;
        std::pair<uint64_t, uint64_t> max_pair;
        for(auto &r : results){
          if(r.second > max){
            max = r.second;
            max_pair = r.first;
          }
        }
        top_results[max_pair] = max;
        results.erase(max_pair);
      }
      return top_results;
    }
  }

  SearchEngine::~SearchEngine()
  {
    delete query_type();
  }

  bool StorageEngine::activate()
  {
    return storage_type()->activate();
  }
  
  bool StorageEngine::deactivate()
  { 
    return storage_type()->deactivate(); 
  }

  void StorageEngine::persist(Vec<Vec<float>> &data)
  {
    storage_type()->persist(data);
  }

  Vec<Vec<float>> StorageEngine::load_by_id(Vec<uint64_t> &ids)
  {
    return storage_type()->load_by_id(ids);
  }

  Vec<Vec<float>> StorageEngine::load_by_index(Vec<uint64_t> &indexes){
    return storage_type()->load_by_index(indexes);
  }

  StorageEngine::~StorageEngine()
  {
    deactivate();
    delete storage_type();
  }

  Vec<uint64_t> IndexerEngine::get_indexes(const Vec<Vec<float>> &data)
  {
    return indexer_type()->get_indexes(data);
  }

  void IndexerEngine::set_index(Vec<Vec<float>> &data)
  {
    Vec<uint64_t> indexes = get_indexes(data);
    for(size_t i = 0; i < data.size(); i++)
    {
      data[i].metadata().index = indexes[i];
    }
  }

  IndexerEngine::~IndexerEngine()
  {
    delete indexer_type();
  }

} // namespace olive
