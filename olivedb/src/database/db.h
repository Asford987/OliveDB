#pragma once
#include "query/query.h"
#include "storage/storage.h"
#include "vector/vec.h"

#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <functional>


namespace olive
{
  /**
   * @brief Enum class for the type of query to be used
   * 
  */
  enum class QueryType{
    COSINE,
    JACCARD,
    EUCLIDEAN,
    MANHATTAN,
    HAMMING
  };

  /**
   * @brief Enum class for the type of storage to be used
   * 
  */
  enum class StorageType{
    MEMORY,
    DISK,
    MONGO,

  };

  // std::map<QueryType, std::function<std::unique_ptr<Query>>> query_creators = {
  //     {QueryType::COSINE, []() -> std::unique_ptr<Query>
  //      { return std::make_unique<CosineSimilarity>(); }},
  //     {QueryType::JACCARD, []() -> std::unique_ptr<Query>
  //      { return std::make_unique<JaccardSimilarity>(); }},
  //     {QueryType::EUCLIDEAN, []() -> std::unique_ptr<Query>
  //      { return std::make_unique<EuclideanSimilarity>(); }},
  //     {QueryType::MANHATTAN, []() -> std::unique_ptr<Query>
  //      { return std::make_unique<ManhattanSimilarity>(); }},
  //     {QueryType::HAMMING, []() -> std::unique_ptr<Query>
  //      { return std::make_unique<HammingSimilarity>(); }},
  // };

  // std::map<StorageType, std::function<std::unique_ptr<Storage>>> storage_creators = {
  //     {StorageType::MEMORY, []() -> std::unique_ptr<Storage>
  //      { return std::make_unique<MemoryStorage>(); }},
  //     {StorageType::DISK, []() -> std::unique_ptr<Storage>
  //      { return std::make_unique<DiskStorage>(); }},
  //     {StorageType::MONGO, []() -> std::unique_ptr<Storage>
  //      { return std::make_unique<MongoStorage>(); }},
  // };

  /**
   * @brief Settings class for the OliveDB class
  */
  class OliveDBSettings
  {
    friend class OliveDB;
    
    private:
      StorageType storage;
      QueryType distance_method;      
      int ndim;
      Preprocessor preprocessor;
      std::map<int, Indexer*> indexers;
      // there may be more settings in the future

    public:
      friend std::ostream& operator<<(std::ostream& os, const OliveDBSettings& settings);
      OliveDBSettings();
      void set_storage(const StorageType storage);
      void set_distance_method(const QueryType distance_method);
      void set_ndim(int ndim);
      void set_preprocessor(Preprocessor preprocessor);
      void set_indexer(int layer, Indexer* indexer); 


  };

  /**
   * @brief Builder class for the OliveDB class
  */
  class OliveBuilder
  {
    private:
      OliveDBSettings settings;
    public:
      OliveBuilder(){
        settings = OliveDBSettings();
      }

      void display_settings(){
        std::cout << settings << std::endl;
      }

      OliveDB build(){
        return OliveDB(settings);
      }

      OliveBuilder& storage(const StorageType storage){
        settings.set_storage(storage);
        return *this;
      }
      
      OliveBuilder& distance_method(const QueryType distance_method){
        settings.set_distance_method(distance_method);
        return *this;
      }

      OliveBuilder& ndim(int ndim){
        settings.set_ndim(ndim);
        return *this;
      }

      OliveBuilder& preprocessor(Preprocessor preprocessor){
        settings.set_preprocessor(preprocessor);
        return *this;
      }

      OliveBuilder& global_indexer(Indexer* indexer){
        settings.set_indexer(0, indexer);
        return *this;
      }

      OliveBuilder& local_indexer(Indexer* indexer){
        settings.set_indexer(1, indexer);
        return *this;
      }
  };

  /**
   * @brief The vector database class, implementing the StorageEngine, SearchEngine and IndexerEngine interfaces
  */
  class OliveDB: public StorageEngine, public SearchEngine, public IndexerEngine
  {
    friend class OliveBuilder;
    
    private:
      OliveDBSettings settings;
      
      OliveDB(const OliveDBSettings& settings): settings(settings){

      };
    public:
      static OliveBuilder builder(){ return OliveBuilder(); }

      /**
       * @brief pointer to the storage dynamic class, defining the persistence mechanism
       */
      std::unique_ptr<Storage> storage_type() override;
      /**
       * @brief pointer to the query dynamic class, defining the distance calculation method
       */
      std::unique_ptr<Query> query_type() override;
      
      /**
       * @brief Defines the storage path, if applicable
      */
      std::string storage_path() override;
      
      /**
       * @brief Retrieves the already loaded data, if applicable. Otherwise, loads the data from the storage
      */
      Vec<Vec<float>> loaded_data() override;

      
      ~OliveDB(){
        deactivate();
      }
  };

} // namespace olive