#pragma once
#include <query/query.h>
#include <storage/storage.h>
#include <vector/vec.h>
#include <preprocess/preprocess.h>

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
      OliveBuilder();
      void display_settings();
      OliveDB build();
      OliveBuilder& storage(const StorageType storage);      
      OliveBuilder& distance_method(const QueryType distance_method);
      OliveBuilder& ndim(int ndim);
      OliveBuilder& preprocessor(Preprocessor preprocessor);
      OliveBuilder& global_indexer(Indexer* indexer);
      OliveBuilder& local_indexer(Indexer* indexer);
  };

  /**
   * @brief The vector database class, implementing the StorageEngine, SearchEngine and IndexerEngine interfaces
  */
  class OliveDB: public StorageEngine, public SearchEngine, public IndexerEngine
  {
    friend class OliveBuilder;
    private:
      OliveDBSettings settings;
      OliveDB(const OliveDBSettings& settings);
    public:
      static OliveBuilder builder();
      std::unique_ptr<Storage> storage_type() override;
      std::unique_ptr<Query> query_type() override;
      std::string storage_path() override;
      Vec<Vec<float>> loaded_data() override; // calls indexer deducer -> calls load_by_index -> temporarily stores data in memory -> returns data
      ~OliveDB(){
        deactivate();
      }
  };

} // namespace olive