#pragma once
#include <iostream>
#include <vector>
#include <cstdint>
#include <memory>
#include <map>
#include <vector/vec.h>
#include <storage/storage.h>
#include <query/query.h>



namespace olive
{

  class Indexer
  {
    public:
      virtual Vec<uint64_t> get_indexes(const Vec<Vec<float>> &query) = 0;
  };

  class LSHIndexer : public Indexer
  {
  };

  class HNSWIndexer : public Indexer
  {
  };

  

} // namespace olive
