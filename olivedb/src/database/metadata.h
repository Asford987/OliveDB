#pragma once

#include <string>
#include <chrono>
#include <unordered_map>

class DatabaseMetadata {
public:
    DatabaseMetadata(const std::string& name);

    const std::string& getDatabaseName() const;
    void setDatabaseName(const std::string& name);

    const std::chrono::system_clock::time_point& getCreationTimestamp() const;
    void setCreationTimestamp(const std::chrono::system_clock::time_point& timestamp);

    const std::chrono::system_clock::time_point& getModificationTimestamp() const;
    void setModificationTimestamp(const std::chrono::system_clock::time_point& timestamp);

    size_t getNumberOfVectors() const;
    void setNumberOfVectors(size_t count);

    const std::unordered_map<std::string, std::string>& getIndexInformation() const;
    void addIndexInformation(const std::string& indexName, const std::string& status);

    size_t getStorageSize() const;
    void setStorageSize(size_t size);

    size_t getNumberOfUsers() const;
    void setNumberOfUsers(size_t count);

    const std::unordered_map<std::string, std::string>& getAccessPermissions() const;
    void addAccessPermission(const std::string& user, const std::string& permission);

    const std::unordered_map<std::string, std::string>& getDataSources() const;
    void addDataSource(const std::string& sourceName, const std::string& details);

    const std::string& getSchemaVersion() const;
    void setSchemaVersion(const std::string& version);

    const std::unordered_map<std::string, std::chrono::system_clock::time_point>& getBackupInformation() const;
    void addBackupInformation(const std::string& location, const std::chrono::system_clock::time_point& timestamp);

    const std::unordered_map<std::string, double>& getPerformanceMetrics() const;
    void addPerformanceMetric(const std::string& metricName, double value);

    const std::unordered_map<std::string, std::string>& getConfigurationParameters() const;
    void addConfigurationParameter(const std::string& parameterName, const std::string& value);

private:
    std::string databaseName;
    std::chrono::system_clock::time_point creationTimestamp;
    std::chrono::system_clock::time_point modificationTimestamp;
    size_t numberOfVectors;
    std::unordered_map<std::string, std::string> indexInformation;
    size_t storageSize;
    size_t numberOfUsers;
    std::unordered_map<std::string, std::string> accessPermissions;
    std::unordered_map<std::string, std::string> dataSources;
    std::string schemaVersion;
    std::unordered_map<std::string, std::chrono::system_clock::time_point> backupInformation;
    std::unordered_map<std::string, double> performanceMetrics;
    std::unordered_map<std::string, std::string> configurationParameters;
};
