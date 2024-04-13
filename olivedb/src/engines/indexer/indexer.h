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
      virtual Vec<uint64_t> get_indexes(const Vec<float> &query) = 0;
      virtual Vec<uint64_t> get_indexes(const Vec<uint64_t> &shortlist) = 0;
    public:
      Vec<uint64_t> retrieve_candidate_ids(const Vec<Vec<float>> &query);
      void set_index(const Vec<Vec<float>> &data);
  };

  class LSHIndexer : public Indexer
  {
    private:
      Vec<uint64_t> get_indexes(const Vec<float> &query) override;
    public:
      LSHIndexer(int ndim, int nhashes, int ntables);
  };

  class HNSWIndexer : public Indexer
  {
    private:
      Vec<uint64_t> get_indexes(const Vec<float> &query) override;
    public:
      HNSWIndexer(int ndim, int nhashes, int ntables);
  };

  

} // namespace olive
