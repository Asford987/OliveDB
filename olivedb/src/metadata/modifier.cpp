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

  MetadataModifier& MetadataModifier::get_instance()
  {
    static MetadataModifier instance;
    return instance;
  }

  void MetadataModifier::modify_id()
  {
  }

  void MetadataModifier::modify_index()
  {
  }

} // namespace olive