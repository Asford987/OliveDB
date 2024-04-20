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
   * @brief Settings class for the OliveDB class
  */
  class OliveDBSettings
  {
    friend class OliveDB;
    friend class OliveBuilder;
    private:
      Storage* storage = nullptr;
      Query* distance_method = nullptr;      
      int ndim;
      Preprocessor preprocessor;
      Indexer* indexer = nullptr;

    public:
      friend std::ostream& operator<<(std::ostream& os, const OliveDBSettings& settings);
      void set_storage(Storage* storage);
      void set_distance_method(Query* distance_method);
      void set_ndim(int ndim);
      void set_preprocessor(Preprocessor preprocessor);
      void set_indexer(Indexer* indexer); 


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
      OliveBuilder& storage(Storage* storage);      
      OliveBuilder& distance_method(Query* distance_method);
      OliveBuilder& ndim(int ndim);
      OliveBuilder& preprocessor(Preprocessor preprocessor);
      OliveBuilder& indexer(Indexer* indexer);
  };

  /**
   * @brief The vector database class, implementing the StorageEngine, SearchEngine and IndexerEngine interfaces
  */
  class OliveDB: public StorageEngine, public SearchEngine, public IndexerEngine
  {
    friend class OliveBuilder;
    private:
      OliveDBSettings settings;
      std::unique_ptr<Storage> storage = nullptr;
      std::unique_ptr<Query> distance_method = nullptr;
      std::unique_ptr<Indexer> indexer = nullptr;
      Vec<Vec<float>> last_query;
      Vec<Vec<float>> last_retrieval;

      OliveDB(const OliveDBSettings& settings);
    public:
      static OliveBuilder builder();
      std::unique_ptr<Storage> storage_type() override;
      std::unique_ptr<Query> query_type() override;
      std::unique_ptr<Indexer> indexer_type() override;
      Vec<Vec<float>> load_data_by_queries(const Vec<Vec<float>> &query) override;
      ~OliveDB(){
        deactivate();
      }
  };

} // namespace olive