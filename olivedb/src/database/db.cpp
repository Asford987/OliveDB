#include "database/db.h"


namespace olive
{

  std::ostream& operator<<(std::ostream& os, const OliveDBSettings& settings)
  {
    os << "OliveDBSettings(\n\tstorage=" << settings.storage << ",\n\tdistance_method=" 
    << settings.distance_method << "\n\tndim=" << settings.ndim << "\n\tPreprocessor=" 
    << settings.preprocessor << "\n\t)"; 
    return os;
  }

  OliveDBSettings::OliveDBSettings()
  {
    storage = "memory";
    distance_method = "cosine";
    ndim = 0;
  }

  Vec<Vec<float>> loaded_data(){
    // check if data was already loaded
    // if not, load data with storage engine's methods
    return Vec<Vec<float>>();
  }

} // namespace olive
