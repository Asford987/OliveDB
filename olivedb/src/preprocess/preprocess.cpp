#include <iostream>
#include <vector>
#include <cstdint>
#include <memory>
#include <map>
#include <functional>
#include "preprocess.h"
#include <vector/vec.h>
#include <storage/storage.h>
#include <query/query.h>
#include <indexer/indexer.h>



namespace olive
{

  

  Vec<Vec<float>> Preprocessor::apply(std::vector<std::string> &sentence) { return preprocess_function(sentence); }

  Preprocessor &Preprocessor::operator = (const Preprocessor &preprocessor)
  {
    preprocess_function = preprocessor.preprocess_function;
    return *this;
  }

  Preprocessor &Preprocessor::add_preprocess_function(std::function<Vec<Vec<float>>(std::vector<std::string>)> &preprocess_function)
  {
    this->preprocess_function = preprocess_function;
    return *this;
  }

  Preprocessor::Preprocessor() : preprocess_function([](std::vector<std::string> sentence)
                                       { return Vec<Vec<float>>(); }) {}

  Preprocessor::Preprocessor(std::function<Vec<Vec<float>>(std::vector<std::string>)> &preprocess_function) : preprocess_function(preprocess_function) {}

} // namespace olive
