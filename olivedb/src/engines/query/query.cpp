#include "query.h"

namespace olive
{
    inline float CosineSimilarity::similarity(const Vec<float> &query, const Vec<float> &data)
    {
        return query.dot(data) / (query.norm() * data.norm());
    }

    inline float JaccardSimilarity::similarity(const Vec<float> &query, const Vec<float> &data)
    {
        return query.dot(data) / (query.norm() + data.norm() - query.dot(data));
    }

    inline float EuclideanSimilarity::similarity(const Vec<float> &query, const Vec<float> &data)
    {
        return std::sqrt((query - data).pow(2).sum());
    }

    inline float ManhattanSimilarity::similarity(const Vec<float> &query, const Vec<float> &data)
    {
        return (query - data).abs().sum();
    }

    inline float HammingSimilarity::similarity(const Vec<float> &query, const Vec<float> &data)
    {
        return (query != data).sum();
    }

    
} // namespace olive
