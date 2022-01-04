//
//  DictionaryBST.h
//  scs202hw3
//
//  Created by Zeynep Büsra Ziyagil on 19.07.2021.
//

#ifndef DictionaryBST_h
#define DictionaryBST_h
#include <string>
#include "DictionarySearchTree.h"
#include "BinaryNode.h"

#include <sstream>
#include <fstream>
using namespace std;
class DictionaryBST: public DictionarySearchTree{
    
public:
    DictionaryBST( string dictionaryFile): DictionarySearchTree( dictionaryFile){
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
    void insert( string word );
    //Searches the given word in the dictionary, and returns the number
    //of comparisons made and whether the word is found or not
    void insx(const string &theItem, BinaryNode*&rootNode);
    void search( string word, int& numComparisons, bool&   found ) const;
    //Searches all words in the query file in the dictionary, and
    //summarizes the results in the output file
    void search( string queryFile, string outputFile )  const;
    
    BinaryNode* root; 
    void  containsxnode(BinaryNode *rootNode,string word, bool &boolr,int &compcount)const;
    
    
    
};


#endif /* DictionaryBST_h */
