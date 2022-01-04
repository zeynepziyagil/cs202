//
//  BinaryNode.cpp
//  scs202hw3
//
//  Created by Zeynep Büsra Ziyagil on 19.07.2021.
//


#include <stdio.h>
#include "BinaryNode.h"
BinaryNode::BinaryNode() { }
BinaryNode::BinaryNode(const string& nodeItem,BinaryNode* left, BinaryNode* right): item(nodeItem), leftChildPtr(left), rightChildPtr(right){}
