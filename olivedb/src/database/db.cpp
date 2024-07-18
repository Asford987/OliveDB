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
    if(settings.storage == nullptr)
    {
      throw std::runtime_error("Storage type not set");
    }
    if(settings.distance_method == nullptr)
    {
      throw std::runtime_error("Distance method algorithm not set");
    }
    if(settings.indexer == nullptr)
    {
      throw std::runtime_error("Indexer algorithm not set");
    }
    if(settings.ndim <= 0)
    {
      throw std::runtime_error(std::string("Number of dimensions not set or invalid: it must be a positive integer. Current value: ") + std::to_string(settings.ndim));
    }

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

  Storage* OliveDB::storage_type()
  {
    if(storage == nullptr)
    {
      storage = settings.storage;
    }
    return std::move(storage);
  }

  Query* OliveDB::query_type()
  {
    if(distance_method == nullptr)
    {
      distance_method = settings.distance_method;
    }
    return std::move(distance_method);
  }

  Indexer* OliveDB::indexer_type()
  {
    if(indexer == nullptr)
    {
      indexer = settings.indexer;
    }
    return std::move(indexer);
  }

  Vec<Vec<float>> OliveDB::load_data_by_queries(const Vec<Vec<float>> &query)
  {
    if(last_query == query)
    {
      return last_retrieval;
    }
    auto indexes = get_indexes(query);
    return storage_type()->load_by_index(indexes);
  }

  std::map<std::pair<uint64_t, uint64_t>, float> OliveDB::search(std::vector<std::string> &sentences, int k)
  {
    auto query_vectorized = settings.preprocessor.apply(sentences);
    return SearchEngine::search(query_vectorized, k);
  }


} // namespace olive
