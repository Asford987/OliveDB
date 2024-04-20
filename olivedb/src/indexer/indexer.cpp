#include "indexer.h"



namespace olive
{
  Vec<uint64_t> LSHIndexer::get_indexes(const Vec<Vec<float>> &query)
  {
    return Vec<uint64_t>();
  }

  LSHIndexer::LSHIndexer(int num_tables, int num_projections, int ndim)
  {
  }

  Vec<uint64_t> HNSWIndexer::get_indexes(const Vec<Vec<float>> &query)
  {
    return Vec<uint64_t>();
  }

  HNSWIndexer::HNSWIndexer(int M, int efConstruction, int efSearch, int ndim)
  {
  }
} // namespace olive