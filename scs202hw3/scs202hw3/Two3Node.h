//
//  Two3Node.h
//  scs202hw3
//
//  Created by Zeynep Büsra Ziyagil on 19.07.2021.
//

#ifndef Two3Node_h
#define Two3Node_h
#include <string>
using namespace std;

class Two3Node {
    public:
    Two3Node();
    string firstitem, seconditem; 
    Two3Node *first, *second, *third;
    Two3Node *parent;
    bool leaf;
    bool full;
    friend class Dictionary23Tree;

};


#endif /* Two3Node_h */
