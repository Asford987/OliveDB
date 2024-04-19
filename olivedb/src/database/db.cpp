#include "database/db.h"


namespace olive
{

  std::ostream& operator<<(std::ostream& os, const OliveDBSettings& settings)
  {
    // os << "OliveDBSettings(\n\tstorage=" << settings.storage << ",\n\tdistance_method=" 
    // << settings.distance_method << "\n\tndim=" << settings.ndim << "\n\tPreprocessor=" 
    // << settings.preprocessor << "\n\t)"; 
    return os;
  }

  void OliveDBSettings::set_storage(Storage* storage)
  {
    this->storage = storage;
  }

  void OliveDBSettings::set_distance_method(Query* distance_method)
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

  void OliveDBSettings::set_indexer(Indexer* indexer)
  {
    this->indexer = indexer;
  }

  OliveBuilder::OliveBuilder()
  {
    settings = OliveDBSettings();
  }

  void OliveBuilder::display_settings()
  {
    std::cout << settings << std::endl;
  }

  OliveDB OliveBuilder::build()
  {
    return OliveDB(settings);
  }

  OliveBuilder &OliveBuilder::storage(Storage* storage)
  {
    settings.set_storage(storage);
    return *this;
  }

  OliveBuilder &OliveBuilder::distance_method(Query* distance_method)
  {
    settings.set_distance_method(distance_method);
    return *this;
  }

  OliveBuilder &OliveBuilder::ndim(int ndim)
  {
    settings.set_ndim(ndim);
    return *this;
  }

  OliveBuilder &OliveBuilder::preprocessor(Preprocessor preprocessor)
  {
    settings.set_preprocessor(preprocessor);
    return *this;
  }

  OliveDB::OliveDB(const OliveDBSettings& settings): settings(settings)
  {
  }

  OliveBuilder OliveDB::builder()
  {
    return OliveBuilder();
  }

  std::unique_ptr<Storage> OliveDB::storage_type()
  {

  }

  std::unique_ptr<Query> OliveDB::query_type()
  {

  }

  std::unique_ptr<Indexer> OliveDB::indexer_type()
  {

  }

  std::string OliveDB::storage_path()
  {

  }

  

  Vec<Vec<float>> OliveDB::loaded_data(){
    // check if data was already loaded
    // if not, load data with storage engine's methods
    return Vec<Vec<float>>();
  }

} // namespace olive
