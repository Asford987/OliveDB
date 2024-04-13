#pragma once
#include "engines/query/query.h"
#include "engines/storage/storage.h"
#include "vector/vec.h"

#include <iostream>
#include <string>
#include <memory>


namespace olive
{

  // enum class QueryType{
  //   COSINE=CosineSimilarity,
  //   JACCARD=JaccardSimilarity,
  //   EUCLIDEAN=EuclideanSimilarity,
  //   MANHATTAN=ManhattanSimilarity,
  //   HAMMING=HammingSimilarity
  // };

  class OliveDBSettings
  {
    friend class OliveDB;
    
    private:
      std::string storage;
      std::string distance_method;      
      int ndim;
      Preprocessor preprocessor;
      // there may be more settings in the future

    public:
      friend std::ostream& operator<<(std::ostream& os, const OliveDBSettings& settings);
      OliveDBSettings();
      void set_storage(const std::string& storage);
      void set_distance_method(const std::string& distance_method);
      void set_ndim(int ndim);
      void set_preprocessor(...);

  };

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

      OliveBuilder& storage(const std::string& storage){
        settings.set_storage(storage);
        return *this;
      }
      
      OliveBuilder& distance_method(const std::string& distance_method){
        settings.set_distance_method(distance_method);
        return *this;
      }

      OliveBuilder& ndim(int ndim){
        settings.set_ndim(ndim);
        return *this;
      }

      OliveBuilder& preprocessor(...){
        settings.set_preprocessor();
        return *this;
      }
  };

  class OliveDB: public StorageEngine, public SearchEngine
  {
    friend class OliveBuilder;
    
    private:
      OliveDBSettings settings;
      OliveDB(const OliveDBSettings& settings): settings(settings){};
    public:
      static OliveBuilder builder();

      IndexerEngine indexer_engine() override;
      std::unique_ptr<Storage> storage_type() override;
      std::unique_ptr<Query> query_type() override;
      std::string storage_path() override;
      Vec<Vec<float>> loaded_data() override;
      ~OliveDB(){
        deactivate();
      }
  };

} // namespace olive