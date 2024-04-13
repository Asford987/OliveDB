# OliveDB

Vector Database implemented in C++ for learning purposes

general workflow for query:

1. global and local indexes candidates are guessed by indexer
2. all vectors from these indexes are loaded
3. similarity is performed. The closest N are chosen

