#pragma once
#include <iostream>
#include <vector>
#include <cstdint>
#include <memory>
#include <map>
#include "vector/vec.h"
#include "storage/storage.h"
#include "query/query.h"



namespace olive
{

  class Indexer
  {
    public:
      virtual Vec<uint64_t> get_indexes(const Vec<float> &query) = 0;
      virtual Vec<uint64_t> get_indexes(const Vec<uint64_t> &shortlist) = 0;
      Vec<uint64_t> retrieve_candidate_ids(const Vec<Vec<float>> &query);
      void set_index(const Vec<Vec<float>> &data);
  };

  class LSHIndexer : public Indexer
  {
    public:
      Vec<uint64_t> get_indexes(const Vec<float> &query) override;
      Vec<uint64_t> get_indexes(const Vec<uint64_t> &shortlist) override;

      LSHIndexer(int ndim, int nhashes, int ntables);
  };

  class HNSWIndexer : public Indexer
  {
    public:
      Vec<uint64_t> get_indexes(const Vec<float> &query) override;
      Vec<uint64_t> get_indexes(const Vec<uint64_t> &shortlist) override;
      HNSWIndexer(int ndim, int nhashes, int ntables);
  };

  

} // namespace olive
