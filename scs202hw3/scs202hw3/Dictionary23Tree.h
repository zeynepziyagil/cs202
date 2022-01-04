//
//  Dictionary23Tree.h
//  scs202hw3
//
//  Created by Zeynep Büsra Ziyagil on 19.07.2021.
//

#ifndef Dictionary23Tree_h
#define Dictionary23Tree_h
#include <string>
#include "DictionarySearchTree.h"
#include "Two3Node.h"
#include <sstream>
#include <fstream>
using namespace std;
class Dictionary23Tree: public DictionarySearchTree {
    
public:
    Dictionary23Tree( string dictionaryFile): DictionarySearchTree( dictionaryFile){
   
        this->size =0;
        this->root =NULL;
        ifstream infile;
        infile.open(dictionaryFile.c_str());

        
        string theline;
       
        if (infile.is_open()) {
            while (getline(infile, theline)) {
            string str =theline.c_str();
                insert(str);
            }
            
            infile.close();
         
        }
        
    }
    ~Dictionary23Tree(){}
    void insert(string word);
    void split(Two3Node *n, string key, Two3Node *first, Two3Node *second, Two3Node *third, Two3Node *fourth);
  
    //Searches the given word in the dictionary, and returns the number
    //of comparisons made and whether the word is found or not
     void search( string word, int& numComparisons, bool& found ) const;
    //Searches all words in the query file in the dictionary, and
    //summarizes the results in the output file
     void search( string queryFile, string outputFile ) const;
    int size;
    Two3Node *root;
    void searchHelper(Two3Node* curr, const string & word, bool & val,int &count) const;
};
#endif /* Dictionary23Tree_h */
