#include "metadata.h"

DatabaseMetadata::DatabaseMetadata(const std::string& name)
    : databaseName(name),
      creationTimestamp(std::chrono::system_clock::now()),
      modificationTimestamp(std::chrono::system_clock::now()),
      numberOfVectors(0),
      storageSize(0),
      numberOfUsers(0) {}

const std::string& DatabaseMetadata::getDatabaseName() const { return databaseName; }
void DatabaseMetadata::setDatabaseName(const std::string& name) { databaseName = name; }

const std::chrono::system_clock::time_point& DatabaseMetadata::getCreationTimestamp() const { return creationTimestamp; }
void DatabaseMetadata::setCreationTimestamp(const std::chrono::system_clock::time_point& timestamp) { creationTimestamp = timestamp; }

const std::chrono::system_clock::time_point& DatabaseMetadata::getModificationTimestamp() const { return modificationTimestamp; }
void DatabaseMetadata::setModificationTimestamp(const std::chrono::system_clock::time_point& timestamp) { modificationTimestamp = timestamp; }

size_t DatabaseMetadata::getNumberOfVectors() const { return numberOfVectors; }
void DatabaseMetadata::setNumberOfVectors(size_t count) { numberOfVectors = count; }

const std::unordered_map<std::string, std::string>& DatabaseMetadata::getIndexInformation() const { return indexInformation; }
void DatabaseMetadata::addIndexInformation(const std::string& indexName, const std::string& status) { indexInformation[indexName] = status; }

size_t DatabaseMetadata::getStorageSize() const { return storageSize; }
void DatabaseMetadata::setStorageSize(size_t size) { storageSize = size; }

size_t DatabaseMetadata::getNumberOfUsers() const { return numberOfUsers; }
void DatabaseMetadata::setNumberOfUsers(size_t count) { numberOfUsers = count; }

const std::unordered_map<std::string, std::string>& DatabaseMetadata::getAccessPermissions() const { return accessPermissions; }
void DatabaseMetadata::addAccessPermission(const std::string& user, const std::string& permission) { accessPermissions[user] = permission; }

const std::unordered_map<std::string, std::string>& DatabaseMetadata::getDataSources() const { return dataSources; }
void DatabaseMetadata::addDataSource(const std::string& sourceName, const std::string& details) { dataSources[sourceName] = details; }

const std::string& DatabaseMetadata::getSchemaVersion() const { return schemaVersion; }
void DatabaseMetadata::setSchemaVersion(const std::string& version) { schemaVersion = version; }

const std::unordered_map<std::string, std::chrono::system_clock::time_point>& DatabaseMetadata::getBackupInformation() const { return backupInformation; }
void DatabaseMetadata::addBackupInformation(const std::string& location, const std::chrono::system_clock::time_point& timestamp) { backupInformation[location] = timestamp; }

const std::unordered_map<std::string, double>& DatabaseMetadata::getPerformanceMetrics() const { return performanceMetrics; }
void DatabaseMetadata::addPerformanceMetric(const std::string& metricName, double value) { performanceMetrics[metricName] = value; }

const std::unordered_map<std::string, std::string>& DatabaseMetadata::getConfigurationParameters() const { return configurationParameters; }
void DatabaseMetadata::addConfigurationParameter(const std::string& parameterName, const std::string& value) { configurationParameters[parameterName] = value; }
