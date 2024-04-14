#pragma once
#include <cmath>
#include <engines/engine.h>
#include <vector/vec.h>

namespace olive
{

  class Query
  {
    public:
      virtual float similarity(const Vec<float> &query, const Vec<float> &data) = 0;
  };

  class CosineSimilarity : public Query
  {
    public:
      float similarity(const Vec<float> &query, const Vec<float> &data) override;
  };

  class JaccardSimilarity : public Query
  {
    public:
      float similarity(const Vec<float> &query, const Vec<float> &data) override;
  };

  class EuclideanSimilarity : public Query
  {
    public:
      float similarity(const Vec<float> &query, const Vec<float> &data) override;
  };

  class ManhattanSimilarity : public Query
  {
    public:
      float similarity(const Vec<float> &query, const Vec<float> &data) override;
  };

  class HammingSimilarity : public Query
  {
    public:
      float similarity(const Vec<float> &query, const Vec<float> &data) override;
  };

} // namespace olive