#include "headers/database/db.h"


namespace olive
{

  std::ostream& operator<<(std::ostream& os, const OliveDBSettings& settings)
  {
    os << "OliveDBSettings(\n\tstorage=" << settings.storage << ",\n\tdistance_method=" << settings.distance_method << "\n\tndim=" << settings.ndim << "\n\tPreprocessor=" << settings.preprocessor << "\n\t)"; 
    return os;
  }
  
} // namespace olive
