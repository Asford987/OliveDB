#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <cstdint>
#include <vector/vec.h>

namespace olive
{
  class Storage
  {
    public:
      virtual void persist(Vec<Vec<float>> &data) = 0;
      virtual Vec<Vec<float>> load_by_id(Vec<uint64_t> &ids) = 0;
      virtual Vec<Vec<float>> load_by_index(Vec<uint64_t> &indexes) = 0; //! Change argument type when figure out how to index data
      virtual bool activate() = 0;
      virtual bool deactivate() = 0;
  };

  class MemoryStorage : public Storage
  {
    private:
      Vec<Vec<float>> data;
    public:
      void persist(Vec<Vec<float>> &data) override;
      Vec<Vec<float>> load_by_id(Vec<uint64_t> &ids) override;
      Vec<Vec<float>> load_by_index(Vec<uint64_t> &indexes) override;
      bool activate() override;
      bool deactivate() override;
  };

  class DiskStorage : public Storage
  {
    private:
      std::string file_path;
      std::fstream file;
      
    public:
      std::string get_file_path();
      void set_file_path(std::string file_path);



      void persist(Vec<Vec<float>> &data) override;
      Vec<Vec<float>> load_by_id(Vec<uint64_t> &ids) override;
      Vec<Vec<float>> load_by_index(Vec<uint64_t> &indexes) override;
      bool activate() override;
      bool deactivate() override;
  };

  class MongoStorage : public Storage
  {
    private: 
      std::string file_path;
    public:
      
      void persist(Vec<Vec<float>> &data) override;
      Vec<Vec<float>> load_by_id(Vec<uint64_t> &ids) override;
      Vec<Vec<float>> load_by_index(Vec<uint64_t> &indexes) override;
      bool activate() override;
      bool deactivate() override;
  };

} // namespace olive
