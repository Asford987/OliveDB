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
  class MetadataModifier
  {
    private:
      MetadataModifier();
    public:
      MetadataModifier& get_instance();
      void modify_id();
      void modify_index();

  };

} // namespace olive
