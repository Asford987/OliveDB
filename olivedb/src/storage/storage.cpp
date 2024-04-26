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

  std::string DiskStorage::get_file_path()
  {
    if(!is_active)
      throw std::runtime_error("Storage not active");
    return this->file_path;
  }

  void DiskStorage::set_file_path(std::string file_path)
  {
    this->file_path = file_path;
  }

  StorageMetadata DiskStorage::get_metadata()
  {
    if(!is_active)
    {
      throw std::runtime_error("Storage not active");
    }
    return this->metadata;
  }

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
    if(cache_indexes == indexes) return cache;

    auto path = this->get_file_path();
    auto meta = get_metadata();
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  }

  bool DiskStorage::activate() {
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    is_active = true;
    return is_active;
  }

  bool DiskStorage::deactivate() {
    is_active = false;
    return is_active;
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
    if(cache_indexes == indexes) return cache;
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  }

  bool MongoStorage::activate() {
    //conn.open(get_file_path());
    //if(!conn.is_open()) thow runtime_error();
    is_active = true;
    return is_active;
  }

  bool MongoStorage::deactivate() {
    is_active = false;
    return is_active;
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  }

  std::string MongoStorage::get_file_path()
  {
    if(!is_active)
      throw std::runtime_error("Storage not active");
    return this->file_path;
  }

  void MongoStorage::set_file_path(std::string file_path)
  {
    this->file_path = file_path;
  }

} // namespace olive