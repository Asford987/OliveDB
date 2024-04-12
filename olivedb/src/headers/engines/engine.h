#pragma once


namespace olive
{

  class QueryEngine
  {
  };

  class StorageEngine
  {
  };

  class Preprocessor
  {  

    public:
      friend std::ostream& operator<<(std::ostream& os, const Preprocessor& preprocessor);
  };

} // namespace olive