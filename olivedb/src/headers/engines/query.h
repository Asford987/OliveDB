#pragma once
#include "engines/engine.h"


namespace olive
{
  class CosineSimilarityEngine : public Query
  {
  };

  class JaccardSimilarityEngine : public Query
  {
  };

  class EuclideanSimilarityEngine : public Query
  {
  };

  class ManhattanSimilarityEngine : public Query
  {
  };

  class HammingSimilarityEngine : public Query
  {
  };

  class DotProductSimilarityEngine : public Query
  {
  };

} // namespace olive