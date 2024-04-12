#pragma once
#include "engines/engine.h"


namespace olive
{
  class CosineSimilarityEngine : public QueryEngine
  {
  };

  class JaccardSimilarityEngine : public QueryEngine
  {
  };

  class EuclideanSimilarityEngine : public QueryEngine
  {
  };

  class ManhattanSimilarityEngine : public QueryEngine
  {
  };

  class PearsonSimilarityEngine : public QueryEngine
  {
  };

} // namespace olive