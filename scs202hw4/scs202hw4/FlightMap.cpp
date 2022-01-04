//
//  FlightMap.cpp
//  scs202hw4
//
//  Created by Zeynep Büsra Ziyagil on 3.08.2021.
//

#include <stdio.h>
#include "FlightMap.h"
#include "HashTable.h"
#include <iostream>
#include <cstring>
#include <fstream>
/* The constructor loads the flight
map from the given text files containing the vertices and the edges. The first input is a text file
named vertexFile that contains each city in a separate line. The second input is a separate
file named edgeFile that contains the edge information that represents the flights. Each line
includes an edge with the cities separated by a comma. The first city is the source city and the
second one after the comma is the destination city.
The constructor must load the map data from these files and construct an adjacency list
representation for the graph. You MUST use the adjacency list representation in this assignment.
(Otherwise, you will get no points from this question). Note again that the edges are directed
edges with no weights.
You MUST also design a hash table to implement the mapping from the cities to unique integer
indices. These integer indices (in the range from 0 to N-1) where N is the number of cities are
used to refer to the vertices (i) and edges (i,j) internally in the code whereas the input and
output use the actual city names. The hash table takes a city name (string) as input and
gives its index (integer) as the output. The goal of the hash table is to perform this lookup
efficiently. You MUST use the hash function (Hash Function 3) given on slide 40 of the lecture
notes on hashing. You are free to choose the table size as you wish. The hash table MUST
use open addressing with quadratic probing to store the data. The integer indices will
correspond to the line numbers for the cities given in the vertex file. You must use this hash
table with the city names given as the keys and the line numbers as the item data that will be
used as the vertex indices.*/
FlightMap::FlightMap(const string vertexFile, const string edgeFile){ 
    
    
    string line;
       ifstream myfile;
       myfile.open(vertexFile);

      if(!myfile.is_open()) {
         perror("Error open");
         exit(EXIT_FAILURE);
      }
        int indexofit =0;
       while(getline(myfile, line)) {
       
           table.insert(line, indexofit);
           indexofit++;
          
       }
    myfile.close();
    

  
    string aline;
       ifstream amyfile;
       amyfile.open(edgeFile);

      if(!amyfile.is_open()) {
         perror("Error open");
         exit(EXIT_FAILURE);
      }
        int aindexofit =0;
   
       while(getline(amyfile, aline)) {
           string word1 = aline.substr(0,5);
           string word2 = aline.substr(6,5);
           int index1 = table.retrieve(word1);
           adjList[index1]->next = new Node;
           
           aindexofit++;
       }
  
    amyfile.close();
    visited = new bool[5757];
    for(int i = 0;i < 5757;i++){
        visited[i] = false;
        
    }
    visitedx = new bool[5757];
    for(int i = 0;i < 5757;i++){
        visitedx[i] = false;
        
    }
    
    
    
}
