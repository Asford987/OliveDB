#pragma once
#include <iostream>
#include <vector>
#include <cstdint>
#include <memory>
#include <map>
#include "query/query.h"
#include "storage/storage.h"
#include "vector/vec.h"



namespace olive
{
  class Indexer
  {
    public:
      virtual Vec<uint64_t> get_indexes(const Vec<Vec<float>> &query) = 0;
  };

  class LSHIndexer : public Indexer
  {
    private:
      uint64_t num_buckets;
      int ndim;
    public:
      Vec<uint64_t> get_indexes(const Vec<Vec<float>> &query) override;
      LSHIndexer(int num_tables, int num_projections, int ndim);
  };

  class HNSWIndexer : public Indexer
  {
    public:
      Vec<uint64_t> get_indexes(const Vec<Vec<float>> &query) override;
      HNSWIndexer(int M, int efConstruction, int efSearch, int ndim);
  };
} // namespace olive
