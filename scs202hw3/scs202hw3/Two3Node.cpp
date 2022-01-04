//
//  Two3Node.cpp
//  scs202hw3
//
//  Created by Zeynep Büsra Ziyagil on 19.07.2021.
//

#include <stdio.h>
#include "Two3Node.h"
Two3Node::Two3Node(void) {
   
    this->firstitem ="";
    this->seconditem ="";
    this->leaf = true;
    this->full = false;
    this->first=NULL;
    this->second=NULL;
    this->third=NULL;
}
