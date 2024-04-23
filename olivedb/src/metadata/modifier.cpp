#pragma once
#include <string>
#include <vector>
#include <cstdint>
#include <memory>
#include <map>
#include <functional>
#include "modifier.h"

namespace olive
{

  MetadataModifier& MetadataModifier::get_instance()
  {
    static MetadataModifier instance;
    return instance;
  }

  void MetadataModifier::modify_id(Metadata &metadata, uint64_t id)
  {
    metadata.id = id;
  }

  void MetadataModifier::modify_index(Metadata &metadata, uint64_t index)
  {
    metadata.index = index;
    metadata.valid_index = true;
  }

} // namespace olive