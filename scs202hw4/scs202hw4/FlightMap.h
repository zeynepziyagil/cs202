//
//  FlightMap.h
//  scs202hw4
//
//  Created by Zeynep Büsra Ziyagil on 3.08.2021.
//

#ifndef FlightMap_h
#define FlightMap_h
#include "HashTable.h"
class FlightMap {
public:
FlightMap(const string vertexFile, const string edgeFile);
~FlightMap();
void findDirectFrom(const string source);
void findDirectTo(const string destination);

void findPath(const string source, const string destination);
void findPath(const string source, const string destination, const int stops);
void findShortestPath(const string source, const string destination);

private:
    struct Node {
      string key;
      int value;
      Node* next;
    };
    int SIZE = 50;
  
    HashTable table;
    Node* adjList[11];
    int n = 5757;
    bool * visited;
    bool* visitedx;
// define your data members here
// define private member functions here, if any
// you MUST use the adjacency list representation
};

#endif /* FlightMap_h */
