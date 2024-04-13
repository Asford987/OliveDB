#pragma once
#include <iostream>
#include <vector>
#include <cstdint>
#include <memory>
#include <map>
#include "vector/vec.h"
#include "engines/storage/storage.h"
#include "engines/query/query.h"



namespace olive
{

  class MetadataModifier{
    
  };

  class Indexer
  {
    private:
      virtual uint64_t get_index(const Vec<float> &data) = 0;
    public:
      Vec<Vec<uint64_t>> retrieve_candidates_ids(const Vec<Vec<float>> &query);
      void set_index(const Vec<Vec<float>> &data);
  };

  class LSHIndexer : public Indexer
  {
    private:
      uint64_t get_index(const Vec<float> &data) override;
    public:
      LSHIndexer(int ndim, int nhashes, int ntables);
  };

  class HNSWIndexer : public Indexer
  {
    private:
      uint64_t get_index(const Vec<float> &data) override;
    public:
      HNSWIndexer(int ndim, int nhashes, int ntables);
  };

  

} // namespace olive
