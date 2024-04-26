#include "storage.h"


namespace olive
{
  void MemoryStorage::persist(Vec<Vec<float>> &data)
  {
    this->data.append(data);
  }

  Vec<Vec<float>> MemoryStorage::load_by_id(Vec<uint64_t> &ids)
  {
    Vec<Vec<float>> result;
    for(auto &id : ids)
    {
      for(auto &d : this->data)
      {
        if(d.metadata().id == id)
        {
          result.push_back(d);
        }
      }
    }
    return result;
  }

  Vec<Vec<float>> MemoryStorage::load_by_index(Vec<uint64_t> &indexes)
  {
    Vec<Vec<float>> result;
    for(auto &index : indexes)
    {
      for(auto &d : this->data)
      {
        if(d.metadata().index == index)
        {
          result.push_back(d);
        }
      }
    }
    return result;
  }

  bool MemoryStorage::activate() { return true; }
  
  bool MemoryStorage::deactivate() { return false; }

  void DiskStorage::persist(Vec<Vec<float>> &data)
  {
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  }

  Vec<Vec<float>> DiskStorage::load_by_id(Vec<uint64_t> &ids)
  {
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }

  Vec<Vec<float>> DiskStorage::load_by_index(Vec<uint64_t> &indexes)
  {
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  }

  bool DiskStorage::activate() {
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    return true;
  }

  bool DiskStorage::deactivate() {
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    return false; 
  }

  void MongoStorage::persist(Vec<Vec<float>> &data)
  {
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  }

  Vec<Vec<float>> MongoStorage::load_by_id(Vec<uint64_t> &ids)
  {
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  }

  Vec<Vec<float>> MongoStorage::load_by_index(Vec<uint64_t> &indexes)
  {
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  }

  bool MongoStorage::activate() {
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  }

  bool MongoStorage::deactivate() {
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  }

} // namespace olive