//
//  BinaryNode.h
//  scs202hw3
//
//  Created by Zeynep Büsra Ziyagil on 19.07.2021.
//

#ifndef BinaryNode_h
#define BinaryNode_h
#include <stdio.h>
#include <string>
using namespace std;

class BinaryNode {     // a node in the tree

public:
    BinaryNode();
    BinaryNode(const string& nodeItem,BinaryNode *left = NULL,
               BinaryNode *right = NULL);
    string item;           // a data item in the tree
    BinaryNode *leftChildPtr;    // pointers to children
    BinaryNode *rightChildPtr;
    int height =0; 
    friend class DictionaryBST;
   friend class DictionaryAVLTree;


};

#endif /* BinaryNode_h */
