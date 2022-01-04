//
//  HashTable.h
//  scs202hw4
//
//  Created by Zeynep Büsra Ziyagil on 3.08.2021.
//

#ifndef HashTable_h
#define HashTable_h

#include <string>
using namespace std;
class HashTable {
  private:
    struct Node {
      string key;
      int value;
      Node* next;
    };
    int SIZE = 50;
    Node *hashlist[50];
    int hash(const string &key);
    
  public:
    HashTable();
    ~HashTable();
    void insert(string key, int value);
    int retrieve(string key);
    string getFromValue(int index);
    
   
};




#endif /* HashTable_h */
