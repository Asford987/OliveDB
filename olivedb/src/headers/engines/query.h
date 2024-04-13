#pragma once
#include <cmath>
#include "engines/engine.h"


namespace olive
{
  class CosineSimilarity : public Query
  {
    public:
      inline float similarity(const Vec<float> &query, const Vec<float> &data) override;
  };

  class JaccardSimilarity : public Query
  {
    public:
      inline float similarity(const Vec<float> &query, const Vec<float> &data) override;
  };

  class EuclideanSimilarity : public Query
  {
    public:
      inline float similarity(const Vec<float> &query, const Vec<float> &data) override;
  };

  class ManhattanSimilarity : public Query
  {
    public:
      inline float similarity(const Vec<float> &query, const Vec<float> &data) override;
  };

  class HammingSimilarity : public Query
  {
    public:
      inline float similarity(const Vec<float> &query, const Vec<float> &data) override;
  };

} // namespace olive