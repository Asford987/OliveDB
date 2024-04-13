#pragma once
#include <cmath>
#include "engines/engine.h"


namespace olive
{
  class CosineSimilarity : public Query
  {
    protected:
      virtual float similarity(const Vec<float> &query, const Vec<float> &data) override{
        return query.dot(data) / (query.norm() * data.norm());
      }
  };

  class JaccardSimilarity : public Query
  {
    protected:
      virtual float similarity(const Vec<float> &query, const Vec<float> &data) override;
  };

  class EuclideanSimilarity : public Query
  {
    protected:
      virtual float similarity(const Vec<float> &query, const Vec<float> &data) override{
        return std::sqrt((query - data).pow(2).sum());
      }
  };

  class ManhattanSimilarity : public Query
  {
    protected:
      virtual float similarity(const Vec<float> &query, const Vec<float> &data) override{
        return (query - data).abs().sum();
      }
  };

  class HammingSimilarity : public Query
  {
    protected:
      virtual float similarity(const Vec<float> &query, const Vec<float> &data) override{
        return (query != data).sum();
      }
  };

} // namespace olive