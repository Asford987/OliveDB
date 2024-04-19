
#pragma once
#include <string>
#include <vector>
#include <cstdint>
#include <memory>
#include <map>
#include <functional>
#include <vector/vec.h>
#include <storage/storage.h>
#include <query/query.h>
#include <indexer/indexer.h>


namespace olive
{

  class Metadata
  {
    friend class MetadataModifier;
    private:
      uint64_t id=0;
      uint64_t index = 0;
  };
} // namespace olive
