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
    private:
      virtual Vec<uint64_t> preprocess() = 0;
      virtual Vec<uint64_t> postprocess() = 0;
      virtual Vec<uint64_t> postprocess() = 0;

    public:
      virtual Vec<uint64_t> apply(const Vec<uint64_t> &shortlist) = 0;
      Vec<uint64_t> retrieve_candidate_ids(const Vec<Vec<float>> &query);
      void set_index(const Vec<Vec<float>> &data);
  };

  class LSHIndexer : public Indexer
  {
  };

  class HNSWIndexer : public Indexer
  {
  };

  

} // namespace olive
