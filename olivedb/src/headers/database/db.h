#pragma once
#include "engines/query.h"
#include "engines/storage.h"

#include <iostream>


namespace olive
{
  class OliveDBSettings
  {
    friend class OliveBuilder;
    friend class OliveDB;
    
    private:
      std::string storage;
      std::string distance_method;      
      int ndim;
      Preprocessor preprocessor;
      // there may be more settings in the future
      OliveDBSettings();

    public:
      friend std::ostream& operator<<(std::ostream& os, const OliveDBSettings& settings);
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
        settings.storage = storage;
        return *this;
      }
      
      OliveBuilder& distance_method(const std::string& distance_method){
        settings.distance_method = distance_method;
        return *this;
      }

      OliveBuilder& ndim(int ndim){
        settings.ndim = ndim;
        return *this;
      }

      OliveBuilder& preprocessor(bool to_lowercase){
        settings.preprocessor = Preprocessor();
        return *this;
      }
  };

  class OliveDB
  {
    friend class OliveBuilder;
    
    private:
      OliveDBSettings settings;
      bool is_active = false;
      OliveDB(const OliveDBSettings& settings): settings(settings){};
    public:
      static OliveBuilder builder();

      OliveDB& activate(); // turns the flag is_active to true, creates the necessary files and directories, initializes the storage engine and the query engine and returns a self reference
  };

} // namespace olive