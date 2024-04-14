#pragma once
#include <iostream>
#include <vector>
#include <cstdint>
#include <memory>
#include <map>
#include <functional>
#include "vector/vec.h"
#include "storage/storage.h"
#include "query/query.h"
#include "indexer/indexer.h"

namespace olive
{
  class Preprocessor
  {
  private:
    std::function<Vec<Vec<float>>(std::vector<std::string>)> preprocess_function;
  public:
    friend std::ostream &operator<<(std::ostream &os, const Preprocessor &preprocessor);
    Vec<Vec<float>> apply(std::vector<std::string> &sentence);
    Preprocessor &operator=(const Preprocessor &preprocessor);
    Preprocessor &add_preprocess_function(std::function<Vec<Vec<float>>(std::vector<std::string>)> &preprocess_function);
    Preprocessor();
    Preprocessor(std::function<Vec<Vec<float>>(std::vector<std::string>)> &preprocess_function);
  };

} // namespace olive
