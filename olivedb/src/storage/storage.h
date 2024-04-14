#pragma once
#include <string>
#include <vector>
#include <cstdint>
#include <vector/vec.h>

namespace olive
{
  class Storage
  {
    public:
      virtual void persist(const Vec<Vec<float>> &data) = 0;
      virtual Vec<Vec<float>> load_by_id(const Vec<uint64_t> &ids) = 0;
      virtual Vec<Vec<float>> load_by_index(const Vec<uint64_t> &indexes) = 0; //! Change argument type when figure out how to index data
      virtual bool activate(std::string path) = 0;
      virtual bool deactivate() = 0;
  };

  class MemoryStorage : public Storage
  {
    public:
      void persist(const Vec<Vec<float>> &data) override;
      Vec<Vec<float>> load_by_id(const Vec<uint64_t> &ids) override;
      Vec<Vec<float>> load_by_index(const Vec<uint64_t> &indexes) override;
      bool activate(std::string path) override{ return true; }
      bool deactivate() override{ return false; }
  };

  class DiskStorage : public Storage
  {
    public:
      void persist(const Vec<Vec<float>> &data) override;
      Vec<Vec<float>> load_by_id(const Vec<uint64_t> &ids) override;
      Vec<Vec<float>> load_by_index(const Vec<uint64_t> &indexes) override;
      bool activate(std::string path) override;
      bool deactivate() override;
  };

  class MongoStorage : public Storage
  {
    public:
      void persist(const Vec<Vec<float>> &data) override;
      Vec<Vec<float>> load_by_id(const Vec<uint64_t> &ids) override;
      Vec<Vec<float>> load_by_index(const Vec<uint64_t> &indexes) override;
      bool activate(std::string path) override;
      bool deactivate() override;
  };

} // namespace olive
