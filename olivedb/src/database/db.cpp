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

  void OliveDBSettings::set_storage(const std::string& storage)
  {
    this->storage = storage;
  }

  void OliveDBSettings::set_distance_method(const std::string& distance_method)
  {
    this->distance_method = distance_method;
  }

  void OliveDBSettings::set_ndim(int ndim)
  {
    this->ndim = ndim;
  }

  void OliveDBSettings::set_preprocessor(Preprocessor preprocessor)
  {
    this->preprocessor = preprocessor;
  }

  void OliveDBSettings::set_indexer(int layer, Indexer* indexer)
  {
    indexers[layer] = indexer;
  }

  Vec<Vec<float>> OliveDB::loaded_data(){
    // check if data was already loaded
    // if not, load data with storage engine's methods
    return Vec<Vec<float>>();
  }

} // namespace olive
